#include <stdlib.h>
#include <stdint.h>
#include <string.h> // memcmp
#include "dut.h"
#include "random.h"
#include "../../../BearSSL/inc/bearssl_rsa.h"
#include "../../../BearSSL/inc/bearssl.h"
#include "../../../BearSSL/src/inner.h"
#include "../../../BearSSL/src/config.h"

br_rsa_private_key key;
const size_t chunk_size = 16;
const size_t number_measurements = 1e3; // per test

uint8_t do_one_computation(uint8_t *data) {
    uint8_t in[64] = {0};
    uint8_t ret = 0;
    uint8_t x[32] = {110};

    key.p = data;
    key.q = data;
    key.iq = data;
    key.n_bitlen = 64;
    key.plen  = 32;
    key.qlen  = 32;
    key.iqlen = 32;

    br_rsa_i31_private(x, &key);

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
