/************************************************************************

    File: stack.h
    Author: Steven Cunden
    Date: October 2nd, 2017

    Declaration of a stack class of a linked list of nodes. Written in class

************************************************************************/

#include <iostream>

using namespace std;

class stack {
  // DO NOT CHANGE ANYTHING about the public section of this data structure.
 public:
  typedef size_t element;

  // constructor
  stack();

  // destructor
  ~stack();

  // copy constructor
  stack(const stack & orig);

  // overloaded assignment operator
  stack & operator=(const stack & rhs);

  // output method
  void output(ostream & ostr) const;

  //empty: report true when size = 0
  bool empty() const;

  //push: puts a new item on top of stack
  void push(const element & item);

  //pop: removes top element from nonempty stack
  void pop();
  
  //top: returns a copy of the top element of a stack
  element top() const;
  
 private:
  struct node {
    element data;
    node *next;
  };

  node *_top;         // pointer to the top of the stack
  static node *_copy(node *p);  // internally used to duplicate linked list
  // internal node struct
  
};
 