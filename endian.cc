#include <vector>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
  for (int i=0;i<4000000;++i) {
    for (int j=0; j<sizeof(i)*8;++j) {
      cout << ((i >> j) & 1) << " ";
    }
    cout << endl;
  }
  return 0;
}
