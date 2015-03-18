#include <vector>
#include <algorithm>
#include <iostream>
#include "helpers.hh"

using namespace std;

int capacity(vector<int> z) {
  if (z.size() == 1) return 0;

  int capacity = 0;
  int min_height = z[0];

  for (size_t i=1;i<z.size();++i) {
    min_height = min( min_height, z[i] );
    capacity = max(capacity, z[i]-min_height);
  }
  return capacity;
}

int main(int argc, char** argv) {
  vector<int> z = { 10, 11, 0, 9, 2, 5, 7, 22, 3,1,9};
  dump(z);
  cout << capacity(z) << endl;
}
