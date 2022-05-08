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

int main(int argc, char **argv) {

  char *str = malloc(32);

  unsigned long start = time(NULL) >> 2;

  printf("%ld\n", start);

  srand(start);

  for (int i = 0; i < 30; i++) {
    memset(str, 0, 32);

    sprintf(str, "%d", rand());

    char *output = str2md5(str, strlen(str));
    printf("%s\n", output);
    free(output);
  }
  free(str);

  return 0;
}
