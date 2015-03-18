#include <iostream>

using namespace std;

struct list_node {
  int val;
  list_node *next;
};

// head -> a -> b -> c -> d -> e -> nullptr

list_node* reverse_list(list_node *head) {
  list_node *prev = nullptr;

  //                          p    h
  // n <- a <- b <- c <- d <- e -> nullptr
  //
  while (head != nullptr) {
    list_node *temp = head->next;
    head->next = prev;
    prev = head;
    head = temp;
  }
  return prev;
}

void dump(list_node *x) {
  while (x != nullptr) {
    cout << x->val << " ";
    x = x->next;
  }
  cout << endl;
}

int main(int argc, char** argv) {

  list_node *xa = new list_node({5,nullptr});
  list_node *xb = new list_node({4,xa});
  list_node *xc = new list_node({3,xb});
  list_node *xd = new list_node({2,xc});
  list_node *xe = new list_node({1,xd});

  dump(xe);
  xe = reverse_list(xe);
  dump(xe);
  return 0;
}
