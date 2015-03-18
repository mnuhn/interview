#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dump(std::vector<int> &v) {
  for (auto x : v) {
    std::cout << x << ",";
  }
  std::cout << std::endl;
}

int main(int argc, char** argv) {
  std::vector<int> v = { 5, 9, 1, 6, 9, 11, 23, 5, 54, 74, 33, 50, 5, 21, 19, 3, 2, 1 };

  size_t left = 0;
  size_t right = v.size() -1;

  size_t p = 7;
  size_t pivot = v[p];

  size_t i=0;
  while (i != right) {
    dump(v);
    if (v[i] < pivot) {
      swap(v[left++], v[i++]);
    } else if (v[i] > pivot) {
      swap(v[right--], v[i]);
    } else {
      i++;
    }
  }
  return 0;
}
