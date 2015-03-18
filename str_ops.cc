#include <string>
#include <iostream>

using namespace std;

string replace(string str) {

  size_t write_idx = 0;
  size_t num_b = 0;
  size_t num_a = 0;

  for (size_t i=0; i<str.size(); ++i) {
    if (str[i] == 'b') num_b++;
    if (str[i] == 'a') num_a++;
    swap(str[write_idx], str[i]);
    if (str[write_idx] != 'a') write_idx++;
  }

  size_t read_idx = str.size() - num_a;
  size_t new_size = write_idx + num_b;

  write_idx = str.size() - 1;
  str.resize(new_size, '_');

  while (read_idx > 0) {
    read_idx--;
    if (str[read_idx] == 'b') {
      str[write_idx--] = str[read_idx];
    }
    str[write_idx--] = str[read_idx];
  }

  return str;
}

// delete a
// b -> dd
int main(int argc, char** argv) {
  cout << replace("hallo wie was macht der boy denn heute bei bestem wetter am bus?") << endl;
}
