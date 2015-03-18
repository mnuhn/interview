#include <vector>
#include <iostream>

using namespace std;

vector<vector<char>> key_map = { {' '}, {' '}, {'A','B','C'}, {'D','E','F'}, {'G','H','I'}, {'J','K','L'}, {'M','N','O'}, {'P','Q','R','S'}, {'T','U','V'}, {'W','X','Y','Z'} };

void increase_options(vector<int> options) {

}

void print_strings(vector<int> number, vector<int> state = {}) {
  if (state.size() == 0) state.resize(number.size(), 0);

  bool last_state = false;

  // print
  for (size_t i=0; i<number.size(); ++i) cout << key_map[number[i]][state[i]];
  cout << endl;

  // increase state
  for (size_t i=0; i<number.size(); ++i) {
    state[i]++;
    if (state[i] == key_map[number[i]].size()) {
      state[i] = 0;
      if (i+1== number.size()) last_state = true;
    } else {
      break;
    }
  }

  if (!last_state) {
    print_strings(number, state);
  }
}


int main(int argc, char** argv) {
  print_strings({2,2});
}
