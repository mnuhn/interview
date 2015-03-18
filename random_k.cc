#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

#include "helpers.hh"

using namespace std;

default_random_engine gen(time(0));

vector<int> random_k_subset(vector<int> v, size_t k) {
  for (size_t i=0; i<k; ++i) {
    uniform_int_distribution<size_t> dist(i, v.size() - 1);
    size_t selected_idx = dist(gen);
    swap(v[i], v[selected_idx]);
  }
  v.resize(k);
  return v;
}

int main(int argc, char** argv) {
  vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8 };
  for (size_t i=0; i<100;++i) {
    dump(random_k_subset(v,5));
  }
  return 0;
}
