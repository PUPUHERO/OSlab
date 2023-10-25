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
    socklen_t addr_len=sizeof(client_addr);
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

    while (1)
    {
        char message[1024];
        printf("Enter message: ");
        fgets(message, 1024, stdin);
        bytes_send = sendto(socket_fd, (const char *)message, strlen(message), MSG_CONFIRM, (const struct sockaddr *)&server_addr, sizeof(server_addr));
        if (bytes_send == -1){
            perror("sendto");
            exit(EXIT_FAILURE);
        }
        if (strcmp(message, "exit\n") == 0)
        {
            printf("Client exit\n");
            break;
        }
        printf("Message sent, total bytes sent: %ld\n", bytes_send);
        printf("Message sent to server\n");
    }

    close(socket_fd);
    return 0;

}


