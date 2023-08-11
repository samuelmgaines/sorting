#include <iostream>
#include <vector>
#include "bubble-sort.h"
#include "swap.h"
using namespace std;

void bubbleSort(vector<int> *nums, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (nums->at(j) > nums->at(j+1)) swap(nums, j, j+1);
        }
    }
    return;
}