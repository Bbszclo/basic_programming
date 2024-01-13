#include "IntMatrix.hpp"

IntMatrix::IntMatrix() : numRows(0), numColumns(0), rows(NULL) {}
IntMatrix::IntMatrix(int r, int c) : numRows(r), numColumns(c) {
    rows = new IntArray *[numRows];
    for (int i = 0; i < numRows; i++) {
        rows[i] = new IntArray(numColumns);
    }
}
IntMatrix::IntMatrix(const IntMatrix & rhs): numRows(rhs.numRows), numColumns(rhs.numColumns), rows(new IntArray *[numRows]) {
//A copy constructor, which makes a deep copy.
    for (int i = 0; i < numRows; i++) {
        rows[i] = new IntArray(numColumns);
        *rows[i] = *rhs.rows[i];
    }
}
IntMatrix::~IntMatrix() {
//destructor
    for (int i = 0; i < numRows; i++) {
        delete rows[i];
    }
    delete[] rows;
}

IntMatrix & IntMatrix::operator=(const IntMatrix & rhs) {
//An assignment operator, which makes a deep copy
    if (this != &rhs) {
        IntArray ** temp = new IntArray *[rhs.numRows];
        for (int i = 0; i < rhs.numRows; i++) {
            temp[i] = new IntArray(rhs.numColumns);
            *temp[i] = *rhs.rows[i];
        }
        for (int i = 0; i < numRows; i++) {
            delete rows[i];
        }
        delete[] rows;
        numRows = rhs.numRows;
        numColumns = rhs.numColumns;
        rows = temp;
    }
    return *this;
}

int IntMatrix::getRows() const {
    //Returns the number of rows
    return numRows;
}
int IntMatrix::getColumns() const {
    //Returns the number of columns
    return numColumns;
}
const IntArray & IntMatrix::operator[](int index) const {
    if (index < 0 || index >= numRows) {
        throw std::out_of_range("out of range");
    }
    return *rows[index];
}

IntArray & IntMatrix::operator[](int index) {
    if (index < 0 || index >= numRows) {
        throw std::out_of_range("out of range");
    }
    return *rows[index];
}

bool IntMatrix::operator==(const IntMatrix & rhs) const {
    if ((numRows != rhs.numRows) || (numColumns != rhs.numColumns)) {
        return false;
    }
    for (int i = 0; i < numRows; i++) {
        if (*rows[i] != *rhs.rows[i])
            return false;
    }
    return true;
}

IntMatrix IntMatrix::operator+(const IntMatrix & rhs) const {
    //validate that this and rhs have the same dimensions. 
    //If not, throw an invalid_argument exception.
    if ((numRows != rhs.numRows) || (numColumns != rhs.numColumns)) {
        throw std::invalid_argument("invalid argument");
    }

    IntMatrix ans(numRows, numColumns);
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numColumns; j++) {
            (*ans.rows[i])[j] = (*rows[i])[j] + (*rhs.rows[i])[j];
        }
    }
  return ans;
}

std::ostream & operator<<(std::ostream & s, const IntMatrix & rhs) {
    s << "[ ";
    for (int i = 0; i < rhs.getRows(); i++) {
        s << rhs[i];
        if (i != rhs.getRows() - 1) {
            s << ",\n";
        }
    }
    s << " ]";
    return s;
}
