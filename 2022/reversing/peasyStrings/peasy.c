#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_dec_password() {
  char enc_flag[28] = {0x18, 0x1c, 0x8,  0xa,  0x2,  0x12, 0x1d,
                       0x1,  0x0,  0x1a, 0x36, 0x0,  0x1a, 0x36,
                       0x1d, 0x6,  0x6,  0x36, 0xc,  0x8,  0x1a,
                       0x10, 0x36, 0x5d, 0x5c, 0x14, 0x69, 0x0};

  char *password = malloc(27);
  password[27] = 0;
  for (int i = 0; i < 27; i++)
    password[i] = enc_flag[i] ^ 0x69;
  return password;
}

int main(int argc, char **argv) {

  double input = 0;

  puts("Enter the super secret number");
  scanf("%lu", (uint64_t *)&input);

  //quack{this_is_too_easy_45}
  // 9221120237041090560 The int representation of NAN
  //  NAN != NAN  holds true that is the trick
  if (input == input) {
    puts("The duck quacks NaN NaN NaN NaN BATMAN!!");
    return 0;
  }

  char buff[32];

  puts("Enter the flag:");

  scanf("%32s", buff);

  if (strcmp(buff, get_dec_password()) == 0)
    puts("congrats you found the flag");
  else
    puts("wrong password");

  return 0;
}
