#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_dec_password() {
  char enc_flag[19] = {0x30, 0x36, 0x33, 0x26, 0x31, 0x1c, 0x30,
                       0x36, 0x33, 0x26, 0x31, 0x1c, 0x30, 0x26,
                       0x20, 0x31, 0x26, 0x37, 0x0};
  char *password = malloc(19);
  password[18] = 0;
  for (int i = 0; i < 18; i++)
    password[i] = enc_flag[i] ^ 0x43;
  return password;
}

int main(int argc, char **argv) {

  char buff[32];

  puts("Enter the password:");

  scanf("%32s", buff);

  if (strcmp(buff, get_dec_password()) == 0)
    puts("congrats you found the flag");
  else
    puts("wrong password");

  return 0;
}
