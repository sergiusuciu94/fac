#include <sys/types.h>
#include <sys/socket.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>

int main() {
    srand(time(NULL));
    int c;
    int r = rand() % 10;
    int elements[r];
    struct sockaddr_in server;
    uint16_t a, b, suma;
    for (int i = 0; i < r; i++) {
        elements[i] = rand() % 20;
    }
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

    a = htons(r);
    for (int j = 0; j < r; j++ ) {
        printf("Element[%d] = %d\n", j, elements[j] );
    }
    send(c, &a, sizeof(a), 0);
    for(int j = 0; j < r; j++) {
        b = htons(elements[j]);
        send(c, &b, sizeof(b), 0);
    }
    recv(c, &suma, sizeof(suma), 0);
    suma = ntohs(suma);
    printf("Suma este %hu\n", suma);
    close(c);
}