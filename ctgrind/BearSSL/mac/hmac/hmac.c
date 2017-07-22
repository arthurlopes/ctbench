#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>

#include "../../ctgrind.h"

#include "../../../BearSSL/inc/bearssl_block.h"
#include "../../../BearSSL/inc/bearssl.h"
#include "../../../BearSSL/src/inner.h"
#include "../../../BearSSL/src/config.h"

br_hmac_key_context kc;
br_hmac_context ctx;
br_hash_class dig;
uint32_t key[64] = {0};
const size_t chunk_size = 16;
const size_t number_measurements = 1e6; // per test

uint8_t do_one_computation(uint8_t *data) {
    uint8_t in[64] = {0};
    uint8_t ret = 0;
    uint32_t iv[32] = {0};
    uint32_t out[32] = {0};

    memcpy(in, data, 32);

    br_hmac_update(&ctx, in, 32);

    return ret;
}

void init_dut(void) {
    br_hmac_key_init(&kc, &br_md5_vtable, key, 32);
    br_hmac_init(&ctx, &kc, 0);
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
