
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

void ascon(void*);

uint8_t tv[]=
{ 0xc6,0x6c,0x64,0x40,0xe0,0x32,0x1a,0x5b,
  0x2e,0x3e,0x9b,0xa3,0x3d,0x61,0x65,0x7a,
  0x2f,0x6c,0xf6,0x91,0xc8,0x67,0x11,0x72,
  0x70,0xad,0x4c,0x60,0x9b,0x5b,0xc8,0x32,
  0x15,0xc6,0xf6,0x21,0x3c,0xfd,0x84,0xf3 };

void bin2hex(void *x, int len) {
    int i;
    for (i=0; i<len; i++) {
      if ((i & 7)==0) putchar('\n');
      printf ("0x%02x,", ((uint8_t*)x)[i]);
    }
    putchar('\n');
}

int main(void) {
  uint64_t s[5];
  int      i, equ;
  
  for (i=0; i<5; i++) s[i] = i;
  
  ascon(s);
  
  equ = (memcmp(s, tv, sizeof(tv))==0);
  bin2hex(&s, sizeof(s));
  
  printf("\nAscon test %s\n", equ ? "OK" : "FAILED");
  return 0;
}
