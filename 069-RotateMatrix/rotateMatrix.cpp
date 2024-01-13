#include <array>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main(int argc, char *argv[]) {

    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <input_file>" << endl;;
        return EXIT_FAILURE;
    }

    ifstream inputFile(argv[1]);

    if (!inputFile.is_open()) {
        cerr << "Unable to open input file: " << argv[1] << "\n";
        return EXIT_FAILURE;
    }
    array<array<char, 10>, 10> matrix;
    string line;
    int lineCount = 0;

    while (getline(inputFile, line)) {
        lineCount++;
        if (line.length() != 10){
        cerr << "Error: character in each line is too short or too long." << endl;
        return EXIT_FAILURE;
        }
        for (int j =0; j<10; j++)
        {
            matrix[j][lineCount-1]=line[j];
        }
    }
    if (lineCount !=10){
        cerr<<"Error: the number of line is too short or too long." << endl;
        return EXIT_FAILURE;
    }
    inputFile.close();

    for (int i = 0; i < 10; i++) {
        for (int j = 9; j >=0; j--) {
            cout << matrix[i][j];
            }
            cout << endl;
            }
    return EXIT_SUCCESS;
    return 0;
}

    