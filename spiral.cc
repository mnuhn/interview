#include <vector>
#include <iostream>

using namespace std;

void spiral(const vector<vector<int>> &v, int layer) {
  for (int i = layer; i + layer < v.size(); ++i) {
    cout << v[layer][i] << endl;
  }

  for (int i = layer+1; i + layer < v.size(); ++i) {
    cout << v[i][v.size()-layer-1] << endl;
  }

  for (int i = v.size() - layer - 2; i >= layer; --i) {
    cout << v[v.size()-layer-1][i] << endl;
  }

  for (int i=v.size()-layer-2; i>layer; --i) {
    cout << v[i][layer] << endl;
  }
}

int main(int argc, char** argv) {

  vector<vector<int>> v = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};

  for (int i=10; i<10; ++i) {
    cout << "I WILL NOT PRINT THIS" << endl;
  }

  for (int i=0; i<v.size(); ++i) {
    for (int j=0; j<v[i].size(); ++j) {
      cout << v[i][j] << " ";
    }
    cout << endl;
  }

  spiral(v,0);
  spiral(v,1);

  return 0;
}
