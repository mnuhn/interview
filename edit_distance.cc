#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int edit_distance(const string &a, const string &b) {
  vector<vector<int>> m(a.size()+1,vector<int>(b.size()+1,0));

  cout << "init" << endl;
  for (int i=0;i<=a.size();++i) m[i][0] = i;
  for (int i=0;i<=b.size();++i) m[0][i] = i;

  cout << "init ok" << endl;

  for (int i=1;i<=a.size();++i) {
    for (int j=1; j<=b.size();++j) {
      if (a[i-1] == b[j-1]) {
        m[i][j] = m[i-1][j-1];
      } else {
        m[i][j] = min(min(m[i-1][j]+1,m[i][j-1]+1),m[i-1][j-1]+1);
      }
    }
  }

  for (int i=0;i<m.size();++i) {
    for (int j=0;j<m[i].size();++j) {
      cout << m[i][j] << " ";
    }
    cout << endl;
  }

  return m[a.size()][b.size()];
}

//    . h e l l o
//  . 0 1 2 3 4 5
//  h 1 0 
//  a 2
//  l 3

int main(int argc, char** argv) {

  cout << edit_distance("kitten", "sitting") << endl;

  return 0;

}

