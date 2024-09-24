#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef bool (*check_fn)(char *str);

bool check1(char *cmp) {
  char str[256] = "quack{w0";
  return strncmp(cmp, str, 8) == 0;
}

bool check2(char *cmp) {
  char str[256] = "w_qu4ck1";
  return strncmp(cmp, str, 8) == 0;
}

bool check3(char *cmp) {
  char str[256] = "ng_g00d_";
  return strncmp(cmp, str, 8) == 0;
}

bool check4(char *cmp) {
  char str[256] = "j0b_y0u}";
  return strncmp(cmp, str, 8) == 0;
}

check_fn dispatch_table[4] = {check1, check2, check3, check4};

int main(int argc, char **argv) {

  char input[512] = {0};

  printf("Enter the flag: ");

  if (fgets(input, sizeof(input), stdin) == 0) {
    return EXIT_FAILURE;
  }

  for(int i = 0; i < sizeof(dispatch_table)/sizeof(check_fn); i++){
    if(!dispatch_table[i](input+i*8)){
      printf("Invalid Flag %d", i+1);
      exit(0);
    }
  }

  puts("Congrats on getting the flag!");

  return 0;
}
