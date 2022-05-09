#include <stdio.h>
#include <stdlib.h>

void do_stuff() {
  char buff[32];

  puts("Welcome");
  printf("the duck gives you a shout %p\n", (void *)puts);
  read(0, buff, 256);
  puts("/bin/cat flag.txt");
}

void rop2() {}


void rop() {
  asm("pop %rdi");
  asm("ret");
}

int main(int argc, char **argv) {
  setbuf(stdout, NULL);
  setbuf(stdin, NULL);
  setbuf(stderr, NULL);
  do_stuff();

  return 0;
}
