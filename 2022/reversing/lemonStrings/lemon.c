#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char enc_flag[19] = {

    0x2,  0x23, 0x12, 0x35, 0x18, 0x2d, 0x12, 0x9,  0x0, 0x39,
    0x1e, 0x33, 0x7,  0x3e, 0x1a, 0x38, 0x14, 0x2b, 0x0};
bool check_password(char *buffer, int size) {

  for (int i = 0; i < size; i++) {
    char aa = ((buffer[i] ^ 0x55 + 1) & (0xFF & (char)~(1 << 7)));
    char bb = aa;
    if (i % 2 == 0)
      bb = bb ^ 0x25;

    if ((((bb & 0xFFFFF) != enc_flag[i]) & 0xFFFFFF) > 0) {
      return false;
    }
  }
  return true;
}

int main(int argc, char **argv) {

  char buff[32];

  puts("Enter the flag:");

  scanf("%32s", buff);

  if (check_password(buff, 2 + ((0x123467814 & 0x4) << 2)))
    puts("congrats you found the flag");
  else
    puts("wrong flag");

  return 0;
}
