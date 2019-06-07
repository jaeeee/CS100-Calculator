#ifndef __BASE_HPP__
#define __BASE_HPP__

#include <cmath>
#include <string>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>
#include "Iterator.hpp"

class Iterator;
// class NullIterator;
// class UnaryIterator;
// class BinaryIterator;

using namespace std;


class Base {
    public:
        /* Constructors */
        Base() { };
        /* Pure Virtual Functions */
        virtual double evaluate() = 0;
        virtual std::string stringify() = 0;
        virtual Base* get_left() = 0;
        virtual Base* get_right() = 0;
        virtual Iterator* create_iterator() = 0;
};

class Op : public Base {
public:
  double value;

  double evaluate() {
    return value;
  }

  Op(double bruh) {
    value = bruh;
    // cout << "THIS OP SHOULD HAVE" << value << endl;
  }

  Op() {
    value = 0;
  }

  Base* get_left() {
    return nullptr;
  }

  Base* get_right() {
    return nullptr;
  }

  string stringify() {
    return to_string(value);
  }

  Iterator* create_iterator() {
    Iterator* it = new NullIterator(this);
    return it;
  }
};

class Rand : public Base {

public:
  double value;

  Rand() {
    //seed
    srand(time(0));
    value = rand() % 100;
  }

  double evaluate() {
    return value;
  }

  string stringify() {
    return to_string(value);
  }

  Base* get_left() {
    return nullptr;
  }

  Base* get_right() {
    return nullptr;
  }

  Iterator* create_iterator() {
    Iterator* it = new NullIterator(this);
    return it;
  }
};

class Mult : public Base {
public:
    Base* left_child;
    Base* right_child;

    string final;

    Mult(Base* left, Base* right) {
        left_child = left;
        right_child = right;
    }
    double evaluate() {
        return left_child->evaluate() * right_child->evaluate();
    }
    string stringify() {
        final = left_child->stringify() + " * " + right_child->stringify();
        return final;
    }

    Base* get_left() {
      return left_child;
    }

    Base* get_right() {
      return right_child;
    }

    Iterator* create_iterator() {
      Iterator* it = new BinaryIterator(this);
      return it;
    }
};

class Div : public Base {
public:
    Base* right_child;
    Base* left_child;
    string final;

    Div(Base* left, Base* right) {
      right_child = right;
      left_child = left;
    }

    double evaluate() {
      return (left_child->evaluate() / right_child->evaluate());
    }

    string stringify() {
      final = left_child->stringify() + " / " + right_child->stringify();
      return final;
    }

    Base* get_left() {
      return left_child;
    }

    Base* get_right() {
      return right_child;
    }

    Iterator* create_iterator() {
      return new BinaryIterator(this);
    }
};


class Add : public Base {
public:
  Base *left_child;
  Base *right_child;

  string final;

  Add(Base* left, Base* right) { //constructs tree
    left_child = left;
    right_child = right;
  }

  double evaluate() {
    return left_child->evaluate() + right_child->evaluate();
  }

  string stringify() {
    final = right_child->stringify() + " + " + left_child->stringify();
    return final;
  }

  Base* get_left() {
    return left_child;
  }

  Base* get_right() {
    return right_child;
  }

  Iterator* create_iterator() {
    return new BinaryIterator(this);
  }
};

class Sub : public Base {
public:
  Base *left_child;
  Base *right_child;
  string final;

  Sub(Base *left, Base *right) {
    left_child = left;
    right_child = right;
  }

  double evaluate() {
    return left_child->evaluate() - right_child->evaluate();
  }

  string stringify() {
    final = left_child->stringify() + " - " + right_child->stringify();
    return final;
  }

  Base* get_left() {
    return left_child;
  }

  Base* get_right() {
    return right_child;
  }

  Iterator* create_iterator() {
    return new BinaryIterator(this);
  }
};

class Pow : public Base {
public:
  Base *left_child;
  Base *right_child;

  string final;

  Pow(Base *left, Base * right) {
    left_child = left;
    right_child = right;
  }

  double evaluate() {
    return pow(left_child->evaluate(), right_child->evaluate());
  }

