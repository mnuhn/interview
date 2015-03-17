#include <iostream>
#include <vector>

using namespace std;

size_t bin_search(const vector<int>& v, int val) {
  int result = v.size();

  int left = 0;
  int right = v.size()-1;

  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (v[mid] == val) {
      result = mid;
      right = mid - 1;
    } else if (v[mid] < val) {
      left = mid + 1;
    } else { // v[mid] >= val
      right = mid - 1;
    }
  }
  return result;
}

size_t find_first_bigger(const vector<int>& v, int val) {
  int result = v.size();

  int left = 0;
  int right = v.size()-1;

  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (v[mid] > val) {
      result = mid;
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return result;
}

int find_smallest_cyclic(const vector<int>& v) {

  int left = 0;
  int right = v.size() - 1;

  while (left < right) {
    int mid = left + (right - left) / 2;

    if (v[mid] > v[right]) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }

  return left;
}

int main(int argc, char** argv) {
  vector<int> v = {1,5,10,99,100,100,100,102,555,1023};

  cout << bin_search(v, 1) << endl;
  cout << bin_search(v, 5) << endl;
  cout << bin_search(v, 10) << endl;
  cout << bin_search(v, 99) << endl;
  cout << bin_search(v, 100) << endl;
  cout << bin_search(v, 102) << endl;
  cout << bin_search(v, 555) << endl;
  cout << bin_search(v, 1023) << endl;
  cout << bin_search(v, 0) << endl;
  cout << bin_search(v, 2) << endl;
  cout << bin_search(v, 1025) << endl;

  //
  cout << "find_first_bigger" << endl;
  //

  cout << find_first_bigger(v, 6) << endl;
  cout << find_first_bigger(v, 7) << endl;
  cout << find_first_bigger(v, 8) << endl;
  cout << find_first_bigger(v, 9) << endl;
  cout << find_first_bigger(v, 10) << endl;
  cout << find_first_bigger(v, 11) << endl;
  cout << find_first_bigger(v, 19) << endl;
  cout << find_first_bigger(v, 1023) << endl;
  cout << find_first_bigger(v, 1024) << endl;

  //
  cout << "find_smallest_value" << endl;
  //

  for (size_t i=0; i<v.size();++i) {
    v.push_back(v[0]);
    v.erase(v.begin());
    for (size_t j=0; j<v.size();++j) cout << v[j] << " ";
     cout << endl;
    cout << find_smallest_cyclic(v) << endl;
  }

}
