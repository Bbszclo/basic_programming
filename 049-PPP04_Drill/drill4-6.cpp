#include "std_lib_facilities.h"

int main() {

    cout << "Enter a double to check if it is smallest of largest (followed by 'Enter'):\n"; //enter a double

    double number;
    double smallest = std::numeric_limits<double>::max();
    double largest = std::numeric_limits<double>::min();

    while (cin >> number)
    {
        cout << number;
        if (number < smallest){
            smallest = number;
            cout << " smallest so far" ;
        }
        if (number > largest){
            largest = number;
            cout << " largest so far" ;
        }
        cout << '\n';
    }
    return 0;
}