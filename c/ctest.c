#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>    
#include <netdb.h>

int main() {
    int soc = socket(AF_INET, SOCK_STREAM, 0);
    // now we want to call connect()
    // connect(int sockfd, struct sockaddr* address, socklen_t addrlen)

    // set up sockaddr_in for the server's address to pass into connect
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    memset(&server.sin_zero, 0, 8);
    server.sin_port = htons(45001);

    // now we just need to set server.sin_addr.s_addr to the IP address.
    // to get IP address, we use getaddrinfo() and pass in the machine name.

    // int getaddrinfo(char* host, char* service, struct addrinfo* hints, struct addrinfo** result)
    // recall we set second and third param to null.

    // suppose the client we want to connect to has name "teach.cs.toronto.edu"
    // now we just need to pass in the struct addrinfo** result argument

    
    /* pulled this from netdb.h */
    struct addrinfo
    {
        int ai_flags;            /* Input flags.  */
        int ai_family;        /* Protocol family for socket.  */
        int ai_socktype;        /* Socket type.  */
        int ai_protocol;        /* Protocol for socket.  */
        socklen_t ai_addrlen;        /* Length of socket address.  */
        struct sockaddr *ai_addr;    /* Socket address for socket.  */
        char *ai_canonname;        /* Canonical name for service location.  */
        struct addrinfo *ai_next;    /* Pointer to next in list.  */
    };
    // i defined the struct again, pulling it from netdb.h because i was getting errors in intellisense for some reason.


    // first declare a struct addrinfo* type:
    struct addrinfo* result;

    // // pass the address of result. getaddrinfo() will return a linked list in result whose nodes contain valid memory addresses that satisfy the request.
    // if (getaddrinfo("localhost", NULL, NULL, &result) != 0) { // note we are using localhost to connect to our own machine.
    //     perror("getaddrinfo");
    //     exit(1);
    // }
    // server.sin_addr = ( (struct sockaddr_in *) result->ai_addr )->sin_addr;
    // freeaddrinfo(result); // we can free the result now.

    inet_pton(AF_INET, "172.29.62.216", &server.sin_addr);
    
    printf("connecting...\n");

    // atp server sockaddr_in is set up and we can call connect()
    int return_code = connect(soc, (struct sockaddr*) &server, sizeof(struct sockaddr_in));

    // we capture the return value to check if the connection worked.
    if (return_code == -1) {
        perror("connect");
        exit(1);
    } // note that connect returns a -1 if we fail
    printf("connection return with: %d\n", return_code);
    
        // now we test communicating by redircecting output.
    dup2(soc, fileno(stdout));

    char s[50];
    while (1 != 0) {
        scanf("%s", &s);
        printf("%s\n", &s);
    }
    

    return 0;
}