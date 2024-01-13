#include "maxSeq.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

size_t maxSeq(int *array, size_t n) {
    size_t max = 1; 
    size_t current = 1;

    if (array == nullptr || n == 0) {
        return 0;
    }

    for (size_t i = 1; i < n; i++) {
        if (array[i] > array[i - 1]) {
            current++;
        } else {
            if (current > max) {
                max= current;
            }
            current = 1;
        }
    }
    if (current > max) {
        max = current;
    }

    return max;
}
