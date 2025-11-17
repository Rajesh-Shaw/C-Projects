#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")

#define PORT 8080

int main() {
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);

    SOCKET sock;
    struct sockaddr_in serv_addr;

    sock = socket(AF_INET, SOCK_STREAM, 0);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    printf("Enter username: ");
    char username[50];
    fgets(username, 50, stdin);
    username[strcspn(username, "\n")] = '\0';

    printf("Connected to Chat Server!\n");

    HANDLE thread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)recv, (LPVOID)sock, 0, NULL);

    char msg[1024];
    char finalmsg[1200];

    while (1) {
        fgets(msg, sizeof(msg), stdin);
        snprintf(finalmsg, sizeof(finalmsg), "%s: %s", username, msg);
        send(sock, finalmsg, strlen(finalmsg), 0);
    }

    closesocket(sock);
    WSACleanup();
    return 0;
}