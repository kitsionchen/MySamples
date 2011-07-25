#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, int len) {
  int i;
  for(i = 0; i < len; i++) 
    printf(" %.2x", start[i]);
  printf("\n");
}

int fun1(unsigned w) {
  return (int)((w << 24) >> 24);
}

int fun2(unsigned w) {
  return ((int) w << 24) >> 24;
}

int main(void) {
  short sx = -12345;
  unsigned short usx = sx;
  int x = sx;
  unsigned ux = usx;

  printf("sx = %d:\t", sx);
  show_bytes((byte_pointer) &sx, sizeof(short));

  printf("usx = %u:\t", usx);
  show_bytes((byte_pointer) &usx, sizeof(unsigned short));

  printf("x = %d:\t", x);
  show_bytes((byte_pointer) &x, sizeof(int));

  printf("ux = %u:\t", ux);
  show_bytes((byte_pointer) &ux, sizeof(unsigned));

  printf("\n");
  unsigned w1 = 0x00000076;
  printf("w1 = %x:\t", w1);
  show_bytes((byte_pointer) &w1, sizeof(unsigned));
  int w11 = fun1(w1);
  printf("w11 = %x:\t", w11);
  show_bytes((byte_pointer) &w11, sizeof(int));
  int w12 = fun2(w1);
  printf("w12 = %x:\t", w12);
  show_bytes((byte_pointer) &w12, sizeof(int));

  printf("\n");
  unsigned w2 = 0x87654321;
  printf("w2 = %x:\t", w2);
  show_bytes((byte_pointer) &w2, sizeof(unsigned));
  int w21 = fun1(w2);
  printf("w21 = %x:\t", w21);
  show_bytes((byte_pointer) &w21, sizeof(int));
  int w22 = fun2(w2);
  printf("w22 = %x:\t", w22);
  show_bytes((byte_pointer) &w22, sizeof(int));

  printf("\n");
  unsigned w3 = 0x000000C9;
  printf("w3 = %x:\t", w3);
  show_bytes((byte_pointer) &w3, sizeof(unsigned));
  int w31 = fun1(w3);
  printf("w31 = %x:\t", w31);
  show_bytes((byte_pointer) &w31, sizeof(int));
  int w32 = fun2(w3);
  printf("w32 = %x:\t", w32);
  show_bytes((byte_pointer) &w32, sizeof(int));

  printf("\n");
  unsigned w4 = 0xEDCBA987;
  printf("w4 = %x:\t", w4);
  show_bytes((byte_pointer) &w4, sizeof(unsigned));
  int w41 = fun1(w4);
  printf("w41 = %x:\t", w41);
  show_bytes((byte_pointer) &w41, sizeof(int));
  int w42 = fun2(w4);
  printf("w42 = %x:\t", w42);
  show_bytes((byte_pointer) &w42, sizeof(int));

  return 0;
}
