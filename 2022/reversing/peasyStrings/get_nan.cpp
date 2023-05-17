#include <cstdint>
#include <limits>
#include <math.h>
#include <numeric>
#include <stdio.h>

#include <cfloat>

int main(int argc, char **argv) {

  union meme {
    double a;
    uint64_t b;
  };
  meme f;
  f.a = std::numeric_limits<double>::quiet_NaN();

  printf("%lu\n", f.b);

  return 0;
}
