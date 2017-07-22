#include <stdlib.h>
#include <stdint.h>
#include <string.h> // memcmp
#include "dut.h"
#include "random.h"
#include "../../nacl-20110221/build/ubuntuxenial/include/amd64/crypto_box.h"

static uint32_t rk[44] = {0};
const size_t chunk_size = 16;
const size_t number_measurements = 1e5; // per test

uint8_t do_one_computation(uint8_t *data) {
    uint8_t m[128] = {0};
    uint8_t c[128] = {0};
    uint8_t n[128] = {0};
    uint8_t ret = 0;

    crypto_secretbox_open(m, c, 8, n, data);

    return ret;
}

void init_dut(void) {
}

void prepare_inputs(uint8_t *input_data, uint8_t *classes) {
  randombytes(input_data, number_measurements * chunk_size);
  for (size_t i = 0; i < number_measurements; i++) {
    classes[i] = randombit();
    if (classes[i] == 0) {
      memset(input_data + (size_t)i * chunk_size, 0x00, chunk_size);
    } else {
      // leave random
    }
  }
}
