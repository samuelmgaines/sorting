#include <iostream>
#include <fstream>
#include <random>

using namespace std;

int main(int argc, char **argv) {

    // check for usage error
    if (argc != 2) {
        cout << "Usage: ./random-list.exe filename";
        return 0;
    }

    // open file
    string filename = argv[1];
    ofstream outputFile;
    outputFile.open(filename);

    // prompt for number of elements and range
    int n, r;
    cout << "Number of elements: ";
    cin >> n;
    cout << "Range (maximum possible element): ";
    cin >> r;

    // write to file
    srand(time(NULL));
    outputFile << n << ' ' << r << endl;
    for (int i = 0; i < n; i++) {
        outputFile << rand() % (r+1) << ' ';
    }
    outputFile << endl;

    // confirm
    cout << "Random list written to " << argv[1] << endl;
    return 0;
}