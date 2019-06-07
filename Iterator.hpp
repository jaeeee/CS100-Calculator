#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <cstdlib>
#include <cmath>
#include <string>
#include <stack>
#include <iostream>
// #include "base.hpp"

class Base;

using namespace std;

class Iterator {
    protected:
        Base* self_ptr;

    public:
        Iterator(Base* ptr) { this->self_ptr = ptr; };
        Iterator() {};
        /* Sets up the iterator to start at the beginning of traversal */
        virtual void first() = 0;

        /* Move onto the next element */
        virtual void next() = 0;

        /* Returns if you have finished iterating through all elements */
        virtual bool is_done() = 0;

        /* Return the element the iterator is currently at */
        virtual Base* current() = 0;
};

/*
will be used to iterate over expression tree classes with two children.
 This means it's first will initialize to the left child,
 and its next will cycle from left child, to right child, then to nothing.
*/
class BinaryIterator : public Iterator {
public:
    Base *root;
    BinaryIterator(Base *a);
    BinaryIterator();
    void first();
    void next();
    bool is_done();
    Base* current();
  //   BinaryIterator(Base *a) {
  //     self_ptr = a->get_left();
  //     root = nullptr;
  //   }
  //   // BinaryIterator() {};
  //
  //   /* Sets up the iterator to start at the beginning of traversal */
  //   void first() {
  //     root = self_ptr->get_left();
  //   }
  //
  //   /* Move onto the next element */
  //   void next() {
  //       if (root == self_ptr->get_left()) { //default value
  //       root = self_ptr->get_right();
  //     } else {
  //       root = nullptr;
  //     }
  //   }
  //
  //   /* Returns if you have finished iterating through all elements */
  //   bool is_done() {
  //   if (root == nullptr) {
  //     return true;
  //   } else {
  //     return false;
  //   }
  // }
  //
  //   /* Return the element the iterator is currently at */
  //   Base* current() {
  //     return root;
  //   }
};

/*
will be used to iterate over expression tree classes with one child.
This means it's first will initialize to the only child,
and its next will cycle from the only child to nothing.
*/
class UnaryIterator : public Iterator {
public:

    Base *root;
    // Base *root;
    UnaryIterator(Base *a);
    UnaryIterator();
    void first();
    void next();
    bool is_done();
    Base* current();
    // UnaryIterator(Base *a) {
    // self_ptr = a->get_left();
    // root = nullptr;
    // }
    //     // BinaryIterator() {};
    //
    // /* Sets up the iterator to start at the beginning of traversal */
    // void first() {
    // root = self_ptr->get_left();
    // }
    //
    // /* Move onto the next element */
    // void next() {
    // root = nullptr; //cycle to nothing
    // }
    //
    // /* Returns if you have finished iterating through all elements */
    // bool is_done() {
    //   if (root == nullptr) {
    //     return true;
    //   } else {
    //   return false;
    // }
    // }
    //
    // /* Return the element the iterator is currently at */
    // Base* current() {
    // return root;
    // }
};

/*
will be used to iterate over expression tree classes with no children.
In this special case the is_done() function will always return true and the current()
function will always return nullptr. The first() and next() functions don't do anything.
*/
class NullIterator : public Iterator {
public:
    NullIterator();
    NullIterator(Base *a);
    void first();
    void next();
    bool is_done();
    Base* current();
    // NullIterator(Base *a) {
    //     self_ptr = a->get_left();
    // }
    //
    // /* Sets up the iterator to start at the beginning of traversal */
    // void first() {
    //   return; //DO NOTHING
    // }
    //
    // /* Move onto the next element */
    // void next() {
    //   return; //DO NOTHING
    // }
    //
    // /* Returns if you have finished iterating through all elements */
    // bool is_done() {
    //   return true; //ALWAYS RETURN TRUE
    // }
    //
    // /* Return the element the iterator is currently at */
    // Base* current() {
    //   return nullptr; //ALWAYS RETURN NULLPTR
    // }
};

class PreorderIterator : public Iterator {
public:
  stack<Iterator*> stackerino;
  Base* root;
  PreorderIterator();
  PreorderIterator(Base *a);
  // Base* curr;
  // Iterator* itPtr;
  //
  void first();
  void next();
  bool is_done();
  Base* current();
// TODO
};

#endif
