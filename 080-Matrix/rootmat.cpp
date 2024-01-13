#include "MatrixIO.h"
#include <cmath>
using namespace Numeric_lib;
using namespace std;

double s(double a){ 
    return sqrt(a);
    }

int main(){
    int nrows =0, ncols = 0;
    cin>>nrows;
    cin>>ncols;
    Matrix<double,2> input(nrows,ncols);
    Matrix<double,2> output(nrows,ncols);
    cin>>input;
    output = Numeric_lib::apply (s,input);
    cout<<nrows<<" "<<ncols<<"\n";
    cout<<output<<"\n";
}
