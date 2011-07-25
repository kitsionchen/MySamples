#include <stdio.h>


// a simple implementation of strncpy
char * strncpy(char *dest, const char *src, size_t n)
{
  size_t i;
  for(i = 0; i < n && src[i] != '\0'; i++)
    dest[i] = src[i];

  for(; i < n; i++)
    dest[i] = '\0';

  return dest;
}

int main(void)
{
  const char *src = "kitsionchen\0";
  char dest[10];
  strncpy(dest, src, sizeof(dest));
  dest[sizeof(dest)-1] = '\0';
  printf("%s\n",dest);

  char *buf[20];
  printf("%s\n", strncpy(buf, src, 10));

  return 0;
} 
