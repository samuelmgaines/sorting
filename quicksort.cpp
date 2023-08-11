#include <iostream>
#include <vector>
#include "merge-sort.h"
#include "swap.h"
using namespace std;

int partition(vector<int> *nums, int f, int l) {
    int pivot = nums->at(f);
    int pivotIndex = f;

    for (int i = f+1; i < l; i++) {
        if (nums->at(i) <= pivot) pivotIndex++;
    }
    swap(nums, f, pivotIndex);

    int i = f;
    int j = l - 1;
    while (i < pivotIndex && j > pivotIndex) {
        while (nums->at(i) <= pivot) i++;
        while (nums->at(j) > pivot) j--;
        if (i < pivotIndex && j > pivotIndex) swap(nums, i, j);
    }

    return pivotIndex;
}

void quicksort(vector<int> *nums, int f, int l) {
    if (f >= l - 1) return;
    int pivotIndex = partition(nums, f, l);
    quicksort(nums, f, pivotIndex - 1);
    quicksort(nums, pivotIndex + 1, l);
    return;
}