#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>

#include "../../ctgrind.h"

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

int main() {
    unsigned char a[128], b[128];

    memset(a, 42, sizeof(a));
    memset(b, 42, sizeof(b));

    ct_poison(a, sizeof(a));

    init_dut();
    do_one_computation(a);

    return 0;
}
