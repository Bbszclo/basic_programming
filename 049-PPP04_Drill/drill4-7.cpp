#include "std_lib_facilities.h"

double covertToMeters(double value, string unit){
    if (unit =="cm"){
        return value /100;
    }
    else if (unit =="ft"){
        return value *12*2.54/100;
    }
    else if (unit =="in"){
        return value = value *2.54 /100;
    }
    else if (unit =="m"){
        return value;
    }
    else {
        return -1;
    }

}

int main() {

    cout << "Enter a double value followed by a space then a unit (cm,m,in,ft):\n"; //enter a double
    
    double val1;
    string unit;

    double smallest = std::numeric_limits<double>::max();
    double largest = std::numeric_limits<double>::min();

    while (cin >> val1 >> unit)
    {
        cout << val1 << unit;
        double converted = covertToMeters(val1,unit);
        if (converted < smallest){
            smallest = converted;
            cout << " smallest so far" ;
        }
        if (converted > largest){
            largest = converted;
            cout << " largest so far" ;
        }
        cout << '\n';
    }
    return 0;
}