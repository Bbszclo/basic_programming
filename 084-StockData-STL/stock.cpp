#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include "StockData.hpp"
using namespace std;

std::ifstream openFile(std::string name) { 
    std::ifstream in(name);
    if (!in.is_open()) {
        std::cerr << "Unable to open " << name << std::endl;
        exit(EXIT_FAILURE);  // since we are in function, return would go back to main
    }
    return in;
}


int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " stockDataFile\n";
        return EXIT_FAILURE;
    }

    std::ifstream inputFile = openFile(argv[1]);

    std::vector<StockData> data;
    std::string line;
    std::vector<double> ratesOfReturn; 

    std::getline(inputFile, line);
    while (std::getline(inputFile, line)) {
        data.push_back(StockData::fromString(line));
    }

    // Insert assignment code
    /*Average Daily Return: -0.08%
    Largest Gain: 1.48% on 20231006
    Largest Loss: -2.46% on 20231026*/
    for(size_t i=1;i<data.size();i++)
    {
        StockData now=data[i];
        StockData prev=data[i-1];
        double dailyReturn= ((now.closingPrice/prev.closingPrice)-1)*100;
        ratesOfReturn.push_back(dailyReturn);
    }

    double avgReturn = std::accumulate(ratesOfReturn.begin(), ratesOfReturn.end(), 0.0) / ratesOfReturn.size();
    double maxReturn = *std::max_element(ratesOfReturn.begin(), ratesOfReturn.end());
    double minReturn = *std::min_element(ratesOfReturn.begin(), ratesOfReturn.end());

    string gainDate="";
    string lossDate="";
    for(size_t i=0;i<ratesOfReturn.size();i++)
    {
        if(ratesOfReturn[i]==maxReturn)
        {
            gainDate=data[i+1].date;
        }
        if(ratesOfReturn[i]==minReturn)
        {
            lossDate=data[i+1].date;
        }
    }

    std::cout << "Average Daily Return: " << std::fixed << std::setprecision(2) << avgReturn << "%\n";
    std::cout << "Largest Gain: " << std::fixed << std::setprecision(2) << maxReturn << "% on " << gainDate << "\n";
    std::cout << "Largest Loss: " << std::fixed << std::setprecision(2) << minReturn << "% on " << lossDate << "\n";


    return EXIT_SUCCESS;
}