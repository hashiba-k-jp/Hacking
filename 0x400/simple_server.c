#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "hacking.h"

#include <fcntl.h> // for open
#include <unistd.h> // for close

#define PORT 7890

int main(void){
    int sockfd, new_sockfd;
    struct sockaddr_in host_addr, client_addr;
    socklen_t sin_size;
    int recv_length = 1, yes = 1;
    char buffer[1024];

    // create socket
    // PF_INET is for IPv4, SOCK_STREAM is one of socket types
    if((sockfd = socket(PF_INET, SOCK_STREAM, 0)) == -1){
        fatal("Failed to create a socket.");
    }

    // set sockets' options
    if(setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1){
        fatal("Set the socket SO_REUSEADDR.");
    }

    // settings for host_addr which is a STRUCT used for bind() function.
    host_addr.sin_family = AF_INET;         // the order of hosts
    host_addr.sin_port = htons(PORT);       // the order of short integer, network bytes
    host_addr.sin_addr.s_addr = 0;          // set IP for itself automatically.
    memset(&(host_addr.sin_zero), '\0', 8); // left of struct will be 0

    if(bind(sockfd, (struct sockaddr *)&host_addr, sizeof(struct sockaddr)) == -1){
        fatal("Failed to bind the socket.");
    }

    if(listen(sockfd, 5) == -1){
        fatal("Failed to wait the socket.");
    }

    // roop for accept arrivaled connections
    while(1){ // accept-roop
        sin_size = sizeof(struct sockaddr_in);
        new_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &sin_size);
        if(new_sockfd == -1){
            fatal("Failed to recept the connection.");
        }
        printf(
            "SERVER: Recepted the connection from port %d, %s.\n",
            ntohs(client_addr.sin_port),
            inet_ntoa(client_addr.sin_addr)
        );
        send(new_sockfd, "Hello, world!\n", 13, 0);
        recv_length = recv(new_sockfd, &buffer, 1024, 0);

        while(recv_length > 0){
            printf("RECEIVE: Received %d byte(s).\n", recv_length);
            dump(buffer, recv_length);
            recv_length = recv(new_sockfd, &buffer, 1024, 0);
        }
        close(new_sockfd);
    }
    return 0;
}