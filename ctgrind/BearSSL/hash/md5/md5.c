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

int main() {
    unsigned char a[128], b[128];

    memset(a, 42, sizeof(a));
    memset(b, 42, sizeof(b));

    ct_poison(a, sizeof(a));

    init_dut();
    do_one_computation(a);

    return 0;
}
