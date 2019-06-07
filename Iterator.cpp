#include <iostream>
// #include <cstdlib>
// #include <cmath>
// #include <string>
// #include <stack>

#include "Iterator.hpp"
#include "base.hpp"

using namespace std;

/**
BINARYITERATOR IMPLEMENTATION
**/
  BinaryIterator::BinaryIterator(Base *a) {
    self_ptr = a;
    root = nullptr;
  }
  // BinaryIterator() {};

  /* Sets up the iterator to start at the beginning of traversal */
  void BinaryIterator::first() {
    root = self_ptr->get_left();
  }

  /* Move onto the next element */
  void BinaryIterator::next() {
      if (root == self_ptr->get_left()) { //default value
      root = self_ptr->get_right();
    } else {
      root = nullptr;
    }
  }

  /* Returns if you have finished iterating through all elements */
  bool BinaryIterator::is_done() {
  if (root == nullptr) {
    return true;
  } else {
    return false;
  }
}

  /* Return the element the iterator is currently at */
  Base* BinaryIterator::current() {
    return root;
  }


/**
UnaryIterator IMPLEMENATION
**/
UnaryIterator::UnaryIterator(Base *a) {
self_ptr = a;
root = nullptr;
}
    // BinaryIterator() {};

/* Sets up the iterator to start at the beginning of traversal */
void UnaryIterator::first() {
root = self_ptr->get_left();
}

/* Move onto the next element */
void UnaryIterator::next() {
root = nullptr; //cycle to nothing
}

/* Returns if you have finished iterating through all elements */
bool UnaryIterator::is_done() {
  if (root == nullptr) {
    return true;
  } else {
  return false;
  }
}

/* Return the element the iterator is currently at */
Base* UnaryIterator::current() {
  // root = self_ptr->get_left();
return root;
}

/**
NullIterator IMPLEMENATION
**/
NullIterator::NullIterator(Base *a) {
    self_ptr = a->get_left();
}

/* Sets up the iterator to start at the beginning of traversal */
void NullIterator::first() {
  return; //DO NOTHING
}

/* Move onto the next element */
void NullIterator::next() {
  return; //DO NOTHING
}

/* Returns if you have finished iterating through all elements */
bool NullIterator::is_done() {
  return true; //ALWAYS RETURN TRUE
}

/* Return the element the iterator is currently at */
Base* NullIterator::current() {
  return nullptr; //ALWAYS RETURN NULLPTR
}

/**
PreorderIterator IMPLEMENATION
TODO
**/

  PreorderIterator::PreorderIterator(Base *a) {
    self_ptr = a;
    root = nullptr;
  }

  void PreorderIterator::first() {
      // Empty the stack (just in case we had something leftover from another run).
        while (!stackerino.empty()) {
           stackerino.pop();
         }
      //TODO PLEASE FINISH
      // Create an iterator for the Base* that was passed into the PreorderIterator constructor.
      // Initialize that iterator and push it onto the stack.
      // Iterator * temp = self_ptr->create_iterator();
      // temp->first();
      itPtr = self_ptr->create_iterator();
      itPtr->first();
      stackerino.push(itPtr);
  }

  void PreorderIterator::next() {
// Create an iterator for the current() of the iterator on the top of the stack
// Initialize the iterator and push it onto the stack. As long as the top iterator
// on the stack is_done, pop it off the stack and then advance whatever iterator is
// now on top of the stack
    root = current();

    itPtr = stackerino.top()->current()->create_iterator();

    itPtr->first();

    stackerino.push(itPtr);

    while(!stackerino.empty() && stackerino.top()->is_done()) {
        stackerino.pop();
        if(!stackerino.empty()) {
          stackerino.top()->next();
        }

    }

}

  bool PreorderIterator::is_done() {
    if (stackerino.empty()) {
      return true;
    } else {
      return false;
    }
      // Return true if there are no more elements on the stack to iterate
  }

  Base* PreorderIterator::current() {
    root = stackerino.top()->current();
      // Return the current for the top iterator in the stack
      return root;
  }
