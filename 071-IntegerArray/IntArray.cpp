#include "IntArray.hpp"
#include <assert.h>
#include <ostream>

IntArray::IntArray(): data(NULL),numElements(0)  {}
IntArray::IntArray(int n):data(new int[n]), numElements(n) {}

IntArray::IntArray(const IntArray & rhs): data(new int[rhs.numElements]), numElements(rhs.numElements) {
    for (int i = 0; i < numElements; i++) {
    data[i] = rhs.data[i];
    }
}

IntArray::~IntArray() {
    delete[] data;
}

IntArray & IntArray::operator=(const IntArray & rhs) {
    if(this != &rhs){
    int* temp = new int[rhs.numElements];
    for(int i=0;i<rhs.numElements;i++){
        temp[i] = rhs.data[i];
    }
    delete[] data;
    numElements = rhs.numElements;
    data = temp;
    }
  return *this;
}

const int & IntArray::operator[](int index) const {
    assert((index >= 0) && (index < numElements));
    return data[index];
}

int & IntArray::operator[](int index) {
    if (index < 0 || index >= numElements) {
        throw std::out_of_range("Index out of bounds");
    }
    return data[index];
}

int IntArray::size() const {
    return numElements;
}

bool IntArray::operator==(const IntArray & rhs) const {
    if(rhs.numElements!=numElements){
        return false;
    }
    for(int i=0;i<numElements;i++){
        if(rhs.data[i]!=data[i]){
            return false;
        }
    }
    return true;
}

bool IntArray::operator!=(const IntArray & rhs) const {
    if(rhs.numElements!=numElements)
    {
        return true;
    }
    for(int i=0;i<numElements;i++){
        if(rhs.data[i]!=data[i]){
            return true;
        }
    }
    return false;
}

std::ostream & operator<<(std::ostream & s, const IntArray & rhs) {
    s << "{";
    for (int i = 0; i < rhs.size(); i++) {
        s << rhs[i];
        if (i != rhs.size() - 1) {
        s << ", ";
        }
    }
    s << "}";
    return s;
}
