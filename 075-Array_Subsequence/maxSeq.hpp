/**
    Finds the maximum length of an increasing contiguous subsequence
    in a built-in array. The subsequence just needs to be increasing, 
    not necessarily increasing by any particular pattern or rate.

    If array is undefined(i.e., equals nullptr), returns 0

    \param array pointer to the start of an int array
    \param n size of the array
    \return the length of the maximum increasing contiguous subsequence
 */

#ifndef MAX_SEQ_HPP
#define MAX_SEQ_HPP

#include <cstddef>

size_t maxSeq(int *array, size_t n);

#endif