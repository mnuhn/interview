#include <iostream>
#include <vector>

using namespace std;

template<typename T> struct tree_node {
  T data;
  tree_node<T> *left, *right;
  tree_node<T> *parent;
};

typedef tree_node<int> tn;

void add_parents(tn *root) {
  if (root->left) {
    root->left->parent = root;
    add_parents(root->left);
  }
  if (root->right) {
    root->right->parent = root;
    add_parents(root->right);
  }
}

size_t depth(tn *root, tn *n) {
  size_t d = 0;
  while (n != root) {
    n = n->parent;
    d++;
  }
  return d;
}

tn* lca(tn *root, tn *a, tn *b) {
  size_t da = depth(root, a);
  size_t db = depth(root, b);
  if (da > db) {
    swap(da, db);
    swap(a,b);
  }
  // da < db
  while (da < db) {
    b = b->parent;
    db--;
  }

  while (a != b) {
    a = a->parent;
    b = b->parent;
  }

  return a;
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
  tn *root = fiv;
  add_parents(root);

  cout << lca(root, one, fou)->data << endl;

  return 0;
}
