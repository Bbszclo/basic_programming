#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <set>
#include "parse.hpp"
#include "solver.hpp"
using namespace std;




int main(int argc, char *argv[]) {
    //step 1:check valid command line argument
    if(argc != 2){
        //check invalid command line use
        cerr << "Usage: " << argv[0] << " <filename>"<<endl; 
        return EXIT_FAILURE;
    }

    string filename = argv[1];
    vector<int> colSums, rowSums; //column sum and row sum
    vector<vector<int>> grid; // the inside grid
    //step 2:check input file's correctness
    ReadInputFile(filename,colSums,rowSums,grid);
    //step 3: solve puzzle
    SolvePuzzle(grid, colSums, rowSums);
    
    cerr<<"not solvable"<<endl;
    return EXIT_FAILURE;
}

