+--------------------------------------------------------------------------------+
| Name: Benjamin Tate															 |
| Date: 11/27/2016																 |
| Class: CS 372																	 |
| Assignment: Project 2															 |
| Description: README file for ftclient.py and ftserver.c						 |
| Testing: This project was tested on access.engr.orst.edu with both running	 |
|	on flip2, as well as with one running on flip1 and one on flip2				 |
+--------------------------------------------------------------------------------+

COMPILING & RUNNING:
1)	To compile ftserver, use the command gcc -o ftserver ftserver.c
2)	Next, run ftserver using the the following command:
		./ftserver <port>
	where <port> represents the port you would like to use for the control connection
3)	In a separate window, compile and run ftclient with the following command:
		python ftclient.py <host> <port p> <-l/-g> [filename] <port q>
	In the above command:
		<host> represents the name of the machine ftserver is running on
		<port p> represents the port specified in step (2) above
		-l is to be used to list the contents of the directory that ftserver is
			running in
		-g is to be used to request a file transfer
		[filename] represents the full name of the file you would like to transfer
			into the directory ftclient is running in
		<port q> represents the port you would like to use for the data connection
	Notes:
		**Use only one of the two options (-l or -g)
		**Specify a filename only if you are using the -g option, in which case
			it is required
4)	ftclient will close its connection after the completion of each command, while
	ftserver will remain running on the specified port until a SIGINT (^C) is received

WEBSITES REFERENCED:
 -	http://codereview.stackexchange.com/questions/43914/client-server-implementation-in-c-sending-data-files
 -	https://docs.python.org/3/howto/sockets.html
 -	https://www.tutorialspoint.com/c_standard_library/c_function_signal.htm
 -	http://stackoverflow.com/questions/2174889/whats-the-differences-between-r-and-rb-in-fopen
 -	http://www.bogotobogo.com/python/python_network_programming_server_client_file_transfer.php

 ***Code found on above references was used for inspiration and clarification 
	only, and was heavily adapted to fit the needs of the this project

EXTRA CREDIT:
 -	This program should be able to transfer non-text files within the size limits
	(tested with .c and .py files)
