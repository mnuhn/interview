#include <vector>
#include <string>
#include <iostream>

using namespace std;

int get_val(char c) {
  if (c >= '0' && c <= '9') return c - '0';
  if (c >= 'A' && c <= 'F') return 10 + c - 'A';
  return 0;
}

char make_val(int v) {
  std::vector<int> a = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
  return a[v];
}

int from_radix(string r, int base) {
  int result = 0;
  int exp = 1;
  for (int i=r.size(); i>=0; i--) {
    int val = get_val(r[i]);
    result += val * exp;
    exp *= base;
  }
  return result;
}

string to_radix(int v, int base) {
  string res = "";
  while (v) {
    res = make_val(v % base) + res;
    v /= base;
  }
  return res;
}



int main(int argc, char** argv) {

  string a = "00FF";
  string b = "";
  int base_a = 16;
  int base_b = 2;

  cout << from_radix(a, 16) << endl;
  cout << to_radix(1024, 16) << endl;

  return 0;
}
