#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <sys/select.h>
#include <unistd.h>
#include <termios.h>

char *file_to_string(FILE *file);

void cursor_hide();
void cursor_show();
void reset_screen();

typedef struct _vec2
{
    uint16_t x;
    uint16_t y;
} vec2;

typedef struct _escaped_char
{
    uint8_t n;
    char *str;
} escaped_char;

vec2 get_console_size();
void raw_mode_enable();
void raw_mode_disable();
struct termios get_terminal_conf();
void set_terminal_conf(struct termios conf);
int was_kbhit();
void getchar_escaped(escaped_char *ec);

#endif
