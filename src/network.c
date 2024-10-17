#include <arpa/inet.h>
#include <assert.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#include "network.h"

int wget(char *hostname, int response_fd)
{
    /* complicated network stuff */

    char buffer[BUFFER_SIZE];
    char request[MAX_REQUEST_LEN];
    // char request_template[] = "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n";
    char request_template[] = "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n";
    int request_len;
    ssize_t nbytes_total, nbytes_last;
    struct protoent *protoent;
    struct hostent *hostent;
    struct sockaddr_in sockaddr_in;
    in_addr_t in_addr;
    int socket_file_descriptor;
    unsigned short server_port = 80;

    /* poop hostname into template */

    request_len = snprintf(request, MAX_REQUEST_LEN, request_template, hostname);
    if (request_len >= MAX_REQUEST_LEN)
    {
        // fprintf(stderr, "request length too large: %d\n", request_len);
        // return EXIT_FAILURE;
        return WGET_EXIT_FAILURE_request_len_too_large;
    }

    /* build socket */

    protoent = getprotobyname("tcp");
    if (protoent == NULL)
    {
        // perror("getprotobyname");
        // return EXIT_FAILURE;
        return WGET_EXIT_FAILURE_getprotobyname;
    }

    socket_file_descriptor = socket(AF_INET, SOCK_STREAM, protoent->p_proto);
    if (socket_file_descriptor == -1)
    {
        // perror("socket");
        // return EXIT_FAILURE;
        return WGET_EXIT_FAILURE_socket;
    }

    /* build address */

    hostent = gethostbyname(hostname);
    if (hostent == NULL)
    {
        // fprintf(stderr, "error: gethostbyname(\"%s\")\n", hostname);
        // return EXIT_FAILURE;
        return WGET_EXIT_FAILURE_gethostbyname;
    }
    
    in_addr = inet_addr(inet_ntoa(*(struct in_addr*)*(hostent->h_addr_list)));
    if (in_addr == (in_addr_t) - 1)
    {
        // fprintf(stderr, "error: inet_addr(\n%s\n)\n", *(hostent->h_addr_list));
        // return EXIT_FAILURE;
        return WGET_EXIT_FAILURE_inet_addr;
    }

    sockaddr_in.sin_addr.s_addr = in_addr;
    sockaddr_in.sin_family = AF_INET;
    sockaddr_in.sin_port = htons(server_port);

    /* actually connect */

    if (connect(socket_file_descriptor, (struct sockaddr*)&sockaddr_in, sizeof(sockaddr_in)) == -1)
    {
        // perror("connect");
        // return EXIT_FAILURE;
        return WGET_EXIT_FAILURE_connect;
    }

    /* send HTTP request */

    nbytes_total = 0;
    while (nbytes_total < request_len)
    {
        nbytes_last = write(socket_file_descriptor, request + nbytes_total, request_len - nbytes_total);
        if (nbytes_last == -1)
        {
            // perror("write");
            // return EXIT_FAILURE;
            return WGET_EXIT_FAILURE_write;
        }
        nbytes_total += nbytes_last;
    }

    /* read response */

    uint32_t i = 0;
    // fprintf(stderr, "debug: before first read\n");
    while ((nbytes_total = read(socket_file_descriptor, buffer, BUFFER_SIZE)) > 0)
    {
        //0xE2 0x96 0x88
        // buffer[BUFFER_SIZE-4] = '\xe2';
        // buffer[BUFFER_SIZE-3] = '\x96';
        // buffer[BUFFER_SIZE-2] = '\x88';
        // buffer[BUFFER_SIZE-1] = '\0';
        fprintf(stderr, "debug: after read %d\tbytes read %zd\n", i++, nbytes_total);
        // fprintf(response, "%s", buffer);
        // buffer[0] = '\0';
        write(response_fd, buffer, nbytes_total);
    }

    // fprintf(stderr, "debug: after last read\n");
    if (nbytes_total == -1)
    {
        // perror("read");
        // return EXIT_FAILURE;
        return WGET_EXIT_FAILURE_read;
    }

    close(socket_file_descriptor);
    // return EXIT_SUCCESS;
    return WGET_EXIT_SUCCESS;
}