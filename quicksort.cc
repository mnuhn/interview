#include <vector>
#include <algorithm>
#include "helpers.hh"

using namespace std;

void partition(vector<int> &v, int pivot) {
  int left = 0;
  int right = v.size() - 1;
  int p = v[pivot];

  swap(v[pivot], v[right]);
  --right;


  while (left < right) {
    if (v[left] > p) {
      swap(v[left], v[right]);
      right--;
    } else {
      left++;
    }
  }

  swap(v[left+1], v[v.size()-1]);
}

int main(int argc, char** argv) {

  vector<int> v = { 58, 1, 55, 23, 53, 51 };
  dump(v);
  partition(v, 3);
  dump(v);

  return 0;
}
