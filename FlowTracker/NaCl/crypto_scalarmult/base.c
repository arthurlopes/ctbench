/*
version 20081011
Matthew Dempsky
Public domain.
Derived from public domain code by D. J. Bernstein.
*/

#include "../../../build/ubuntuxenial/include/amd64/crypto_scalarmult_curve25519.h"

const unsigned char base[32] = {9};

int crypto_scalarmult_base(unsigned char *q,
  const unsigned char *n)
{
  return crypto_scalarmult(q,n,base);
}
