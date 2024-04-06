#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h> 
#include <netinet/in.h>


int main() {
    int soc = socket(AF_INET, SOCK_STREAM, 0);

    // set up sockaddr_in for the server's address to pass into connect
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    memset(&server.sin_zero, 0, 8);
    server.sin_port = htons(54321);

    // now we just need to set server.sin_addr.s_addr to the IP address.
    // to get IP address, we use getaddrinfo() and pass in the machine name.

    // getaddrinfo(char* host, char* service, struct addrinfo* hints, struct addrinfo** result)
    // recall we set second and third param to null.

    // suppose the client we want to connect to has name "teach.cs.toronto.edu"
    // now we just need to pass in the struct addrinfo** result argument

    // first declare a struct addrinfo* type:
    struct addrinfo* result;
    // pass the address of result. getaddrinfo() will return a linked list in result whose nodes contain valid memory addresses that satisfy the request.

    getaddrinfo("teach.cs.toronto.edu", NULL, NULL, &result);

    return 0;
}