#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include "parse.hpp"
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

Asset* ParseCSV(string filename, int& num) { 
    //handle input into asset class format
    ifstream file(filename.c_str());
    vector<string> assetNames;
    string line;
    if(getline(file, line)) { //Read headerline
        assetNames = split(line, ',');
        for(size_t i=0;i<assetNames.size();i++) {
            if(assetNames[i] == "null"){ //check if index has null
                cerr<<"first line has non-numeric";
   	            exit(EXIT_FAILURE);
            }
        }
    }
    else {
        cerr << "Error: Empty file\n";
        exit(EXIT_FAILURE);
    }
    if(assetNames.size()<=1) {
        cerr << "Error: Empty header\n";
        exit(EXIT_FAILURE);
    }


    num=int(assetNames.size()-1); //ignore the first "time" index
    Asset* asset=new Asset[num];
    vector<double> previousValue(int(assetNames.size()), -1.0); //use to store previous valid value: -1.0 = no valid value existed

    for(size_t i=0;i<assetNames.size()-1;i++)
    {
        asset[i].SetName(assetNames[i+1]);
    }
    while (getline(file, line)) { //read one line at once
        vector<string> fields = split(line, ',');
        if (fields.size() != assetNames.size()) { 
            cerr << "Error: Mismatched number of fields in line\n";
            exit(EXIT_FAILURE);
        }
        for (size_t i=1;i<fields.size();i++) { // start from 1 - the assets
            double price= atof(fields[i].c_str()); // Convert string to double
            if(fields[i]=="null") {
                if(previousValue[i]==-1.0) {
                    cerr << "Error: Invalid initial price data\n";
                    exit(EXIT_FAILURE);
                }
                price = previousValue[i];
            }
            previousValue[i]=price; //update previous value to current value 
            
            vector<double> temp=asset[i-1].GetTimeSeriesReturn(); 
            temp.push_back(price);
            asset[i-1].SetTimeSeriesReturn(temp);
        }

    }
    //construct every asset's Time Series Return with return data
    for(int i=0;i<num;i++) {
        vector<double> temp=asset[i].GetTimeSeriesReturn();
        vector<double> cur;
        for(size_t j=1;j<temp.size();j++) {
            cur.push_back(temp[j]/temp[j-1]-1);
        }
        asset[i].SetTimeSeriesReturn(cur);
    }
    return asset;
}
