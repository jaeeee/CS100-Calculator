#include "container.hpp"
#include <iostream>
#include "sort.hpp"

using namespace std;

VectorContainer::VectorContainer() { }

VectorContainer::VectorContainer(vector <Base*> temp) {
  VList = temp;
}

void VectorContainer::add_element(Base * element) {
  VList.push_back(element);
}

void VectorContainer::print () {
  for (int i  = 0; i < VList.size(); i++) {
    cout << VList.at(i)->stringify() << endl;
  }
}

// void sort() {
//   if (sort_function == nullptr) {
//     throw overflow_error ("Sort_function has not selected a sort method. \n");
//   }
//   else {
//     Container * temp = new VectorContainer(VList);
//     // Sort::sort(temp);
//     temp->sort();
//   }
// }
void VectorContainer::sort()
  {
    try
    {
      if(!sort_function){
      throw invalid_argument("Still set to a NULL value");
    }
      //Container *temp = new VectorContainer(VList);
      // sort_function->sort(this);
      sort_function->sort(this);
    }
    catch(exception& e)
    {
      cout << e.what() << endl;
    }
  }

void VectorContainer::swap(int i, int j) {
  Base * temp = VList.at(i);
  VList.at(i) = VList.at(j);
  VList.at(j) = temp;
}

Base* VectorContainer::at(int i) {
  return VList.at(i);
}

int VectorContainer::size() {
  return VList.size();
}

ListContainer::ListContainer() { }

ListContainer::ListContainer(list <Base*> temp) {
  LList = temp;
}

void ListContainer::add_element(Base * element) {
  LList.push_back(element);
}

void ListContainer::print () {
  for (list <Base *>::iterator it = LList.begin(); it != LList.end(); it++) {
    Base * temp = *it;
    cout << temp->stringify() << endl;
  }
}

// void sort() {
//   if (sort_function == nullptr) {
//     throw overflow_error ("Sort_function has not selected a sort method. \n");
//   }
//   else {
//     Container * temp = new ListContainer(LList);
//     temp -> sort();
//   }
// }
void ListContainer::sort()
  {
    try
    {
      if(!sort_function){
      throw invalid_argument("Still set to a NULL value");}
      // Container *temp = new VectorContainer(VList);
      // sort_function->sort(this);
  sort_function->sort(this);
    }
    catch(exception& e)
    {
      cout << e.what() << endl;
    }
  }

void ListContainer::swap(int i, int j) {
  list<Base *>::iterator it = LList.begin();
  list<Base *>::iterator itt = LList.begin();
  Base * temp;

  for (int k = 0; k < i; k++) {
    it++;
  }
  for (int l = 0; l < j; l++) {
    itt++;
  }
  temp = *it;
  *it = *itt;
  *itt = temp;
}

Base* ListContainer::at(int i) {
  list<Base *>::iterator it = LList.begin();
  for (int j = 0; j < i; j++) {
    it++;
  }
  return *it;
}

int ListContainer::size() {
  return LList.size();
}
