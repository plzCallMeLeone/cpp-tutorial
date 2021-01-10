/*
 Simple Linked List Implementation using pointer. ver 0.0.0.1
 This Implementation might be dangerous to use because it couldn't handle error properly.
*/

#include <iostream>
using namespace std;
struct Link {
  string value;
  Link* prev;
  Link* next;
  Link(const string& v, Link* p = nullptr, Link* n = nullptr)
    : value{v}, prev{p}, next{n} { }
};


Link* insert(Link* p, Link *n)
{
  if(p == nullptr || n == nullptr) { return nullptr; }
  if(p->prev != nullptr) {
    p->prev->next = n;
  }
  p->next = n;
  n->next = p;
  return n;
}

Link* add(Link* p, Link* n)
{
  if(p == nullptr || n == nullptr) { return nullptr; }
  if(p->next != nullptr) {
    p->next->prev = n;
  }
  n->next = p->next;
  n->prev = p;
  p->next = n;
  return p;
}

Link* erase(Link* p)
{
  if(p == nullptr) { return nullptr; }
  Link* prev = p->prev;

  if(p->prev != nullptr) {
    p->prev->next = p->next;
  }
  if(p->next != nullptr) {
    p->next->prev = p->prev;
  }
  delete(p);
  return prev;
}


Link* find(Link* p, const string& s)
{
  if(p == nullptr) { return nullptr; }
  for(; p!=nullptr; p = p->next) {
    if(p->value == s) { return p; }
  }
  return nullptr;
}

int main()
{
  Link* norse_gods = new Link("Thor");
  norse_gods = add(norse_gods, new Link("Odin"));
  norse_gods = add(norse_gods, new Link("Freia"));
  for(Link* t = norse_gods; t != nullptr; t = t->next) {
    cout << t->value << '\n';
  }

  cout << "\n\n" << find(norse_gods, "Odin")->value << "\n\n";
  erase(find(norse_gods, "Odin"));

  for(Link* t = norse_gods; t != nullptr; t = t->next) {
    cout << t->value << '\n';
  }
}
