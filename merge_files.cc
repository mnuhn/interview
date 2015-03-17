#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <assert.h>

using namespace std;

typedef pair<int,size_t> entry;

int main(int argc, char** argv) {

  vector<std::vector<int>> vecs;
  vector<int> out;

  vecs.push_back(vector<int>({1,6,9,11,15,99}));
  vecs.push_back(vector<int>({6,3,10,15,49}));
  vecs.push_back(vector<int>({7,9,11,29}));
  vecs.push_back(vector<int>({2,11,15,99}));

  size_t total_size = 0;
  for (size_t i=0; i<vecs.size();++i) total_size += vecs[i].size();

  auto compare_func = [](entry &a, entry &b) { return a.first > b.first; };
  priority_queue<entry, vector<entry>, decltype(compare_func)> q(compare_func);
  //priority_queue<pair<int,size_t>> q;

  for (size_t i=0;i<vecs.size();++i) {
    cout << "pushing " << i << endl;
    q.push(make_pair(vecs[i][0], i));
  }

  cout << "start" << endl;

  while(q.size() > 0) {
    auto x = q.top(); q.pop();
    out.push_back(x.first);
    vecs[x.second].erase(vecs[x.second].begin());
    if (vecs[x.second].size() > 0) {
      q.push(make_pair(vecs[x.second][0], x.second));
    }
  }

  assert(out.size() == total_size);

  return 0;
}
