#include <stdio.h>
#include "populator.h"

int main(void)
{
  unit_t u;

  set_unit(&u);
  printf("number %d\nmsg: %s\n", u.number, u.msg);
  return 0;
}
