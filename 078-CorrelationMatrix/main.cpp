#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include "parse.hpp"
using namespace std;

ostream& operator<<(ostream& os, vector< vector<double> >& matrix) {
    os << "[" <<fixed<<setprecision(4); //set precision to 4 digits
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            os <<setw(7)<<matrix[i][j]; //set 7 space
            if (j<matrix[i].size() - 1) {
                os << ",";
            }
        }
        if (i < matrix.size() - 1) {
            os << "\n "; //line change if not last line
        }
    }
    os << "]"<<endl;
    return os;
}

int main(int argc, char* argv[]) {
    //first step: check valid input
    if (argc != 2) {
        //check invalid command line use
        cerr << "Usage: " << argv[0] << " <filename>\n"; 
        return EXIT_FAILURE;
    }

    string filename = argv[1];
    ifstream file(filename.c_str());

    if (!file.is_open()) {
        //check invalid file
        cerr << "Error: Could not open file " << filename << "\n";
        exit(EXIT_FAILURE);
    }
    //second step: construct data into asset class
    int num=0; //number of assets
    Asset* assets=ParseCSV(filename,num); 

    //third step: construct matrix using correlation and covariance
    for(int i=0;i<num;i++) {
        assets[i].CalculateAverageReturn();
        assets[i].CalculateStandardDeviation();
    }

    vector< vector<double> > matrix(num,vector<double>(num));
    for (int i = 0; i < num; ++i) {
        for (int j = 0; j < num; ++j) {
            if(i==j) {
                matrix[i][j]=1.0;
            }
            else {
                matrix[i][j]=assets[i].CalculateCorrelation(assets[j]);
            }
        }
    }
    //last step: generate output
    for (int i = 0; i < num; i++) {
        cout<<assets[i].GetName()<<endl;
    }
    cout<<matrix;
    //destructor, release memory
    delete[] assets;
    return 0;
}
