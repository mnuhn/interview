#include <queue>
#include <random>
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

default_random_engine eng(time(0));

int main(int argc, char** argv) {

  auto comp = [](int a, int b) { return a<b; };

  priority_queue<int, vector<int>, decltype(comp)> q(comp);

  uniform_int_distribution<int> dist(0, 1000);

  size_t k = 10;

  for (size_t i=0; i<100; ++i) {
    q.push(dist(eng));
    if (q.size() > k) {
      q.pop();
    }
  }

  while(q.size() > 0) {
    cout << q.top() << endl;
    q.pop();
  }

}
