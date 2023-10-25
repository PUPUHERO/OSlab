// Socket server demo
#include<arpa/inet.h>
#include<netinet/in.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<unistd.h>
#include<sys/types.h>

#define PORT 3000
#define MSG "hello from server"
#define MAXLINE 1024

int main (){
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
    memset(&client_addr, '\0', sizeof(client_addr));

    // set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // bind socket to address
    if (bind(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1){
        perror("bind");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        bytes_recv = recvfrom(socket_fd, (char *)buffer, MAXLINE, MSG_WAITALL, (struct sockaddr *)&client_addr, &addr_len);
        if (bytes_recv == -1){
            perror("recvfrom");
            exit(EXIT_FAILURE);
        }
        buffer[bytes_recv] = '\0';
        if (strcmp(buffer, "exit\n") == 0)
        {
            printf("Server exit\n");
            break;
        }        
        printf("Client(received %ld bytes): %s\n", bytes_recv, buffer);
    }

    close(socket_fd);
    return 0;

}