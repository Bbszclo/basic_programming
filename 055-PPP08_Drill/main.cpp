#include <iostream>

namespace X {
    int var;
    void print(){
        std::cout << var << std::endl;
    }
}

namespace Y {
    int var = 9;
    void print(){
        std::cout << var << std::endl;
    }
}

namespace Z {
    int var;
    void print(){
        std::cout << var << std::endl;
    }
}

int main()
{
    X::var = 7;
    X::print(); // print X’s var
    using namespace Y;
    int var = 9;
    print(); // print Y’s var
    {
        using Z::print;
        using Z::var;
        var = 11;
        print(); // print Z’s var
    }
    print();    // print Y’s var
    X::print(); // print X’s var
}