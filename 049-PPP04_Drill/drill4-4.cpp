#include "std_lib_facilities.h"

int main() {

    cout << "Enter two double values separated by a space (followed by 'Enter'):\n"; //enter two double

    double val1, val2;
    while (cin >> val1 >> val2)
    {
        if (val1 < val2){
            cout << "the smaller value is: "<<val1 <<"\n";
            cout << "the larger value is: "<<val2 <<endl;
        }
        else if (val1 > val2){
            cout << "the smaller value is: "<<val2 <<"\n";
            cout << "the larger value is: "<<val1 <<endl;
        }
        else if (val1 == val2){
            cout << "the numbers are equal"<<endl;
        }
    }
    return 0;
}