#include <stdlib.h>
#include <stdint.h>
#include <string.h> // memcmp
#include "../../ctgrind.h"
#include "../../../nacl-20110221/build/ubuntuxenial/include/amd64/crypto_box.h"

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

int main() {
    unsigned char a[128], b[128];
    
    memset(a, 42, sizeof(a));
    memset(b, 42, sizeof(b));
    
    ct_poison(a, sizeof(a));
    
    init_dut();
    do_one_computation(a);
    
    return 0;
}
