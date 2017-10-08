#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>

int main() {
    int c, suma;
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
    fgets(a, sizeof(a), stdin);
    int len = strlen(a);
    len = htons(len);
    send(c, &len, sizeof(len), 0);
    for (int i = 0; i < strlen(a) - 1; i++) {
        int ch = htons(a[i]);
        send(c, &ch, sizeof(ch), 0);
    }
    recv(c, &suma, sizeof(suma), 0);
    suma = ntohs(suma);
    printf("Numarul de spatii este %d\n", suma);
    close(c);
}