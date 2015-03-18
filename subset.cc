#include <algorithm>
#include <vector>
#include <random>
#include <iostream>

#include "helpers.hh"

using namespace std;

default_random_engine gen(time(0));

vector<int> random_subset(vector<int> v) {
  size_t pos = 0;
  size_t kept = 0;
  int rand = 0;

  for (int pos=0;pos<v.size();++pos) {
    // need new random number?
    if (pos % sizeof(rand) == 0) {
      rand = gen();
    }

    if (rand % 2) {
      swap(v[pos],v[kept++]);
    }

    rand = rand >> 1;

  }
  v.resize(kept);
  return v;
}

int main(int argc, char** argv) {

  vector<int> v = { 1,2,3,4,5,6,7,8,9,10};

  while(true) {
    auto vv = random_subset(v);
    dump(vv);
  }

}
