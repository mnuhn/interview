#include <iostream>
#include <stdint.h>

using namespace std;

uint64_t int_sqrt(int64_t target) {
  uint64_t left = 0;
  uint64_t right = (static_cast<uint64_t>(1) << 32);

  while (left != right) {
    uint64_t mid = left + ((right - left) / 2);
    if (mid*mid <= target && (mid+1)*(mid+1) > target) {
      return mid;
    } else if (mid*mid < target) {
      left = mid;
    } else if (mid*mid > target) {
      right = mid;
    }
  }
  return 0;
}

int main(int argc, char** argv) {
  for (size_t i=0; i<32000;++i) {
    cout << i << " " << int_sqrt(i) << endl;
  }
}
