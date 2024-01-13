#include <string>
#include <vector>
#include <cmath>
#include "asset.hpp"
#include <iostream>
using namespace std;
//asset conctructors
Asset::Asset(): name(), timeSeriesReturn(), averageReturn(0), standardDeviation(0) {}

Asset::Asset(string name): name(name), timeSeriesReturn(), averageReturn(0), standardDeviation(0) {}

void Asset::CalculateAverageReturn() {
    //calculate each asset's average return
    double sum=0;
    for (size_t i=0;i<timeSeriesReturn.size();i++) {
        sum+=timeSeriesReturn[i];
    }
    averageReturn=sum/timeSeriesReturn.size();
}

void Asset::CalculateStandardDeviation() { 
    //calculate each asset's standard deviation
    double sum=0;
    for (size_t i=0;i<timeSeriesReturn.size();i++) {
        sum+=(timeSeriesReturn[i] - averageReturn) * (timeSeriesReturn[i] - averageReturn);
    }
    standardDeviation = sqrt(sum/(timeSeriesReturn.size()-1));
}

//getters and setters
double Asset::GetAverageReturn() {
    return averageReturn;
}

double Asset::GetStandardDeviation() {
    return standardDeviation;
}

string Asset::GetName() {
    return name;
}

void Asset::SetAverageReturn(double averageReturn) {
    this->averageReturn=averageReturn;
}

vector<double> Asset::GetTimeSeriesReturn() {
    return timeSeriesReturn;
}

void Asset::SetTimeSeriesReturn(vector<double> timeSeriesReturn) {
    this->timeSeriesReturn=timeSeriesReturn;
}

void Asset::SetStandardDeviation(double standardDeviation) {
    this->standardDeviation=standardDeviation;
}

void Asset::SetName(string name) {
    this->name=name;
}
//calculate two assets' covariance and correlations--used to construct matrix
double Asset::CalculateCovariance(Asset& assetB) {
    double averageReturnA=averageReturn;
    double averageReturnB=assetB.averageReturn;
    

    double covariance=0;
    for (size_t i = 0; i < timeSeriesReturn.size(); ++i) {
        covariance += (timeSeriesReturn[i] - averageReturnA)*(assetB.timeSeriesReturn[i] - averageReturnB);
        
    }

    return covariance/int(timeSeriesReturn.size());

}

double Asset::CalculateCorrelation(Asset& assetB) {
    double covariance=CalculateCovariance(assetB);
    
    double correlation=covariance/(GetStandardDeviation()*assetB.GetStandardDeviation());
    return correlation;
}
