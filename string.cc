#include <iostream>
#include <vector>
#include <string>

#include <stdlib.h>
#include <assert.h>

using namespace std;

int str_to_int(const string& s) {
  int result = 0;
  int factor = 1;
  for (int i=s.size()-1; i>=0;--i) {
    int digit = s[i] - '0';
    result += factor * digit;
    factor *= 10;
  }
  return result;
}

string int_to_str(int i) {
  string res = "";
  while(i>0) {
    int digit = i % 10;
    res = static_cast<char>(digit + '0') + res;
    i /= 10;
  }
  return res;
}

int main(int argc, char** argv) {
  string s = "123818841";

  cerr << int_to_str(100249124) << endl;
  cerr << str_to_int("3532532") << endl;

  for (int i=0;i<100000;++i) {
    assert(str_to_int(int_to_str(i)) == i);
  }
}
