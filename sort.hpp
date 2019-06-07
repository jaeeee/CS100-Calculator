#ifndef __SORT_HPP__
#define __SORT_HPP__

#include "container.hpp"
#include "base.hpp"

using namespace std;

class Container;

class Sort {
    public:
        /* Constructors */
        Sort ()  { };

        /* Pure Virtual Functions */
        virtual void sort(Container* container) = 0;
};

class BubbleSort : public Sort {
public:
  BubbleSort();
  void sort(Container * container);
};

class SelectionSort : public Sort {
public:
  SelectionSort();
  void sort(Container* container);
};
#endif //__SORT_HPP__
