#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

string hash_string(string s) {
  sort(s.begin(), s.end());
  return s;
}


int main(int argc, char** argv) {
  vector<string> v = {"hallo", "wie", "geht", "es", "dir", "ein", "nie", "malte", "etlam", "tolle", "ollet", "not", "ton", "ten", "net", "internet", "netinter"};
  map<string, vector<string>> groups;


  for (string s : v) {
    groups[hash_string(s)].push_back(s);
  }

  for (auto s : groups) {
    cout << "group " << s.first << ": ";
    for (string ss : s.second) {
      cout << ss << " ";
    }
    cout << endl;
  }

}
