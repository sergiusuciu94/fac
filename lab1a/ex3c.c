#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>

int main() {
    int c;
    int ch;
    struct sockaddr_in server;
    char a[255];

    c = socket(AF_INET, SOCK_STREAM, 0);
    if (c < 0) {
        printf("Eroare la crearea socketului client\n");
        return 1;
    }

    memset(&server, 0, sizeof(server));
    server.sin_port = htons(1234);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;

    if (connect(c, (struct sockaddr *) &server, sizeof(server)) < 0) {
        printf("Eroare la conectarea la server\n");
        return 1;
    }

    printf("Sirul = ");
    fgets(a, 100, stdin);
    int len = strlen(a);
    len = htons(len);
    send(c, &len, sizeof(len), 0);
    for (int i = 0; i < strlen(a) - 1; i++) {
        int ch = a[i];
        ch = htons(ch);
        send(c, &ch, sizeof(int), 0);
    }
    char newString[strlen(a)];
    for (int i = 0; i < strlen(a) - 1; i++) {
        int chr;
        recv(c, &chr, sizeof(chr), MSG_WAITALL);
        chr = ntohs(chr);
        newString[i] = (char)chr;
    }
    printf("%s" ,newString);

    close(c);
}