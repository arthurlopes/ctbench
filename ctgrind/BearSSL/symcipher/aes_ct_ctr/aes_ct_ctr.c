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

br_aes_ct_ctr_keys ctx;
uint32_t key = 0;
uint8_t in[16] = {0};
uint32_t iv[3] = {0};

int main() {
    unsigned char a[16], b[16];

    memset(a, 42, sizeof(a));
    memset(b, 42, sizeof(b));

    ct_poison(a, sizeof(a));

    br_aes_ct_ctr_init(&ctx, &key, 4);

    br_aes_ct_ctr_run(&ctx, iv, 0, (uint32_t *)in, 4);


    return 0;
}
