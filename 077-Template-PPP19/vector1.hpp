#include <initializer_list>
#include <algorithm>

struct Range_error : std::out_of_range {   // enhanced vector range error reporting
    int index;
    Range_error(int i) :out_of_range{"Range error"}, index(i) { }
};

template <typename T, typename A = std::allocator<T>>
class vector1 {
    int sz;       // the size
    T* elem; // a pointer to the elements
    int space;  

public:
    vector1(int s) : sz{s}, elem{new T[s]}, space{0} { /* constructor */ }

    vector1(std::initializer_list<T> lst) : sz{int(lst.size())}, elem{new T[sz]},space{0} {
        std::copy(lst.begin(), lst.end(), elem);
    }

    vector1(const vector1& arg) : sz{arg.sz}, elem{new T[arg.sz]},space{0} {
        std::copy(arg.elem, arg.elem + arg.sz, elem);
    }

    vector1() :sz{0}, elem{nullptr}, space{0} { }

    void reserve(int newalloc)
    {
        if(newalloc<=space){ 
            return; 
        }                   // never decrease allocation
        T* p = new T[newalloc];      // allocate new space
        for (int i=0; i<sz; ++i) 
        {
            p[i] = elem[i];
        }      // copy old elements
        delete[] elem;                                              // deallocate old space
        elem = p;
        space = newalloc;
    }
    int capacity() const { return space; }

    void resize(int newsize)
        // make the vector have newsize elements
        // initialize each new element with the default value 0.0
    {
        reserve(newsize);
        for (int i=sz; i<newsize; ++i) elem[i] = 0;          // initialize new elements
        sz = newsize;
    }

    void push_back(T d)
          // increase vector size by one; initialize the new element with d
    {
        if (space==0){
            reserve(8); 
        }                 // start with space for 8 elements
        else if (sz==space){
            reserve(2*space);
        }   // get more space
        elem[sz] = d;                      // add d at end
        ++sz;   // increase the size (sz is the number of elements)
    }

    vector1& operator=(const vector1& a)
    {
          if (this==&a) return *this;      // self-assignment, no work needed

          if (a.sz<=space) {                     // enough space, no need for new allocation
                    for (int i = 0; i<a.sz; ++i) elem[i] = a.elem[i];        // copy elements
                    sz = a.sz;
                    return *this;
        }

          T* p = new T[a.sz];                         // allocate new space
          for (int i = 0; i<a.sz; ++i) p[i] = a.elem[i];        // copy elements
          delete[] elem;                                    // deallocate old space
          space = sz = a.sz;                             // set new size
          elem = p;                                           // set new elements
          return *this;                                      // return a self-reference
    }


    ~vector1() { delete[] elem; } // destructor

    int size() const { return sz; } 

    T get(int n) const { return elem[n]; } 
    void set(int n, T v) { elem[n] = v; }  

    T& operator[](size_t i){
        if (int(i)<0|| sz<=int(i)) throw Range_error{int(i)};
        return elem[int(i)];
    }
    

/*template<typename T, typename A> T& vector<T,A>::operator[](int n)
{
    return elem[n];
}*/

};