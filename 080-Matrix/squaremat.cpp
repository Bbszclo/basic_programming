#include "Matrix.h"
#include "MatrixIO.h"
#include <cmath>

using namespace Numeric_lib;
using namespace std;

double square(double a) {
    return a * a;
}

int main() {
    int nrows=0, ncols=0;
    cin >> nrows >> ncols;

    Matrix<double, 2> input(nrows, ncols);
    Matrix<double, 2> output(nrows, ncols);

    cin >> input;

    output = Numeric_lib::apply(square, input);

    cout << nrows << " " << ncols << "\n";
    cout << output << "\n";

    return 0;
}
