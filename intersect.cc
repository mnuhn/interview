#include <vector>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {

  vector<int> a = { 1,2,5,7,10,15,16,100,200 };
  vector<int> b = { 4,6,7,8,10,13,14,15,200 };


  size_t a_idx = 0;
  size_t b_idx = 0;

  while (a_idx < a.size() && b_idx < b.size()) {
    if (a[a_idx] == b[b_idx]) {
      cout << a[a_idx] << endl;
      a_idx++;
      b_idx++;
    } else if (a[a_idx] < b[b_idx]) {
      a_idx++;
    } else {
      b_idx++;
    }
  }

  return 0;
}
