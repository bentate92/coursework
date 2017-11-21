/**********************************************************************************
 * Name: Benjamin Tate
 * Date: 11/27/2016
 * Class: CS 372
 * Assignment: Project 2
 * Description: Server-side implementation of a simple file transfer application
 **********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>

//Define maximum message length constants
#define BUFF 2048
#define MAXBUFF 8192

/*
 * Function prototypes
 */
void sighandler();
int makeSock(int);
unsigned sendLength(int, unsigned);
unsigned getLength(int);
int sendMsg(int, char*);
int getMsg(int, char*, unsigned);
int handleReq(int, char*);
int sendResp(char*, char*, int);

/*
 * Main program body
 */
int main(int argc, char* argv[]) {
	//Begin signal handler
	signal(SIGCHLD, sighandler); 

	//Declare strings for messages
	char buffer[BUFF];
	char message[BUFF];
	char outgoing[BUFF];
	//Declare int to hold message size
	int size;
	//Declare int to hold port of data connection
	int dataport;
	//Declare int to hold status of messages
	int r;

	//Check for appropriate number of arguments
	if(argc != 2) {
		fprintf(stderr, "\nUsage: $ ftserver <PORT>\n\n");
		exit(0);
	}

	//Convert port argument to int and check validity
	int port = atoi(argv[1]);
	if(port < 1024 || port > 65535) {
		fprintf(stderr, "\nERROR: Invalid port number. Please enter a number from 1024 - 65535.\n");
		exit(1);
	}

	//Initialize file descriptor for control socket and check success
	int connP_desc = makeSock(port);
	if(connP_desc < 0) {
		fprintf(stderr, "\nERROR: Failed to listen on port %d.\n", port);
		exit(1);
	}
	printf("Now listening on port %d.\n", port);

	//Declare int for process id of children
	int pid;
	//Declare int for status of children
	int status;

	//Continue until SIGINT received
	while(1) {
		//Accept control connection
		int connP = accept(connP_desc, NULL, NULL);

		//Check success of connP
		if(connP < 0) {
			//Connection P failed; throw error
			fprintf(stderr, "\nERROR: Could not connect.\n");
			close(connP);
		} else {
			//Connection P succeeded

			//Fork off new process and check success
			pid = fork();
			if(pid < 0) {
				printf("\nERROR: Could not fork process.\n");
				exit(1);
			} else if(pid == 0) {
				printf("Connection to client successful.\n");

				//Call handleReq() to find the request number
				int reqNum = handleReq(connP, message);
				printf("Req# = %d\n", reqNum);

				//Call getLength to get connP data port number
				dataport = getLength(connP);

				//Check connection status
				if(r == 0) {
					//Message received

					//Create file descriptor data socket
					int connQ_desc = makeSock(dataport);
					printf("Initiating data connection to client on port %d.\n", dataport);

					//Accept data connection
					int connQ = accept(connQ_desc, NULL, NULL);

					if(reqNum == 1) {
						//Option was '-g'

						//Declare string to hold directory contents to be printed
						char dir[BUFF];

						//Get path of current directory
						getcwd(buffer, BUFF);

						//Initialize pointer to directory contents
						DIR* pDir = NULL;
						pDir = opendir(buffer);

						//Initialize dirent struct pointer
						struct dirent* stDir = NULL;

						//Add header to dir
						strncat(dir, "Directory contents:\n", 20);

						//Continue to end of directory
						while((stDir = readdir(pDir)) != NULL) {
							//Ignore '.' and '..'
							if((strncmp(stDir->d_name, ".", strlen(stDir->d_name)) != 0) && (strncmp(stDir->d_name, "..", strlen(stDir->d_name)) != 0)) {
								//Add file to dir
								strncat(dir, "  ", 2);
								strncat(dir, stDir->d_name, strlen(stDir->d_name));
								strncat(dir, "\n", 1);
							}
						}

						//Send response over control connection
						sendResp(outgoing, "DATA", connP);
						//Send directory contents string
						sendResp(outgoing, dir, connQ);

						//Make sure connP is closed
						close(connP);
						_exit(0);
					} else if (reqNum == 2) {
						//Option was '-l'

						//Get message length
						size = getLength(connP);
						//Receive filename in message
						r = getMsg(connP, message, size);
						//Add terminating NULL char
						message[size] = '\0';
						printf("Client is requesting the file \"%s\".\n", message);

						//Get path of current directory
						getcwd(buffer, BUFF);

						//Initialize pointer to directory contents
						DIR* pDir = NULL;
						pDir = opendir(buffer);

						//Initialize dirent struct pointer
						struct dirent* stDir = NULL;

						//Initialize bool to check if file exists
						int valid = 0;
						//Continue to end of directory
						while((stDir = readdir(pDir)) != NULL) {
							//Declare int to hold the length of the longer string for comparing
							int longer;
							//Compare lengths of the filename from stDir and from message
							//  and set longer accordingly
							if(strlen(stDir->d_name) >= strlen(message)) {
								longer = strlen(stDir->d_name);
							} else {
								longer = strlen(message);
							}
							//If the strings match, the filename is valid
							if(strncmp(message, stDir->d_name, longer) == 0) {
								valid = 1;
							}
						}

						if(valid == 1) {
							//Filename is valid
							printf("\"%s\" is a valid file.\n", message);
							char fBuff[MAXBUFF];

							//Declare file pointer and open the requested file
							FILE* pFile;
							pFile = fopen(message, "rb");
							//Find size of file
							fseek(pFile, 0, SEEK_END);
							long fileSize = ftell(pFile);
							fseek(pFile, 0, SEEK_SET);

							//Read file into buffer and add NULL terminator
							char* buffer = malloc(fileSize + 1);
							fread(buffer, fileSize, 1, pFile);
							buffer[fileSize] = '\0';

							//Close file
							fclose(pFile);

							//Copy buffer into fBuff
							strncpy(fBuff, buffer, MAXBUFF);

							//Send response over connP
							sendResp(outgoing, "DATA", connP);

							//Send length of message over data connection
							sendLength(connQ, (strlen(fBuff)));
							//Send message over data connection
							sendMsg(connQ, fBuff);
							printf("File sent successfully. Closing data connection.\n");
							
							//Close data connection
							close(connQ);
							printf("Completed file transfer.\n");

							//Close Control connection
							close(connP);
							_exit(0);
						} else {
							//Filename is invalid
							printf("\"%s\" is an not a valid file.\n", message);
							sendResp(outgoing, "\nERROR: Could not find the requested file.\n", connP);
							close(connP);
							_exit(0);
						}
					} else {
						//Option was not '-l' or '-g'
						//**This should not occur, as options are checked in ftclient.py
						sendResp(outgoing, "\nERROR: Invalid command.\n", connP);
						close(connP);
						_exit(0);
					}
				} else {
					//Message not received
					fprintf(stderr, "\nERROR: Failed to receive message.\n");
					close(connP);
					_exit(1);
				}
			}
		}
	}

	return 0;
}

