#include <initializer_list>
#include <algorithm>
class vector1 {
    int sz;       // the size
    double* elem; // a pointer to the elements

public:
    vector1(int s) : sz{s}, elem{new double[s]} { /* constructor */ }

    vector1(std::initializer_list<double> lst) : sz{lst.size()}, elem{new double[sz]} {
        std::copy(lst.begin(), lst.end(), elem);
    }

    vector1(const vector1& arg) : sz{arg.sz}, elem{new double[arg.sz]} {
        std::copy(arg.elem, arg.elem + arg.sz, elem);
    }

    vector1& operator=(const vector1& a) {
        if (this == &a) {
            return *this; // Self-assignment, no need to do anything
        }

        double* p = new double[a.sz]; // allocate new space
        std::copy(a.elem, a.elem + a.sz, p); // copy elements
        delete[] elem; // deallocate old space
        elem = p; // now we can reset elem
        sz = a.sz;
        return *this; // return a self-reference
    }

    ~vector1() { delete[] elem; } // destructor

    int size() const { return sz; } 

    double get(int n) const { return elem[n]; } 
    void set(int n, double v) { elem[n] = v; }  

    double& operator[ ](int n) { return elem[n]; } 
};