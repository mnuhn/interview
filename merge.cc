#include <iostream>
#include <algorithm>

using namespace std;

template<typename T> struct list_node {
  T val;
  list_node<T>* next;
};

template<typename T> list_node<T>* add(list_node<T> *head, T val) {

  if (head == nullptr) {
    return new list_node<T>({val, nullptr});
  }

  list_node<T> *walk = head;

  while (walk->next != nullptr) {
    walk = walk->next;
  }

  walk->next = new list_node<T>({val, nullptr});
  return head;
}

template<typename T> void print_list(list_node<T> *head) {
  while (head != nullptr) {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
}

template<typename T> list_node<T>* merge_lists(list_node<T> *a, list_node<T> *b) {
  list_node<T>* head = nullptr;

  if (a == nullptr) return b;
  if (b == nullptr) return a;

  while (true) {
    // swap a and b such that we always merge into a
    if (a == nullptr || b == nullptr) {
      break;
    }

    if (a->val > b->val) swap(a,b);
    if (head == nullptr) head = a;

    print_list(head);

    // fast forward until we find the position in which we want to merge
    auto a_prev = a;
    while(a != nullptr && a->val < b->val) {
      a_prev = a;
      a = a->next;
    }

    // a_prev points to entry after which b should come
    // merge into list, redifine a and b

    auto a_prev_next = b;
    auto b_new = b->next;
    auto a_new = b;
    auto a_next = a_prev->next;

    a_prev->next = a_prev_next;
    b = b_new;
    a = a_new;
    a->next = a_next;

  }

  return head;
}

int main(int argc, char** argv) {
  list_node<int> *x, *y = nullptr;
  list_node<int> *empty = nullptr;

  for (int i=0;i<10;++i) {
    x = add(x, 5*i);
    y = add(y, i*i);
  }

  print_list(x);
  print_list(y);

  print_list(merge_lists(x,y));
  print_list(merge_lists(x,empty));
  print_list(merge_lists(empty,empty));

  return 0;
}
