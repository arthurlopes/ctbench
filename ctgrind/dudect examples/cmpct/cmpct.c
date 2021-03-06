#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "random.h"
#include "dut.h"

const size_t chunk_size = 16;
const size_t number_measurements = 1e5; // per test

// https://cryptocoding.net/index.php/Coding_rules#Compare_secret_strings_in_constant_time
static int util_cmp_const(const void *a, const void *b, const size_t size) {
  const unsigned char *_a = (const unsigned char *)a;
  const unsigned char *_b = (const unsigned char *)b;
  unsigned char result = 0;
  size_t i;

  for (i = 0; i < size; i++) {
    result |= _a[i] ^ _b[i];
  }

  return result; /* returns 0 if equal, nonzero otherwise */
}

uint8_t do_one_computation(uint8_t *data) {
  uint8_t secret[16] = {0};

  return (uint8_t)util_cmp_const(secret, data, 16);
}

void init_dut(void) {}

int main() {
    unsigned char a[128], b[128];
    
    memset(a, 42, sizeof(a));
    memset(b, 42, sizeof(b));
    
    ct_poison(a, sizeof(a));
    
    init_dut();
    do_one_computation(a);
    
    return 0;
}