  string stringify() {
    final = left_child->stringify() + "^(" + right_child->stringify() + ")";
    return final;
  }

  Base* get_left() {
    return left_child;
  }

  Base* get_right() {
    return right_child;
  }

  Iterator* create_iterator() {
    return new BinaryIterator(this);
  }
};

class Trunc : public Base {
private:
  double val;
  Base* ptr;

public:

  Trunc(Base* temp) {
    this->ptr = temp;
  }

  double evaluate() {
    return ptr->evaluate();
  }

  string stringify() {
    val = ptr->evaluate();
    return to_string(val);
  }

  Base* get_left() {
    return ptr;
  }

  Base* get_right() {
    return nullptr;
  }

  Iterator* create_iterator() {
    return new UnaryIterator(this);
  }

};

class Paren : public Base {
private:
  double val;
  Base* ptr;
public:

  Paren(Base* temp) {
    this->ptr = temp;
  }

  double evaluate() {
    return ptr->evaluate();
  }

  string stringify() {
    return "(" + this->ptr->stringify() + ")";
  }

  Base* get_left() {
    return ptr;
  }

  Base* get_right() {
    return nullptr;
  }

  Iterator* create_iterator() {
    return new UnaryIterator(this);
  }

};

class Ceil : public Base {
public:
  double val;
  Base* ptr;

  Ceil(Base *ptr) {
    this->ptr = ptr;
  }

  double evaluate() {
    val = ptr->evaluate();
    return ceil(val);
  }

  string stringify() {
    //val = ptr->evaluate();
    //return to_string(ceil(val)); //might cause compile issue but try this
    return ptr->stringify();
  }

  Base* get_left() {
    return ptr;
  }

  Base* get_right() {
    return nullptr;
  }

  Iterator* create_iterator() {
    return new UnaryIterator(this);
  }
};

class Floor : public Base {
public:
  double val;
  Base* ptr;

  Floor(Base *ptr) {
    this->ptr = ptr;
  }

  double evaluate() {
    val = ptr->evaluate();
    return floor(val);
  }

  string stringify() {
    // val = ptr->evaluate();
    // return to_string(floor(val)); //might cause compile issue but try this
    return ptr->stringify();
  }

  Base* get_left() {
    return ptr;
  }

  Base* get_right() {
    return nullptr;
  }

  Iterator* create_iterator() {
    return new UnaryIterator(this);
  }

};

class Abs : public Base {
public:
  double val;
  Base* ptr;

  Abs(Base *ptr) {
    this->ptr = ptr;
  }

  double evaluate() {
    val = ptr->evaluate();
    return abs(val);
  }

  string stringify() {
    //val = ptr->evaluate();
    return "|" + ptr->stringify() + "|"; //might cause compile issue but try this
  }

  Base* get_left() {
    return ptr;
  }

  Base* get_right() {
    return nullptr;
  }

  Iterator* create_iterator() {
    return new UnaryIterator(this);
  }
};

class PrecisionOp : public Op {
        public:
                int numPlaces;
                double number;

                PrecisionOp(int a, double value) {
                  numPlaces = a;
                  Op::value = value;
                }

                string stringify(){
                        stringstream ss;
                        ss << fixed << setprecision(numPlaces) << Op::value;
                        return ss.str();
                }
};

class PrecisionRand : public Rand{
        public:
                int numPlaces;

                PrecisionRand(int a) {
                  numPlaces = a;
                }

                string stringify(){
                        stringstream ss;
                        ss << fixed << setprecision(numPlaces) << Rand::value;
                        return ss.str();
                }
};

class SciOp : public Op{
        public:
                int numPlaces;

                SciOp(int a, double x) {
                  numPlaces = a;
                  Op::value = x;
                }

                string stringify() {
                        stringstream ss;
                        ss << fixed << setprecision(numPlaces) << scientific <<Op::value;
                        return ss.str();
                }

};

class SciRand : public Rand{
        public:
                int numPlaces;


                SciRand(int a) {
                  numPlaces = a;
                }

                string stringify() {
                        stringstream ss;
                        ss << fixed << setprecision(numPlaces) << scientific <<Rand::value;
                        return ss.str();
                }


};

#endif //__BASE_HPP__
