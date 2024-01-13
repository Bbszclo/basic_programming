//smallest: value
//largest:  value
//number: number
//sum: number

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
    int num_entries = 0;
    double sum = 0.0;
    vector<double> entries = {};

    double smallest = std::numeric_limits<double>::max();
    double largest = std::numeric_limits<double>::min();

    while (cin >> val1>>unit)
    {
        
        double converted = covertToMeters(val1,unit);

        if (converted ==-1){
            cout << "bad unit: "<< unit<< "\n";
        }
        else{
            cout << val1 << unit;
            if (converted < smallest){
                smallest = converted;
                cout << " smallest so far" ;
            }

            if (converted > largest){
            largest = converted;
            cout << " largest so far" ;
            }
            
            num_entries++;
            sum+= converted;
            cout << '\n';
            entries.push_back(converted);
        } 
        sort(entries);
    }
    cout << "smallest: "<< smallest << "\n";
    cout << "largest: "<< largest<< "\n" ;
    cout << "number: " << num_entries << "\n";
    cout << "sum: " << sum << "\n";
    
    for (double d:entries){
            cout << d<< "\n";
        }
    return 0;
}