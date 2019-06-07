#ifndef __COMMAND_HPP__
#define __COMMAND_HPP__

#include "base.hpp"
#include "base_factory.hpp"

class Command {
    protected:
        Base* root;

    public:
        Command() { this->root = nullptr; }
        double execute() { return root->evaluate(); }
        std::string stringify() { return root->stringify(); }
        Base* get_root() { return root; }
};
// InitialCommand
// AddCommand
// SubCommand
// MultCommand
// DivCommand
// PowCommand
class InitialCommand : public Command {
public:
  InitialCommand(Base *val) {
    root = val;
  }
};

class AddCommand : public Command {
public:
  AddCommand(Command *left, Base *val) {
    root = new Add(left->get_root(), val);
  }
};

class SubCommand : public Command {
public:
  SubCommand(Command *left, Base *val) {
    root = new Sub(left->get_root(), val);
  }
};

class MultCommand : public Command {
public:
  MultCommand(Command *left, Base *val) {
    root = new Mult(left->get_root(), val);
  }
};

class DivCommand : public Command {
public:
  DivCommand(Command *left, Base *val) {
    root = new Div(left->get_root(), val);
  }
};

class PowCommand : public Command {
public:
  PowCommand(Command *left, Base *val) {
    root = new Pow(left->get_root(), val);
  }
};
#endif
