#include <iostream>
#include "maxSeq.hpp"

using namespace std;

int main() {
    int a[] = {1, 2, 1, 3, 5, 8, 2, 4, 6, 9};
    size_t length = maxSeq(a, sizeof(a) / sizeof(a[0]));
    cout << "Maximum length of an increasing contiguous subsequence: " << length << std::endl;
    return 0;
}
