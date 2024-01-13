#ifndef __SOLVER_HPP__
#define __SOLVER_HPP__
#include <iostream>
#include <string>
#include <vector>
#include<set>
using namespace std;

vector<vector<int>> FillPuzzle(vector<vector<int>> puzzle,vector<int> colSums, vector<int> rowSums);
void SolvePuzzle(vector<vector<int>> puzzle,vector<int> colSums, vector<int> rowSums);

#endif
