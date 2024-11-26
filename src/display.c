#include <time.h>
#include <string.h>

#include "display.h"
#include "weather.h"

#define NUMLINES 4

typedef struct _weather_stat {
    char *name;
    char *format_str;
    double value;
} weather_stat;

char *format_stat(weather_stat stat)
{
    int format_bufsize = snprintf(NULL, 0, stat.format_str, stat.value) + 1;
    char *format_buf = malloc(format_bufsize * sizeof(char));
    snprintf(format_buf, format_bufsize, stat.format_str, stat.value);

    #define BUFFER_LEN 24
    #define NAME_LEN 12

    char *buffer = malloc(BUFFER_LEN);
    char *end = memccpy(buffer, stat.name, '\0', NAME_LEN);
    end = end ? end : buffer + NAME_LEN;
    memset(end - 1, '.', BUFFER_LEN - strlen(stat.name));
    memccpy(buffer + BUFFER_LEN - format_bufsize, format_buf, '\0', format_bufsize);
    buffer[BUFFER_LEN - 1] = '\0';

    return buffer;
}

void display(window *win, window *win_prev, weather_data *weather)
{
    time_t t_curr;
    time(&t_curr);
    struct tm *t = localtime(&t_curr);

    weather_stat temperature_2m = { "temperature", "%.1lfF", *weather->current->temperature_2m };
    weather_stat apparent_temperature = { "feels like", "%.1lfF", *weather->current->apparent_temperature };
    weather_stat precipitation = { "precipition", "%.1lfmm", *weather->current->precipitation };
    weather_stat cloud_cover = { "cloud cover", "%.1lf%%", *weather->current->cloud_cover };

    char *temperature_2m_str = format_stat(temperature_2m);
    char *apparent_temperature_str = format_stat(apparent_temperature);
    char *precipitation_str = format_stat(precipitation);
    char *cloud_cover_str = format_stat(cloud_cover);

    char *lines[NUMLINES] = {
        temperature_2m_str,
        apparent_temperature_str,
        precipitation_str,
        cloud_cover_str
    };

    // printf("we're beginning\n");
    // printf("%s\n", temperature_2m_str);
    // printf("we're ending\n");

    window_fill_color(win, COLOR_BLACK);

    for (int i = 0; i < NUMLINES; i++)
    {
        window_draw_text(win, lines[i], 2, 2 + i * (FONT_HEIGHT + 2), COLOR_WHITE);
    }

    render_window(win, win_prev);
}