#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct max_stack {
  vector<int> v, m;
};

void stack_push(max_stack *s, int v) {
  size_t size = s->v.size();

  cout << "push " << v << " size=" << size << endl;
  if (size == 0) {
    s->m.push_back(v);
    s->v.push_back(v);
  } else {
    int last_max = s->m[s->m.size()-1];
    s->m.push_back(max(last_max, v));
    s->v.push_back(v);
  }
}

int stack_max(const max_stack &s) {
  return s.m[s.m.size()-1];
}

int stack_pop(max_stack *s) {
  cout << "pop" << endl;
  s->m.pop_back();
  int res = s->m[s->v.size()-1];
  s->v.pop_back();
  return res;
}

int main(int argc, char** argv) {

  max_stack s;

  stack_push(&s, 10);
  cout << stack_max(s) << endl;
  stack_push(&s, 13);
  cout << stack_max(s) << endl;
  stack_push(&s, 2);
  cout << stack_max(s) << endl;
  stack_push(&s, 4);
  cout << stack_max(s) << endl;
  stack_push(&s, 1);
  cout << stack_max(s) << endl;
  stack_push(&s, 5);
  cout << stack_max(s) << endl;

  stack_pop(&s);
  cout << stack_max(s) << endl;
  stack_pop(&s);
  cout << stack_max(s) << endl;
  stack_pop(&s);
  cout << stack_max(s) << endl;
  stack_pop(&s);
  cout << stack_max(s) << endl;
  stack_pop(&s);
  cout << stack_max(s) << endl;
  stack_pop(&s);
  cout << stack_max(s) << endl;
}
