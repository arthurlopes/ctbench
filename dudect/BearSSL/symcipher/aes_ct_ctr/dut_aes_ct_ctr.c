#include <stdlib.h>
#include <stdint.h>
#include <string.h> // memcmp
#include "dut.h"
#include "random.h"
#include "../../../BearSSL/inc/bearssl_block.h"
#include "../../../BearSSL/inc/bearssl.h"
#include "../../../BearSSL/src/inner.h"
#include "../../../BearSSL/src/config.h"

br_aes_ct_ctr_keys ctx;
uint32_t key = 0;
const size_t chunk_size = 16;
const size_t number_measurements = 1e6; // per test

uint8_t do_one_computation(uint8_t *data) {
    uint8_t in[16] = {0};
    uint8_t ret = 0;
    uint32_t iv[3] = {0};

    memcpy(in, data, 16);

    // chain some encryptions
    for (int i = 0; i < 30; i++) {
        br_aes_ct_ctr_run(&ctx, iv, 0, (uint32_t *)in, 4);
    }

return ret;
}

void init_dut(void) {
    br_aes_ct_ctr_init(&ctx, &key, 4);
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
