#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080  // Port number for the server
#define BUFFER_SIZE 1024  // Size of the buffer for receiving messages

int main() {
    int server_fd, new_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    char buffer[BUFFER_SIZE];

    // Create a socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    printf("Socket created successfully...\n");

    // Configure server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY; 
    server_addr.sin_port = htons(PORT);

    // Bind the socket to the specified port
    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }
    printf("✅ Binding successful on port %d.\n", PORT);

    // Listen for incoming connections
    if (listen(server_fd, 5) < 0) {  // Max 5 clients in queue
        perror("Listening failed");
        exit(EXIT_FAILURE);
    }
    printf("🔊 Server listening for connections...\n");

    // Accept an incoming connection
    new_socket = accept(server_fd, (struct sockaddr*)&client_addr, &addr_len);
    if (new_socket < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }
    printf("✅ Connection accepted from %s:%d\n",
           inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    // Communication loop
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);  // Clear the buffer
        int bytes_received = recv(new_socket, buffer, BUFFER_SIZE, 0);  // Receive message from client
        if (bytes_received <= 0) {
            printf("❌ Client disconnected.\n");
            break;
        }
        printf("📩 Received: %s\n", buffer);

        // Echo the message back to the client
        send(new_socket, buffer, strlen(buffer), 0);
    }

    // Close the sockets
    close(new_socket);
    close(server_fd);
    printf("Server closed.\n");

    return 0;
}