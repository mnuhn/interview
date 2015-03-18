#include <iostream>
#include <stdint.h>
#include <vector>
#include <limits>
#include <assert.h>

using namespace std;

vector<bool> parity_lookup;

bool parity_slow(uint64_t x) {
  bool parity = 0;
  for (size_t i=0; i<64; ++i) {
    parity ^= x&1;
    x >>= 1;
  }
  return parity;
}

bool parity_fast(uint64_t x) {
  int16_t part_a =  x      & 0xFFFF;
  int16_t part_b = (x>>8 ) & 0xFFFF;
  int16_t part_c = (x>>16) & 0xFFFF;
  int16_t part_d = (x>>24) & 0xFFFF;

  return parity_lookup[part_a] ^ parity_lookup[part_b] ^ parity_lookup[part_c] ^ parity_lookup[part_d];
}


int main(int argc, char** argv) {
  uint64_t x = 9;

  for (size_t i=0;i<65536; ++i) {
    parity_lookup.push_back(parity_slow(i));
  }

  assert(parity_fast(1) == 1);
  assert(parity_fast(2) == 1);
  assert(parity_fast(3) == 0);

  for (uint64_t i=0;i<std::numeric_limits<uint64_t>::max();++i) {
    if (i%1000000 == 0) cout << "." << endl;
    assert(parity_slow(x) == parity_fast(x));
  }
}
