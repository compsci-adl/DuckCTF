#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
  char buff[32];

  puts("Enter the password:");

  scanf("%32s", buff);

  if (strcmp(buff, "mayooooo!") == 0)
    puts("congrats the flag is quack{abnja_apple_pear}");
  else
    puts("wrong password");

  return 0;
}
