#include <iostream>
#include <vector>
#include "merge-sort.h"
using namespace std;

void merge(vector<int> *nums, int f, int m, int l) {
    int p1 = f;
    int p2 = m;
    vector<int> temp;
    while (p1 < m && p2 < l) {
        if (nums->at(p1) < nums->at(p2)) {
            temp.push_back(nums->at(p1));
            p1++;
        }
        else{
            temp.push_back(nums->at(p2));
            p2++;
        }
    }
    while (p1 < m) {
        temp.push_back(nums->at(p1));
        p1++;
    }
    while (p2 < l) {
        temp.push_back(nums->at(p2));
        p2++;
    }
    for (int i = 0; i < temp.size(); i++) {
        nums->at(f+i) = temp.at(i);
    }
    return;
}

void mergeSort(vector<int> *nums, int f, int l) {
    // IN PROGRESS
    int m  = (f+l)/2;
    if (f < l-1) {
        mergeSort(nums, f, m);
        mergeSort(nums, m, l);
    }
    merge(nums, f, m, l);
    return;
}