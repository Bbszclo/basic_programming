#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <set>
#include "parse.hpp"
using namespace std;
vector<vector<int>> FillPuzzle(vector<vector<int>> puzzle,vector<int> colSums, vector<int> rowSums)
{
    set<int> numbers=Init();//initialize the grid
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            numbers.erase(puzzle[i][j]);
        }
    }
    bool newFill=true;
    while(newFill)
    {
        newFill=false;
        for(int i=0;i<4;i++)
        {
            int sum=colSums[i];
            int zeroCount=0;
            int fillX;
            int fillY;
            for(int j=0;j<4;j++)
            {
                if(puzzle[j][i]==0)
                {
                    zeroCount++;
                    fillX=j;
                    fillY=i;
                }
                else
                {
                    sum-=puzzle[j][i];
                }
            }
            if(zeroCount==1)
            {
                if(numbers.find(sum)==numbers.end())
                {
                    return vector<vector<int>>();;
                }
                else
                {
                    numbers.erase(sum);
                    puzzle[fillX][fillY]=sum;
                    newFill=true;
                }
            }
        }
        for(int i=0;i<4;i++)
        {
            int sum=rowSums[i];
            int zeroCount=0;
            int fillX;
            int fillY;
            for(int j=0;j<4;j++)
            {
                if(puzzle[i][j]==0)
                {
                    zeroCount++;
                    fillX=i;
                    fillY=j;
                }
                else
                {
                    sum-=puzzle[i][j];
                }
            }
            if(zeroCount==1)
            {
                if(numbers.find(sum)==numbers.end())
                {   
                    return vector<vector<int>>();;
                }
                else
                {
                    numbers.erase(sum);
                    puzzle[fillX][fillY]=sum;
                    newFill=true;
                }
            }
        }
    }
    return puzzle;
}

void SolvePuzzle(vector<vector<int>> puzzle,vector<int> colSums, vector<int> rowSums)
{
    vector<vector<int>> prevPuzzle = puzzle;
    vector<vector<int>> newPuzzle = FillPuzzle(puzzle,colSums,rowSums);
    if(newPuzzle.empty())
    {
        return;
    }
    
    int fillX=-1;
    int fillY=-1;
    for(int i=0;i<4;i++)
    {
        int flag=0;
        for(int j=0;j<4;j++)
        {
            if(newPuzzle[i][j]==0)
            {
                fillX=i;
                fillY=j;
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            break;
        }
    }
    if(fillX== -1 && fillY==-1)
    {
        cout<<"   ";
        for(int m=0;m<4;m++){
            cout<<setw(2)<<colSums[m]<<" ";
        }
        cout<<"\n";
        for(int i=0;i<4;i++)
        {
            cout<<setw(2)<<rowSums[i]<<" ";
            for(int j=0;j<3;j++)
            {
                cout<<setw(2)<<newPuzzle[i][j]<<" ";
            }
            cout<<setw(2)<<newPuzzle[i][3]<<endl;
        }
        exit(EXIT_SUCCESS);
    }

    set<int> numbers=Init();
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            numbers.erase(newPuzzle[i][j]);
            
        }
    }
    for(int k=1;k<=16;k++)
    {
        if(numbers.find(k)!=numbers.end())
        {   
            newPuzzle[fillX][fillY]=k;
            numbers.erase(k);
            SolvePuzzle(newPuzzle,colSums,rowSums);
            numbers.insert(k);
        }
    }
}