/*
 * Function to watch for SIGINTs
 */ 
void sighandler() {
	pid_t pid;
	int status;
	pid = waitpid(-1, &status, WNOHANG);
}

/*
 * Function to create a socket at a given port
 */
int makeSock(int port) {
	int connP_desc;

	if((connP_desc = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		return -1;
	}

	struct sockaddr_in s;
	s.sin_family = AF_INET;
	s.sin_port = htons(port);
	s.sin_addr.s_addr = INADDR_ANY;

	int optval = 1;
	setsockopt(connP_desc, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof optval);

	if(bind(connP_desc, (struct sockaddr*) &s, sizeof(s)) < 0) {
		return -1;
	}

	if(listen(connP_desc, 10) < 0) {
		return -1;
	}

	return connP_desc;
} 

/*
 * Function to tell the client how big of a message to expect
 */
unsigned sendLength(int connP_desc, unsigned num) {
	int r = write(connP_desc, &num, sizeof(unsigned));
	if(r < 0) {
		return -1;
	} else {
		return 0;
	}
}

/*
 * Function to receive expected message length from client
 */
unsigned getLength(int connP_desc) {
	unsigned num;
	int r = read(connP_desc, &num, sizeof(unsigned));
	if(r < 0) {
		return -1;
	} else {
		return num;
	}
}

/*
 * Function to send messages to the client
 */
int sendMsg(int connP_desc, char* msg) {
	unsigned r;
	unsigned size = strlen(msg)+1;
	unsigned total = 0;

	while(total < size) {
		r = write(connP_desc, msg+total, size-total);

		total += r;

		if(r < 0) {
			return -1;
		} else if(r == 0) {
			total = size - total;
		}
	}

	return 0;
}

/*
 * Function to receive messages from client
 */
int getMsg(int connP_desc, char* output, unsigned size) {
	char buffer[BUFF];
	unsigned r;
	unsigned total = 0;

	while(total < size) {
		r = read(connP_desc, buffer+total, size-total);
		total += r;

		if(r < 0) {
			return -1;
		} else if(r == 0) {
			total = size - total;
		}
	}

	strncpy(output, buffer, size);

	return 0;
}

/*
 * Function to handle incoming requests from client
 */
int handleReq(int connP, char* buffer) {
	int size = getLength(connP);
	int r = getMsg(connP, buffer, size);
	buffer[size] = '\0';

	if(strncmp("-g", buffer, strlen(buffer)) == 0) {
		return 2;
	} else if(strncmp("-l", buffer, strlen(buffer)) == 0) {
		return 1;
	} else {
		return -1;
	}
}

/*
 * Function to respond to client requests
 */
int sendResp(char* outgoing, char* message, int connP) {
	strncpy(outgoing, message, BUFF);
	int r = sendLength(connP, (strlen(outgoing)));
	r = sendMsg(connP, outgoing);
}
