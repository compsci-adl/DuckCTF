#include <openssl/md5.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

char *str2md5(const char *str, int length) {
  int n;
  MD5_CTX c;
  unsigned char digest[16];
  char *out = (char *)malloc(33);

  MD5_Init(&c);

  while (length > 0) {
    if (length > 512) {
      MD5_Update(&c, str, 512);
    } else {
      MD5_Update(&c, str, length);
    }
    length -= 512;
    str += 512;
  }

  MD5_Final(digest, &c);

  for (n = 0; n < 16; ++n) {
    snprintf(&(out[n * 2]), 16 * 2, "%02x", (unsigned int)digest[n]);
  }

  return out;
}

const char *buff[] = {
    "35181016cbe2466244043120d4bb9eca", "6a813b557c7b373ca1a951071dbeafb6",
    "d98162e6869a16b89446753454a90bb0", "75901622501da75ce4e08ad2fd6de17f",
    "19b0add2663b6eeebe176b70cac6756a",
};

int main(int argc, char **argv) {

  char *str = malloc(32);
  memset(str, 0, 32);
  unsigned long start = time(NULL) >> 2;
//  start = 413004225;

  while (1) {

    srand(start);
    int a = 0;

    for (int i = 0; i < 5; i++) {
      sprintf(str, "%d", rand());
      char *output = str2md5(str, strlen(str));

      printf("%ld : %32s, %32s\n", start, output, buff[i]);

      if (strncmp(output, buff[i], 32) != 0) {
        free(output);
        a = 1;
        break;
      }

      free(output);
    }

    if (a == 0) {
      puts("SOLVED");
      break;
    }
    start--;
  }
  printf("quack{%ld}\n", start);

  free(str);

  return 0;
}
