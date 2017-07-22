#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

// https://cryptocoding.net/index.php/Coding_rules#Compare_secret_strings_in_constant_time
int util_cmp_const(const void *a, const void *b, const size_t size) {
  const unsigned char *_a = (const unsigned char *)a;
  const unsigned char *_b = (const unsigned char *)b;
  unsigned char result = 0;
  size_t i;

  for (i = 0; i < size; i++) {
    result |= _a[i] ^ _b[i];
  }

  return result; /* returns 0 if equal, nonzero otherwise */
}
