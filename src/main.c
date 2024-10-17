#include<stdlib.h>
#include<stdint.h>
#include<stdio.h>
#include<time.h>
#include <fcntl.h>

#include "network.h"
#include "utils.h"

void disp_t(time_t);

int main(int argc, char *argv[])
{
  // FILE *response;
  // response = fopen("response.txt", "w");

  int response_fd = open("response.txt", O_WRONLY | O_TRUNC | O_CREAT, S_IWUSR);

  if (wget("example.com", response_fd) != WGET_EXIT_SUCCESS)
  {
    perror("whoopsie occurred uwu");
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
