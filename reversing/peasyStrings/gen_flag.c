#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *gen_flag() {
  char *flag = "quack{a_something}";

  for (int i = 0; i < 18; i++)
    printf("0x%x, ", (flag[i] ^ 0x55 + 1) & (0xFF & (char)~(1 << 7)));
  printf("0x%x\n", 0x0);

  return flag;
}

int main(int argc, char **argv) {

  gen_flag();
  return 0;
}
