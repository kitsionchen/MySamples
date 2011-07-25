#include <stdio.h>

int main(void)
{
  int i = 0xcffffff3;
  printf("%x\n", 0xcffffff3 >> 2);
  printf("%x\n", i >> 2);
  return 0;
}
