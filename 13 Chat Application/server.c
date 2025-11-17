#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")

#define PORT 8080
#define MAX_CLIENTS 10

int main() {
    WSADATA wsa;
    SOCKET server_fd, new_socket, clients[MAX_CLIENTS];
    struct sockaddr_in address;

    printf("Starting Windows Server...\n");

    WSAStartup(MAKEWORD(2, 2), &wsa);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == INVALID_SOCKET) {
        printf("Socket creation failed!\n");
        return 1;
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 3);

    printf("📡 Server running on port %d...\n", PORT);

    for (int i = 0; i < MAX_CLIENTS; i++)
        clients[i] = 0;

    while (1) {
        fd_set readfds;
        FD_ZERO(&readfds);

        FD_SET(server_fd, &readfds);
        SOCKET max_sd = server_fd;

        for (int i = 0; i < MAX_CLIENTS; i++) {
            SOCKET sd = clients[i];
            if (sd > 0) FD_SET(sd, &readfds);
            if (sd > max_sd) max_sd = sd;
        }

        select(max_sd + 1, &readfds, NULL, NULL, NULL);

        if (FD_ISSET(server_fd, &readfds)) {
            int addrlen = sizeof(address);
            new_socket = accept(server_fd, (struct sockaddr *)&address, &addrlen);

            printf("New client connected!\n");

            for (int i = 0; i < MAX_CLIENTS; i++) {
                if (clients[i] == 0) {
                    clients[i] = new_socket;
                    break;
                }
            }
        }

        char buffer[1024];
        for (int i = 0; i < MAX_CLIENTS; i++) {
            SOCKET sd = clients[i];

            if (FD_ISSET(sd, &readfds)) {
                int val = recv(sd, buffer, sizeof(buffer), 0);

                if (val <= 0) {
                    printf("Client disconnected\n");
                    closesocket(sd);
                    clients[i] = 0;
                } else {
                    buffer[val] = '\0';

                    for (int j = 0; j < MAX_CLIENTS; j++)
                        if (clients[j] != 0 && j != i)
                            send(clients[j], buffer, strlen(buffer), 0);
                }
            }
        }
    }

    WSACleanup();
    return 0;
}