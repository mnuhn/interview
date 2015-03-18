#include<vector>
#include<random>
#include<algorithm>
#include<iostream>

std::default_random_engine gen(time(0));

int partition(std::vector<int> &v, size_t left, size_t right, size_t pivot) {
  std::swap(v[pivot], v[right]);
  size_t store_index = left;

  for (size_t i = left; i<right;++i) {
    if (v[i] <= v[right]) {
      std::swap(v[store_index], v[i]);
      store_index++;
    }
  }
  std::swap(v[right], v[store_index]);
  return store_index;
}

void dump(std::vector<int> &v) {
  for (auto x : v) {
    std::cout << x << ",";
  }
  std::cout << std::endl;
}

int main(int argc, char** argv) {

  std::vector<int> v = {1,2,3,4,5,6,7,8,9,10,11,14,22,44,55,66,77,2,1,4,5,3,2,1};

  size_t left = 0;
  size_t right = v.size() - 1;
  size_t pivot = 0;
  {
    std::uniform_int_distribution<size_t> pivot_dist(left, right);
    pivot = pivot_dist(gen);
  }
  size_t k = 6;

  while(true) {
    dump(v);
    int store_index = partition(v, left, right, pivot);
    std::cout << "left=" << left << " right=" << right << " pivot=" << pivot << " value " << v[pivot] << std::endl;

    if (k<store_index) {
      right = store_index;
      std::uniform_int_distribution<size_t> pivot_dist(left, right);
      pivot = pivot_dist(gen);
    } else if (k>store_index) {
      left = store_index;
      std::uniform_int_distribution<size_t> pivot_dist(left, right);
      pivot = pivot_dist(gen);
    } else {
      break;
    }
  }

  return 0;
}
