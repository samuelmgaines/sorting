#include <iostream>
#include <vector>
#include "swap.h"

using namespace std;

void swap(vector<int> *nums, int n1, int n2) {
    int temp = nums->at(n2);
    nums->at(n2) = nums->at(n1);
    nums->at(n1) = temp;
    return;
}