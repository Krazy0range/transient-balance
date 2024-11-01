#ifndef NETWORK_H
#define NETWORK_H

#include <stdio.h>

#define _DEBUG

#define BUFFER_SIZE 1024
#define MAX_REQUEST_LEN 2048

#define NETWORK_EXIT_SUCCESS                       0
#define NETWORK_EXIT_FAILURE                       1
#define NETWORK_EXIT_FAILURE_request_len_too_large 2
#define NETWORK_EXIT_FAILURE_getprotobyname        3
#define NETWORK_EXIT_FAILURE_socket                4
#define NETWORK_EXIT_FAILURE_gethostbyname         5
#define NETWORK_EXIT_FAILURE_inet_addr             6
#define NETWORK_EXIT_FAILURE_connect               7
#define NETWORK_EXIT_FAILURE_write                 8
#define NETWORK_EXIT_FAILURE_read                  9
#define NETWORK_EXIT_FAILURE_find_response_body    10

// #define NETWORK_TRANSFER_ENCODING_NORMAL  0
// #define NETWORK_TRANSFER_ENCODING_CHUNKED 1

int network_response(char *hostname, char *path, int response_fd);
int response_body(FILE *response_file, FILE *body_file, int transfer_encoding);

#endif