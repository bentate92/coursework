##################################################################################
# Name: Benjamin Tate
# Date: 11/24/2016
# Class: CS 344
# Assignment: Program 5
# Description: A simple python program that will create 3 new text files, write 10
#	random lowercase letters and a newline to each, print the random strings of 
#	each, and finally print 2 random integers [1, 42] and compute and print their
#	product.
# Note: Please run program with 'python mypython.py'
##################################################################################

import sys
import random
import string

#Seed psuedo-random generator
random.seed()

#Initialize 3 strings to hold be written to the 3 files
f1string = ''
f2string = ''
f3string = ''

#Get string containing list of all letters and remove uppercase letters
letters = string.letters
letters = letters[:-26]

#Making first file:
for i in range(0, 10):
	#Add 10 random characters from lowercase letter string to f1string
	letter = random.choice(letters)
	f1string += letter

#Add newline
f1string += '\n'

#Open a file for writing and write string to it
f1 = open('foo.txt', 'w')
f1.write(f1string)

#Making second file:
for j in range(0, 10):
	#Add 10 random characters from lowercase letter string to f2string
	letter = random.choice(letters)
	f2string += letter

#Add newline
f2string += '\n'

#Open a file for writing and write string to it
f2 = open('bar.txt', 'w')
f2.write(f2string)

#Making third file:
for k in range(0, 10):
	#Add 10 random characters from lowercase letter string to f3string
	letter = random.choice(letters)
	f3string += letter

#Add newline
f3string += '\n'

#Open a file for writing and write string to it
f3 = open('baz.txt', 'w')
f3.write(f3string)

#Print contents of f1
print '\nContents of foo.txt:'
print f1string

#Print contents of f2
print 'Contents of bar.txt:'
print f2string

#Print contents of f3
print 'Contents of baz.txt:'
print f3string

#Create 2 random integers from 1 to 42
i1 = random.randint(1, 42)
i2 = random.randint(1, 42)

#Print integers and their product
print 'First integer = {0}'.format(i1)
print 'Second integer = {0}'.format(i2)
print 'Product = {0}'.format(i1 * i2)
