// socker client demo
#include<arpa/inet.h>
#include<netinet/in.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<unistd.h>
#include<sys/types.h>

#define PORT 3000
#define MSG "hello from client"
#define MAXLINE 1024

int main(){
    int socket_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len;
    ssize_t bytes_send, bytes_recv;
    char buffer[MAXLINE];

    // create socket
    socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (socket_fd == -1){
        perror("socket");
        exit(EXIT_FAILURE);
    }

    memset(&buffer, '\0', sizeof(buffer));
    memset(&server_addr, '\0', sizeof(server_addr));

    // set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) == -1){
        perror("inet_pton");
        exit(EXIT_FAILURE);
    }

    bytes_send = sendto(socket_fd, (const char *)MSG, strlen(MSG), MSG_CONFIRM, (const struct sockaddr *)&server_addr, sizeof(server_addr));
    if (bytes_send == -1){
        perror("sendto");
        exit(EXIT_FAILURE);
    }
    printf("Message sent to server\n");

    bytes_recv = recvfrom(socket_fd, (char *)buffer, MAXLINE, MSG_WAITALL, (struct sockaddr *)&server_addr, &addr_len);
    if (bytes_recv == -1){
        perror("recvfrom");
        exit(EXIT_FAILURE);
    }
    buffer[bytes_recv] = '\0';
    printf("Server: %s\n", buffer);

    close(socket_fd);
    return 0;

}


