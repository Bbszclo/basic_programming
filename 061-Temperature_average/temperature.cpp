#include <iostream>
#include <cmath>
#include <fstream> //read file
#include <string>
#include <iomanip>
using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <filename>" << endl;
        return EXIT_FAILURE;
    }

    ifstream inputFile(argv[1]);
    
    if (!inputFile.is_open()) {
        cerr << "Could not open the file: " << argv[1] << endl;
        return EXIT_FAILURE;
    }
    //Minimum Temperature:    XX
    //Maximum Temperature:    XX
    // Max Temp as octal:     ooo
    // Max Temp as hex:        hh
    // Average Temperature: XX.XX
    double min=999.9;
    double max=-999.9;
    double total= 0.0;
    double average = 0.0;
    int count=0;
    string line;


    while (getline(inputFile, line)) {
        if (stod(line) < min){
            min = stod(line);
        }
        if (stod(line) > max){
            max = stod(line);
        }
        total+=stod(line);
        count++;

    }
    average = total/count;
    
    cout<<"Minimum Temperature:";
    cout<<right<<setw(6)<<min<<endl;
    cout<<"Maximum Temperature:";
    cout<<right<<setw(6)<<max<<endl;
    cout<<"Max Temp as octal:";
    cout<<right<<setw(8)<<oct<<int(max)<<endl;
    cout<<"Max Temp as hex:";
    cout<<right<<setw(10)<<hex<<int(max)<<endl;
    cout<<"Average Temperature:";
    cout<<right<<setw(6)<<setprecision(4)<<average<<endl;
    
    inputFile.close();
    return 0;
}