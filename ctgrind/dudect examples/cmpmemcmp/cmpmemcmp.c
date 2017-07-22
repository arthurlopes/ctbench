#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "random.h"
#include "dut.h"

const size_t chunk_size = 16;
const size_t number_measurements = 1e5; // per test

uint8_t do_one_computation(uint8_t *data) {
  //uint8_t secret[16] = {0x2b,0x7e,0x15,0x16,0x28,0xae,0xd2,0xa6,0xab,0xf7,0x15,0x88,0x09,0xcf,0x4f,0x3c};
  uint8_t secret[16] = {0};
  return (uint8_t)memcmp(secret, data, 16);
}

void init_dut(void) {}

/*
 * This is a simple example on how good test vectors
 * accelerate leakage detection. The code below defines
 * two input classes:
 *  a) random input
 *  b) input fixed to 0
 *
 * This helps to detect timing leakage in do_one_computation()
 * above. The process is faster if the input is equal to the
 * `secret` variable inside do_one_computation(). In that case,
 * the timing difference is be much larger and hence more
 * easily detectable. Otherwise, the timing difference is still
 * detectable but more measurements are needed. (Try changing
 * the value of `secret` variable.)
 *
 * Morale: carefully crafted input vectors detect much faster
 * leakage (``whitebox'' testing).
 *
 */
int main() {
    unsigned char a[128], b[128];
    
    memset(a, 42, sizeof(a));
    memset(b, 42, sizeof(b));
    
    ct_poison(a, sizeof(a));
    
    init_dut();
    do_one_computation(a);
    
    return 0;
}
