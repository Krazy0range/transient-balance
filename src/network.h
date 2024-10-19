#ifndef NETWORK_H
#define NETWORK_H

#include <stdio.h>

#define BUFFER_SIZE 1024
#define MAX_REQUEST_LEN BUFSIZ

#define WGET_EXIT_SUCCESS                       0
#define WGET_EXIT_FAILURE                       1
#define WGET_EXIT_FAILURE_request_len_too_large 2
#define WGET_EXIT_FAILURE_getprotobyname        3
#define WGET_EXIT_FAILURE_socket                4
#define WGET_EXIT_FAILURE_gethostbyname         5
#define WGET_EXIT_FAILURE_inet_addr             6
#define WGET_EXIT_FAILURE_connect               7
#define WGET_EXIT_FAILURE_write                 8
#define WGET_EXIT_FAILURE_read                  9

int wget(char *hostname, char *path, int response_fd);

#endif