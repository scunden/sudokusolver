/************************************************************************

    File: stack.h
    Author: Steven Cunden
    Date: October 2nd, 2017

    Implementation of a stack class of a linked list of nodes. Written in class

************************************************************************/

#include "stack.h"
#include <cstdlib>
#include <cassert>


stack::stack()
{ // Initializes Null pointer
  _top = NULL;
}

stack::~stack()
{ // Empty the stack
  while (not empty())
    pop();
}

stack::stack(const stack & orig)
{ // Initializes a copy of a stack
  _top = _copy(orig._top);
}

stack & stack::operator=(const stack & rhs)
{ // Defines the operator =
  if (this != &rhs) 
    _top = _copy(rhs._top);

  return *this;
}

void stack::output(ostream & ostr) const
{ // Prints the stack
  ostr << "<";

  for(node *p = _top;p;p=p->next) {

    ostr << p->data;

    if (p->next)
      ostr << ", ";
  }
  ostr << ">";
}

void stack::push(const element & item)
{ // Push item on top of the stack
  node *born = new node;
  born->data = item;
  born->next = _top;
  _top = born;
}

void stack::pop()
{ // Removes the top item from the stack
  assert(!empty());
  node *rest = _top->next;
  delete _top;
  _top = rest;
}

stack::element stack::top() const
{ // Returns the top of the stack
  assert(!empty());
  return _top->data;
}

bool stack::empty() const
{ // Checks whether the stack is empty
  return _top==NULL;
}

stack::node * stack::_copy(node *p)
{ // Make a deep copy of linked list dominated by p.
  node *result = NULL;

  if (p != NULL) {

    result = new node;

    node *last = result;

    while (p != NULL) {

      // invariant: last points to a node ready to receive p's data.
      last->data = p->data;
      last->next = NULL;
      p = p->next;

      if (p != NULL) {
        
      	last->next = new node;
      	last = last->next;
      }
    }
  }
  return result;
}
