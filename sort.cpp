#include "sort.hpp"
using namespace std;
BubbleSort::BubbleSort() { };

void BubbleSort::sort(Container * container) {
  int size = container->size();
  int i, j, temp1, temp2;
  for (i = 0; i < size; i++) {
    for (j = 0; j < size - 1; j++) {
      if (container->at(j)->evaluate() > container->at(j + 1)->evaluate()) {
        container->swap(j, j + 1);
      }
    }
    // cout << endl;
  }
}

SelectionSort::SelectionSort() { };

void SelectionSort::sort(Container* container) {
  int size = container->size();
  int i, j, index_of_min;
  for (i = 0; i < size; i++) {
    index_of_min = i;
    for (j = i + 1; j < size; j++) {
      if (container->at(j)->evaluate() < container->at(index_of_min)->evaluate()) {
        index_of_min = j;
      }
    }
    container->swap(index_of_min, i);
  }
}
