#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char **argv) {

  char *flag = "quack{a_something}";
  char *b2 = malloc(18);

  for (int i = 0; i < 18; i++)
    b2[i] = ((flag[i] ^ 0x55 + 1) & (0xFF & (char)~(1 << 7)));

  for (int i = 0; i < 18; i += 2)
    b2[i] = (b2[i] ^ 0x25);

  for (int i = 0; i < 18; i++)
    printf("0x%x, ", b2[i]);

  printf("0x%x\n", 0x0);

  return 0;
}
