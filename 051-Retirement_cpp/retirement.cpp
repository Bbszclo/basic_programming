#include "std_lib_facilities.h"
#include <iomanip>
#include<iostream>

class RetireInfo {
    public:
    int months;
    double contribution;
    double rate_of_return;
};

void printLine(int current_age, double balance){
    cout << "Age " << setw(3) << (current_age/12) << " month " << setw(2) << (current_age % 12) << " you have $" << fixed << setprecision(2) << balance << "\n";
}

double updateBalance(double balance, RetireInfo info){
    return balance * (info.rate_of_return) + balance + (info.contribution);
}

void retirement (int startAge, double initial, RetireInfo working, RetireInfo retired){
    for (int i = 0; i < working.months;i++){
        int current_age = startAge + i;
        printLine(current_age, initial);
        initial = updateBalance(initial, working);
    }

    for (int j =0; j<retired.months;j++){
        int current_age = startAge + working.months+ j;
        printLine(current_age, initial);
        initial =updateBalance(initial, retired);
    }

}

int main(void){
    RetireInfo working;
    working.months = 489;
    working.contribution = 1000;
    working.rate_of_return = 0.045/12;

    RetireInfo retired;
    retired.months = 384;
    retired.contribution = -4000;
    retired.rate_of_return = 0.01/12;

    retirement (327,21345, working, retired);
    return EXIT_SUCCESS;
}