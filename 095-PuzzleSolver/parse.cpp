#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <set>
using namespace std;

vector<string> split(string str, char splitter) {
    //split the string with splitter
    vector<string> index;
    string current="";
    for (size_t i = 0; i < str.size(); i++) {
        char ch = str[i];
        if (ch == splitter) {
            if (current!="") {
                index.push_back(current);
                current="";
            }
        } else {
            current += ch;
        }
    }
    if (current!="") { //push lost index
        index.push_back(current);
    }
    return index;
}

set<int> Init(){
    set<int> numbers;
    for(int i=1;i<=16;i++)
    {
        numbers.insert(i);
    }
    return numbers;
}

void ReadInputFile(const string& filename, vector<int>& colSums, vector<int>& rowSums, vector<vector<int>>& grid){
    //validate if the input file‘s format and number validation
    ifstream file(filename);
    if (!file.is_open()) {
        cerr<<"file cannot be opened"<<endl;
        exit(EXIT_FAILURE);
    }
    string line;
    getline(file,line);
    if(line.substr(0,13)!="column sums: ")
    {
        cerr<<"line 1 format incorrect"<<endl;
        exit(EXIT_FAILURE);
    }
    vector<string> cols = split(line.substr(13), ',');
    if (cols.size()!=4)
    {
        cerr<<"col sum number incorrect"<<endl;
        exit(EXIT_FAILURE);
    }
    for(int i=0;i<4;i++)
    {
        int sum;
        try
        {
            sum=stoi(cols[i]);
        }
        catch(...)
        {
            cerr<<"col sum number not integer"<<endl;
            exit(EXIT_FAILURE);
        } 
        
        if (sum<10||sum>58)
        {
            cerr<<"col sum number too large or small"<<endl;
            exit(EXIT_FAILURE);
        }
        colSums.push_back(sum);
    }

    getline(file,line);
    if(line.substr(0,10)!="row sums: ")
    {
        cerr<<"line 2 format incorrect"<<endl;
        exit(EXIT_FAILURE);
    }
    vector<string> rows = split(line.substr(10), ',');
    if (rows.size()!=4)
    {
        cerr<<"row sum number incorrect"<<endl;
        exit(EXIT_FAILURE);
    }
    for(int i=0;i<4;i++)
    {
        int sum;
        try
        {
            sum=stoi(rows[i]);
        }
        catch(...)
        {
            cerr<<"row sum number not integer"<<endl;
            exit(EXIT_FAILURE);
        }
        if(sum<10||sum>58)
        {
            cerr<<"row sum number too large or small"<<endl;
            exit(EXIT_FAILURE);
        }
        rowSums.push_back(sum);
    }

    getline(file, line); // read the "grid:" line
    if (line != "grid:")
    {
        cerr<<"line 3 format incorrect"<<endl;
        exit(EXIT_FAILURE);
    }

    int count=0;
    set<int> numbers=Init();
    while(getline(file,line))
    {
        count++;
        vector<string> gridRow=split(line, ',');
        if (gridRow.size()!=4)
        {
            cerr<<"gridRow number incorrect"<<endl;
            exit(EXIT_FAILURE);
        }
        vector<int> row;
        for(int i=0;i<4;i++) {
            int value;
            try
            {
                value=stoi(gridRow[i]);
            }
            catch(...)
            {
                cerr<<"grid number not integer"<<endl;
                exit(EXIT_FAILURE);
            }
            if ((value< 0||value> 16) || (value!=0 && numbers.find(value)==numbers.end()))
            {
                cerr<<"duplicate numbers"<<endl;
                exit(EXIT_FAILURE);
            }
            row.push_back(value);
            numbers.erase(value);
        }
        
        grid.push_back(row);
    }
    if(count!=4)
    {
        cerr<<"excessive or missing rows"<<endl;
        exit(EXIT_FAILURE);
    }
}
