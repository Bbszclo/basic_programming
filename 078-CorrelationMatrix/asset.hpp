#include <string>
#include <vector>
using namespace std;

class Asset {
private:
    string name;
    vector<double> timeSeriesReturn;
    double averageReturn;
    double standardDeviation;

public:
    Asset();
    ~Asset(){};
    
    Asset(string name);

    void CalculateAverageReturn();

    void CalculateStandardDeviation();

    double GetAverageReturn();

    double GetStandardDeviation();

    vector<double> GetTimeSeriesReturn();

    void SetTimeSeriesReturn(vector<double> timeSeriesReturn);

    string GetName();
    
    void SetName(string name);

    void SetAverageReturn(double averageReturn);

    void SetStandardDeviation(double standardDeviation);

    double CalculateCovariance(Asset& assetB);

    double CalculateCorrelation(Asset& assetB);
};
