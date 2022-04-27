/*
* Brief - GUI based application that gets control information from the user and transmits it to the server (RPi)
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
#include <netdb.h>
#include "user_interface.h"

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{

    int temp;
    char transmit_buffer[1024];

    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server; //Used to store information about a given host

    if(argc < 3)
    {
        printf("usage %s hostname port\n", argv[0]);
        exit(1);
    }
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET,SOCK_STREAM,0);

    if(sockfd < 0)
        error("ERROR opening socket!");

    server = gethostbyname(argv[1]); //Get the hostname of the server from its ip address
    if(server == NULL)
        error("Error, no such host for server");

    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr_list[0], (char *)&serv_addr.sin_addr.s_addr,server->h_length);
    serv_addr.sin_port = htons(portno);

    connect(sockfd, (struct sockaddr *)&serv_addr,sizeof(serv_addr));

    argc = 1;

    while(1)
    {
        /* Recieve information from the user and transmit it over the network */
        get_user_data(transmit_buffer,argc, argv);

        n = write(sockfd,transmit_buffer,strlen(transmit_buffer));

        if(n < 0)
            error("Error on writing!\n");

        printf("Press Enter to continue again\n");
        getchar();

    }

    close(sockfd);

    return 0;

}
