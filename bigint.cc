#include <iostream>
#include <vector>
#include "helpers.hh"
#include <assert.h>

using namespace std;

vector<int> increase(vector<int> v) {
  bool carry = true;
  for (int i=v.size()-1; i>= 0; --i) {
    if (carry) v[i] = (v[i] + 1) % 10;
    carry = (v[i] == 0);
  }
  if (carry) v.insert(v.begin(), 1);
  return v;
}

int main(int argc, char** argv) {
  vector<int> v = {9,9};

  assert(increase({9,9}) == vector<int>({1,0,0}));
  assert(increase({1,9}) == vector<int>({2,0}));
  assert(increase({0})   == vector<int>({1}));
  assert(increase({1,0}) == vector<int>({1,1}));

  return 0;
}
