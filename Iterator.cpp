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
  if (root == nullptr || root == self_ptr->get_right()) {
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
  if (root == nullptr || root == self_ptr->get_left()) {
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
       if (stackerino.empty() == true) {
         while (stackerino.top() != NULL) {
           stackerino.pop();
         }
      } //TODO PLEASE FINISH
      // Create an iterator for the Base* that was passed into the PreorderIterator constructor.
      // Initialize that iterator and push it onto the stack.
      Iterator * temp = self_ptr->create_iterator();
      temp->first();
      stackerino.push(temp);
  }

  void PreorderIterator::next() {
      // Create an iterator for the current() of the iterator on the top of the stack
      // Initialize the iterator and push it onto the stack. As long as the top iterator
      // on the stack is_done, pop it off the stack and then advance whatever iterator is
      // now on top of the stack

      // Iterator *temp = s.top()->current()->create_iterator();
      //   temp->first();
      //   s.push(temp);
      //
      //   while(s.top()->is_done()){
    	// s.pop();
    	// if(s.size() == 0)
    	//     break;
      //
    	// s.top()->next();
      //   }

      Iterator *temp = stackerino.top()->current()->create_iterator();
      temp->first();
      stackerino.push(temp);
      while(stackerino.top()->is_done()) {
        stackerino.pop();
        if(stackerino.size() == 0)
        break;
        stackerino.top()->next();
      }

      //
      // root = current();
      //
      // Iterator * temp = stackerino.top()->current()->create_iterator();
      // stackerino.push(temp);
      //
      // while (is_done() == false) {
      //   stackerino.pop();
      //   root = current();
      // }
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
      // Return the current for the top iterator in the stack
      return stackerino.top()->current();
  }
