#include <iostream>
#include <vector>
#include <list>
#include <cmath>

using namespace std;

template<typename Iter1, typename Iter2>
Iter2 copy2(Iter1 begin, Iter1 end, Iter2 iterFinal) {
    while (begin != end) {
        *iterFinal = *begin; 
        begin++;         
        iterFinal++;          
    }
    return iterFinal;         
}

void increaseArrayByTwo(int array1[], int size) {
    for (int i = 0; i < size; i++) {
        array1[i] += 2;
    }
}

void increaseVectorByThree(vector<int> &vector1) {
    for (auto &element : vector1) {
        element += 3;
    }
}
//using new learnt method from chap20:iterator
void increaseListByFive(list<int> &list1) {
    for (auto &element : list1) {
        element += 5;
    }
}

void printContents(const int array1[], size_t sizeArray, const vector<int>& vector1, const list<int>& list1) {
    cout << "array: {";
    for (size_t i = 0; i < sizeArray; i++) {
        cout << array1[i];
        if (i < sizeArray - 1) {
            cout << ", ";
        }
    }
    cout << "}\n";

    cout << "vector: {";
    for (size_t i = 0; i < vector1.size(); i++) {
        cout << vector1[i];
        if (i < vector1.size() - 1) {
            cout << ", ";
        }
    }
    cout << "}\n";

    cout << "list: {";
    for (auto it = list1.begin(); it != list1.end(); it++) {
        cout << *it;
        if (next(it) != list1.end()) {
            cout << ", ";
        }
    }
    cout << "}\n";
}

int main(){
    //3 to initialize the define and initialize the containers
    //builtin array
    int array1[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int s = sizeof(array1) / sizeof(array1[0]);
    //vector
    vector<int> vector1 = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    //list
    list<int> list1 = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    //3 to call a function that increases the containers as defined above
    increaseArrayByTwo(array1, s);
    increaseVectorByThree(vector1);
    increaseListByFive(list1);

    //call copy2() as specified

    copy2(array1, array1 + s, vector1.begin());
    copy2(list1.begin(), list1.end(), array1);  
    

    //3 to call a function to print your containers
    printContents(array1, s, vector1,list1);

    //1 to return EXIT_SUCCESS
    return EXIT_SUCCESS;
}


