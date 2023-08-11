#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <chrono>

#include "bubble-sort.h"
#include "insertion-sort.h"
#include "selection-sort.h"
#include "merge-sort.h"
#include "quicksort.h"

using namespace std;

int prompt() {
    int input;
    cout << endl << "Which sort would you like to perform?" << endl;
    cout << "0: Exit" << endl;
    cout << "1: Bubble Sort" << endl;
    cout << "2: Insertion Sort" << endl;
    cout << "3: Selection Sort" << endl;
    cout << "4: Merge Sort" << endl;
    cout << "5: Quicksort" << endl;
    cin >> input;
    if (input < 0 || input > 5) {
        cout << "Please enter a number 0 to 5" << endl;
        return prompt();
    }
    return input;
}

void printList(vector<int> nums) {
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << ' ';
    }
    cout << endl;
}

int main(int argc, char **argv) {

    // check for usage error
    if (argc != 2) {
        cout << "Usage: ./sorting.exe filename";
        return 0;
    }

    // open file
    string filename = argv[1];
    ifstream inputFile;
    inputFile.open(filename);
    if (!inputFile) {
        cout << "File " << filename << " not found";
        return 0;
    }

    // read from file
    int n, r; // number of elements and range of elements
    inputFile >> n;
    inputFile >> r;
    vector<int> nums(n, -1);
    for (int i = 0; i < n; i++) {
        inputFile >> nums[i];
    }

    // prompt for sorting algorithm
    while (1) {
        vector<int> numsCopy(nums);
        string algorithm;
        int input = prompt();

        // start timer
        auto beg = chrono::high_resolution_clock::now();

        // perform sort
        if (input == 0) {
            break;
        }
        else if (input == 1) {
            algorithm = "Bubble Sort";
            bubbleSort(&numsCopy, n);
        }
        else if (input == 2) {
            algorithm = "Insertion Sort";
            insertionSort(&numsCopy, n);
        }
        else if (input == 3) {
            algorithm = "Selection Sort";
            selectionSort(&numsCopy, n);
        }
        else if (input == 4) {
            algorithm = "Merge Sort";
            mergeSort(&numsCopy, 0, n);
        }
        else if (input == 5) {
            algorithm = "Quicksort";
            quicksort(&numsCopy, 0, n);
        }

        // end timer
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - beg);

        // print results
        if (duration.count() < 1E3) {
            cout << algorithm << " ran in " << duration.count() << " microseconds" << endl;
        }
        else if (duration.count() < 1E6) {
            cout << algorithm << " ran in " << int((duration.count()+5E2) / 1E3) << " milliseconds" << endl;
        }
        else {
            duration = chrono::duration_cast<chrono::seconds>(duration);
            cout << algorithm << " ran in " << int((duration.count()+5E5) / 1E6) << " seconds" << endl;
        }
        char yesOrNo = 'y';
        if (n > 30) {
            cout << "Would you like to see the sorted list? (y/n) ";
            cin >> yesOrNo;
        }
        if (yesOrNo == 'y' || yesOrNo == 'Y') {
            cout << endl << "The sorted list is" << endl;
            printList(numsCopy);
        }

        numsCopy.clear();
    }

    return 0;
}