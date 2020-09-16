##################################################################################
# Name: Benjamin Tate
# Date: 11/27/2016
# Class: CS 372
# Assignment: Project 2
# Description: Client-side implementation of a simple file transfer application
##################################################################################

import socket
import sys
import os.path
from struct import *

###
## Function to create socket with server of given host name and port number
###
def makeSock(host, port):
	#Validate port number
	if int(port) < 1024 or int(port) > 65535:
		print "\nERROR: Invalid port number. Please enter a number from 1024 - 65535.\n"
		sys.exit(1)

	#Create socket
	s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

	#Connect to server
	try:
		s.connect((host, port))
	except:
		s = -1

	#Check if connection was successful
	if s < 0:
		print "\nERROR: Failed to connect to " + host + ":" + str(port) + "\n"
		sys.exit(1)

	return s

###
## Function to send request message to server
###
def sendReq(sock, port, outgoing):
	#Set size of message
	size = len(outgoing)

	#Send message size and then message itself
	try:
		data = pack('I', size)
		sock.send(data)
		sock.send(outgoing)
	except:
		#Throw error and close connections in case of failure
		print "\nERROR: Failed to send message.\n"
		q.close()
		p.close()
		sys.exit(1)

	#Send port number
	try:
		data = pack('I', port)
		sock.send(data)
	except:
		#Throw error and close connections in case of failure
		print "\nERROR: Failed to send port number.\n"
		q.close()
		p.close()
		sys.exit(1)

###
## Function to receive responses from server
###
def getMsg(sock):
	try:
		data = sock.recv(4)
		recvsize = unpack('I', data)
		incoming = sock.recv(recvsize[0])
		return incoming
	except:
		#Throw error and close connections in case of failure
		print "\nERROR: Failed to receive message.\n"
		q.close()
		p.close()
		sys.exit(1)

###
## Main program body
###

#Check for appropriate number of arguments
if len(sys.argv) < 5 or len(sys.argv) > 6:
	print "\nUsage:\n $ python ftclient.py <SERVER_HOST> <SERVER_PORT> <-l || -g [filename]> [DATA_PORT]\n"
	sys.exit(0)
else:
	#Argument count is reasonable

	#Create control socket
	p = makeSock(sys.argv[1], int(sys.argv[2]))

	#Set option from 3rd argument
	option = sys.argv[3]

	#Check option
	if option == "-g":
		#Send message over p containing option, using specified port
		sendReq(p, int(sys.argv[5]), option)

		#Create data socket
		q = makeSock(sys.argv[1], int(sys.argv[5]))

		#Check again for argument count, since filename is required
		if len(sys.argv) < 6:
			print "\nUsage:\n $ python ftclient.py <SERVER_HOST> <SERVER_PORT> <-l || -g [filename]> [DATA_PORT]\n"
			sys.exit(0)
		else:
			#Set filename from 4th argument
			filename = sys.argv[4]

		#Send filename
		sendReq(p, int(sys.argv[5]), filename)

		#Receive response string
		incoming = getMsg(p)

		#Check if server is sending file
		if incoming == "DATA":
			print "\nInitiating file transfer request."
			file = getMsg(q)
		
			#Initialize overwrite bool
			overwrite = True
		
			#Check if file exists already
			if os.path.isfile(filename):
				#Ask user if he/she would like to replace existing file
				choice = raw_input("A file with that name already exists. Would you like to overwrite it? (yes/no) ")
				if choice == 'yes':
					overwrite = True
				elif choice == 'no':
					overwrite = False
				else:
					while choice != 'yes' and choice != 'no':
						choice = raw_input("Please enter either 'yes' or 'no': ")
						if choice == 'yes':
							overwrite = True
						elif choice == 'no':
							overwrite = False
		
			if overwrite == False:
				#User does not want to replace file; print message and stop
				print "File transfer unsuccessful. Please choose a unique file name or select overwrite."
			else:
				#User wants to replace file, open file for writing and overwrite contents
				newFile = open(filename, 'w')
				newFile.write(file)
		
				print "Successfully completed file transfer."
		else:
			#File does not exist; print error and exit
			print "\nERROR: Unable to find requested file.\n"
			sys.exit(1);
	elif option == "-l":
		#Send request over control connection
		sendReq(p, int(sys.argv[4]), option)

		#Make data socket
		q = makeSock(sys.argv[1], int(sys.argv[4]))

		#Receive response
		incoming = getMsg(p)

		#If server is sending data, receive and print it
		if incoming == "DATA":
			incoming = getMsg(q)
			print '\n' + incoming
	else:
		#Invalid command
		print "\nUsage:\n $ python ftclient.py <SERVER_HOST> <SERVER_PORT> <-l || -g [filename]> [DATA_PORT]\n"
		sys.exit(0)

	#Close data connection
	q.close()

	print "Closing connection to server.\n"
	#Close control connection
	p.close()
