#include "std_lib_facilities.h"

int main() {

    cout << "Enter two integer values separated by a space (followed by 'Enter'):\n"; //enter two intergers

    int val1, val2;
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
        else{
            break;
        }
    }
    return 0;
}