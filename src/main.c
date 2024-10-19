#include<stdlib.h>
#include<stdint.h>
#include<stdio.h>
#include<time.h>
#include <fcntl.h>

#include "network.h"
#include "utils.h"

#define WEATHER_API_URL "https://api.open-meteo.com/v1/forecast?latitude=30.4394&longitude=-97.62&hourly=temperature_2m,apparent_temperature,precipitation_probability,precipitation,cloud_cover"
#define WEATHER_API_URL_SHORT "https://api.open-meteo.com/v1/forecast?latitude=30.4394&longitude=-97.62&hourly=temperature_2m"
#define WEATHER_API_URL_SHORT_2 "api.open-meteo.com/v1/forecast?latitude=30.4394&longitude=-97.62&hourly=temperature_2m"
#define WEATHER_API_URL_HOSTNAME "api.open-meteo.com"
#define WEATHER_API_URL_PATH_SHORT "/v1/forecast?latitude=30.4394&longitude=-97.62&hourly=temperature_2m"
#define WEATHER_API_URL_PATH_LONG "/v1/forecast?latitude=30.4394&longitude=-97.62&hourly=temperature_2m,apparent_temperature,precipitation_probability,precipitation,cloud_cover"

void disp_t(time_t);

int main(int argc, char *argv[])
{
  // FILE *response;
  // response = fopen("response.txt", "w");

  int response_fd = open("response.txt", O_WRONLY | O_TRUNC | O_CREAT, S_IWUSR);
  int err;
  if ((err = wget(WEATHER_API_URL_HOSTNAME, WEATHER_API_URL_PATH_LONG, response_fd)) != WGET_EXIT_SUCCESS)
  {
    printf("whoopsie occurred uwu\nerror number: %d\n", err);
    // fclose(response);
    close(response_fd);
    return 1;
  }

  // fclose(response);
  close(response_fd);

  return 0; /* :trollface: */

  time_t t_curr;
  time_t t_last;
  time(&t_curr);
  time(&t_last);

  struct termios orig_conf = get_terminal_conf();
  raw_mode_enable();
  cursor_hide();
  
  while (1)
  {
    time(&t_curr);
    time_t t_delta = t_curr - t_last;
    if (t_delta)
      disp_t(t_curr);
    if (was_kbhit())
      if (getchar())
        break;
    t_last = t_curr;
  }

  reset_screen();
  raw_mode_disable();
  set_terminal_conf(orig_conf);
  cursor_show();
  
  return 0;
}

void disp_t(time_t t_curr)
{
  struct tm *t = localtime(&t_curr);
  reset_screen();
  printf("time\n");
  printf("%02d:%02d:%02d\n",
    t->tm_hour,
    t->tm_min,
    t->tm_sec);
}
