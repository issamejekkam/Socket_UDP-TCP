#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>


#define PORT 8080
#define BUFFER_SIZE 1024

int main(int argc,char* argv[]){
    int server_fd, new_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    server_fd = socket(AF_INET, SOCK_DGRAM, 0);
    char buffer[BUFFER_SIZE];
    if (server_fd == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    printf("Socket created successfully...\n");


    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY; 
    server_addr.sin_port = htons(PORT);

    if(bind(server_fd,(struct sockaddr*)&server_addr,sizeof(server_addr))<0){
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }
    printf("✅ Binding successful on port %d.\n", PORT);

    memset(buffer, 0, BUFFER_SIZE);
    recvfrom(server_fd, buffer, BUFFER_SIZE, 0, (struct sockaddr*)&client_addr, &addr_len);

    // 4️⃣ Display received time
    printf("📩 Received time from client: %s", buffer);

    // 5️⃣ Close socket and exit
    close(server_fd);
    printf("🔌 Server shutting down.\n");
    return 0;

}