# Compiler
CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# Source files
TCP_SERVER = TcpServer.c
TCP_CLIENT = TcpClient.c
UDP_SERVER = UdpServer.c
UDP_CLIENT = UdpClient.c

# Output binaries
TCP_SERVER_BIN = tcp_server
TCP_CLIENT_BIN = tcp_client
UDP_SERVER_BIN = udp_server
UDP_CLIENT_BIN = udp_client

# Build rules
all: $(TCP_SERVER_BIN) $(TCP_CLIENT_BIN) $(UDP_SERVER_BIN) $(UDP_CLIENT_BIN)

$(TCP_SERVER_BIN): $(TCP_SERVER)
	$(CC) $(CFLAGS) $^ -o $@

$(TCP_CLIENT_BIN): $(TCP_CLIENT)
	$(CC) $(CFLAGS) $^ -o $@

$(UDP_SERVER_BIN): $(UDP_SERVER)
	$(CC) $(CFLAGS) $^ -o $@

$(UDP_CLIENT_BIN): $(UDP_CLIENT)
	$(CC) $(CFLAGS) $^ -o $@

# Clean up compiled files
clean:
	rm -f $(TCP_SERVER_BIN) $(TCP_CLIENT_BIN) $(UDP_SERVER_BIN) $(UDP_CLIENT_BIN)

# Run servers and clients
run_tcp_server:
	./$(TCP_SERVER_BIN)

run_tcp_client:
	./$(TCP_CLIENT_BIN) localhost

run_udp_server:
	./$(UDP_SERVER_BIN)

run_udp_client:
	./$(UDP_CLIENT_BIN) localhost
