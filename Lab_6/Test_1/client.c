#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

#define MAX_LEN 1024

void SendIP(char* message)
{
    struct sockaddr_in local;

    inet_aton("127.0.0.1", &local.sin_addr);
    local.sin_port = htons(1488);
    local.sin_family = AF_INET;

    int s = socket(AF_INET, SOCK_STREAM, 0);
    connect(s, (struct sockaddr*) &local, sizeof(local));

    write(s, message, strlen(message) + 1);
    close(s);
}

int main(int argc, char *argv[])
{
    char message[MAX_LEN];

    if(argc != 2)
    {
        printf("Error! Wrong number of arguments.\n");

        return -1;
    }

    struct hostent *h;
    h = gethostbyname(argv[1]);

    if(h == NULL)
    {
        printf("Eror! Can not find host.\n");

        return -1;
    }

    if(h->h_addrtype != AF_INET)
    {
        printf("Not IPv4.\n");

        return 0;
    }

    int i;
    for(i = 0; h->h_addr_list[i]; ++i)
    {
        struct in_addr* address = (struct in_addr*)h->h_addr_list[i];

        memset(message, 0, MAX_LEN * sizeof(char));
        strcat(message, argv[1]);
        strcat(message, " ");
        strcat(message, inet_ntoa(*address));

        SendIP(message);
    }

    return 0;
}
