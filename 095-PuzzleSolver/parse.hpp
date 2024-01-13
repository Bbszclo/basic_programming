#ifndef __PARSE_HPP__
#define __PARSE_HPP__
#include <iostream>
#include <string>
#include <vector>
#include<set>
using namespace std;

set<int> Init();
void ReadInputFile(const string& filename, vector<int>& colSums, vector<int>& rowSums, vector<vector<int>>& grid);
#endif
