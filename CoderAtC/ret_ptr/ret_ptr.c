#include <string.h>
#include "ret_ptr.h"

static const char *msg[] = {"Sunday", "Monday", "Tuesday", 
			    "Wednesday", "Thursday", "Friday", "Saturday"};
char buf[20];

char *get_a_day(int index)
{
  printf("index: %d\n", index);
  printf("msg[index]: %s\n", msg[index]);
  strcpy(buf, msg[index]);
  printf("buf: %s\n", buf);
  return buf;
}

