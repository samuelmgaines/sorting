#include <iostream>
#include <vector>
#include "selection-sort.h"
#include "swap.h"
using namespace std;

int getMinIndex(vector<int> *nums, int start) {
    int minIndex = start;
    for (int i = start+1; i < nums->size(); i++) {
        if (nums->at(i) < nums->at(minIndex)) minIndex = i;
    }
    return minIndex;
}

void selectionSort(vector<int> *nums, int n) {
    for (int i = 0; i < n; i++) swap(nums, getMinIndex(nums, i), i);
    return;
}