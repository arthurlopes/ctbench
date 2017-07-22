#include <stdlib.h>
#include <stdint.h>
#include <string.h> // memcmp
#include "dut.h"
#include "random.h"
#include "../../../BearSSL/inc/bearssl_block.h"
#include "../../../BearSSL/inc/bearssl.h"
#include "../../../BearSSL/src/inner.h"
#include "../../../BearSSL/src/config.h"

br_md5_context ctx;
uint32_t key[64] = {0};
const size_t chunk_size = 16;
const size_t number_measurements = 1e5; // per test

uint8_t do_one_computation(uint8_t *data) {
    uint8_t in[64] = {10};
    uint8_t ret = 0;
    uint32_t iv[32] = {10};
    uint32_t out[32] = {0};

    br_md5_round(data, in);
    br_md5_update(&ctx, data, 32);

    return ret;
}

void init_dut(void) {
    br_md5_init(&ctx);
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
