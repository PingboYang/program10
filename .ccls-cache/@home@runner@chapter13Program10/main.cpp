#include <iostream>

using namespace std;

//？？floating-point
//class for floating-point numbers.
class ArrayNumber {
    int cap;
    float *dynamicallyArr;//？？

public:
    //constructor
    ArrayNumber(int a) {
        cap = a;
        dynamicallyArr = new float[cap];
    }

    //destructor
    ~ArrayNumber() {
        delete[]dynamicallyArr;
    }

    void getCap(int b) {
        cap = b;
    }

    //
    void insert(int index, float value) {
        // notes by p
        // dynamicallyArr: 指着dynamicallyArr index=0的位置
        // dynamicallyArr+index: 指针往后移动 index个位置(aka: float * index 长度)
        // *(dynamicallyArr+index) 取对应位置的变量
        // *(dynamicallyArr+index)=value 对变量赋值
        *(dynamicallyArr + index) = value;
    }

    float retrieve(int i) {
        return dynamicallyArr[i];
    }

//    void getDynamicallyArr(){
//        for (int index=0; index<cap; index++){
//            cout <<"array[" <<index <<"]:";
//            cin>>dynamicallyArr[index];
//        }
//    }
    float accessDynamicallyArr() {
        return *dynamicallyArr;
    }

    int accessCap() {
        return cap;
    }

    int highestNumber() {
        int max = dynamicallyArr[0];
        for (int index = 1; index <= cap; index++) {
            if (dynamicallyArr[index] > max) {
                max = dynamicallyArr[index];
            }
        }
        return max;

    }

    int lowestNumber() {
        int min = dynamicallyArr[0];
        for (int index = 1; index < cap; index++) {
            if (dynamicallyArr[index] < min) {
                min = dynamicallyArr[index];
            }
        }
        return min;

    }

    int average() {
        int total = 0;
        for (int index = 0; index <= cap; index++) {
            total = total + dynamicallyArr[index];
        }
        int average = total / cap;
        return average;

    }

};


int main() {
    // construct a ArrayNumber array with length of 3
    ArrayNumber A(3);

    // get 3 numbers from command line separately, and STORE(not retrieve) to the array
    float a;
    cin >> a;
    float b;
    cin >> b;
    float c;
    cin >> c;

    // demonstrate store 3 number from an element of the array:
    // side node: use insert() member function
    A.insert(0, a);
    A.insert(1, b);
    A.insert(2, c);

    // demonstrate: retrieving 3 numbers from the array:
    float x = A.retrieve(0);
    float y = A.retrieve(1);
    float z = A.retrieve(2);
    cout << x << y << z;

    //A.getDynamicallyArr();
    int max;
    int min;
    int average;

    max = A.highestNumber();
    min = A.lowestNumber();
    average = A.average();
    cout << "highestNumber is" << max << endl;
    cout << "lowestNumber is" << min << endl;
    cout << "average is" << average << endl;
    return 0;
}



