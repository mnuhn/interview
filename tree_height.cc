#include <iostream>
#include <vector>

using namespace std;

template<typename T> struct tree_node {
  T data;
  tree_node<T> *left, *right;
};

typedef tree_node<int> tn;

bool balanced(tn* t) {
  if (t == nullptr) return true;
  if (t->left != nullptr && t->right != nullptr) {
    return balanced(t->left) && balanced(t->right);
  } else if (t->left == nullptr && t->right == nullptr){
    return true;
  } else {
    return false;
  }
}

int main(int argc, char** argv) {


  //
  //            5
  //        3       9
  //      2   4   8   10
  //    1 
  //
  //

  tn *one = new tn({1, nullptr, nullptr});
  tn *two = new tn({2, one, nullptr});
  tn *fou = new tn({4, nullptr, nullptr});
  tn *thr = new tn({3, two, fou});
  tn *eig = new tn({8, nullptr, nullptr});
  tn *ten = new tn({10, nullptr, nullptr});
  tn *nin = new tn({9, eig, ten});
  tn *fiv = new tn({5, thr, nin});

  cout << balanced(two) << endl;
  cout << balanced(thr) << endl;
  cout << balanced(fiv) << endl;
  cout << balanced(nin) << endl;
  cout << balanced(one) << endl;

  return 0;
}
