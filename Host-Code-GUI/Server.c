/*
* Brief - A simple program that acts a socket server. Used to test the client. 
*
* Author - Deekshith Reddy Patil, patil.deekshithreddy@colorado.edu
*/
#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 
#include <unistd.h> 
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    off_t len;

    if(argc < 2)
    {
        printf("\nPort No not provided. Program termintaed!\n");
        exit(1);
    }

    int sockfd, newsockfd, portno, n;

    char buffer[255];

    struct sockaddr_in serv_addr, cli_addr;

    socklen_t clilen;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
    {
        error("Error opening Socket.");
    }

    bzero((char *)&serv_addr, sizeof(serv_addr)); //Clear serv_addr and set it to 0
    portno = atoi(argv[1]);

    //Set the server characteristics
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno); // htons is host to network short

    if(bind(sockfd,(struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        error("Binding failed");
    }



    clilen = sizeof(cli_addr);


    if(newsockfd < 0)
    {
        error("Error on Accept");
    }

    while(1)
    {
        //start listening on the created socket
        listen(sockfd, 5);

        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);

        printf("Client connected!\n");
        
        bzero(buffer,255);

        n = read(newsockfd, buffer, 255); //Read from socket into buffer

        if(n < 0)
        {
            error("Error on reading!\n");
        }

        printf("Client: %s\n",buffer);

        close(newsockfd);

    }

    close(newsockfd);
    close(sockfd);

    return 0;
    
}