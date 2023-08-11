#include <iostream>
#include <vector>
#include "insertion-sort.h"
#include "swap.h"
using namespace std;

void insertionSort(vector<int> *nums, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i-1; j >= 0; j--) {
            if (nums->at(j) > nums->at(j+1)) swap(nums, j, j+1);
            else break;
        }
    }
    return;
}