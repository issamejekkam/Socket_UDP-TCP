#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/timeb.h>
#include <time.h>
#include <netdb.h>  // Needed for gethostbyname()

#define PORT 8080
#define BUFFER_SIZE 128

int main(int argc, char *argv[]) {
    int client_fd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    struct timeb t;
    time_t raw_time;
    struct hostent *host;

    // Check for hostname argument
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Resolve hostname to IP address
    host = gethostbyname(argv[1]);
    if (host == NULL) {
        herror("gethostbyname failed");
        exit(EXIT_FAILURE);
    }

    // Create UDP socket
    client_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (client_fd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    printf("✅ UDP Client socket created successfully...\n");

    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    //  Get current time
    ftime(&t);
    raw_time = t.time;
    snprintf(buffer, BUFFER_SIZE, "%s", ctime(&raw_time));

    //  Send time to server
    sendto(client_fd, buffer, strlen(buffer), 0, (struct sockaddr*)&server_addr, sizeof(server_addr));
    printf("📤 Sent time to server (%s): %s", argv[1], buffer);

    //  Close socket and exit
    close(client_fd);
    printf("🔌 Client shutting down.\n");
    return 0;
}
