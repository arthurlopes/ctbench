#include <stdlib.h>
#include <stdint.h>
#include <string.h> // memcmp
#include "rijndael-alg-fst.h"
#include "dut.h"
#include "random.h"

static uint32_t rk[44] = {0};
const size_t chunk_size = 16;
const size_t number_measurements = 1e6; // per test

uint8_t do_one_computation(uint8_t *data) {
  uint8_t in[16] = {0};
  uint8_t out[16] = {0};
  uint8_t ret = 0;

  memcpy(in, data, 16);

  // chain some encryptions
  for (int i = 0; i < 30; i++) {
    rijndaelEncrypt(rk, 10, in, out);
    memcpy(in, out, 16);
  }

  ret ^= out[0];
  return ret;
}

void init_dut(void) {
  uint8_t cipherKey[16] = {0};
  rijndaelKeySetupEnc(rk, cipherKey, 128);
}

int main() {
    unsigned char a[128], b[128];

    memset(a, 42, sizeof(a));
    memset(b, 42, sizeof(b));

    ct_poison(a, sizeof(a));

    init_dut();
    do_one_computation(a);

    return 0;
}
