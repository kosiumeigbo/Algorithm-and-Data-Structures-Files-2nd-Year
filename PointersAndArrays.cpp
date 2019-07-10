#include <iostream>
#define ASIZE 128
using namespace std;

int main(){

    int na[ASIZE];
    int* pna;

    na[0] = 1;
    na[1] = 2;
    na[2] = 3;

    cout << "na[0]: " << na[0] << " &na[0]: " << &na[0] << endl;
    cout << "na[1]: " << na[1] << " &na[1]: " << &na[1] << endl;
    cout << "na[2]: " << na[2] << " &na[2]: " << &na[2] << endl;

    cout << "na: " << na << endl;
    cout << "(it will be the same value as &na[0])" << endl;

    cout << endl;

    pna = na;

    *pna = 11;
    *(pna + 1) = 22;
    *(pna + 2) = 33;

    cout << "after changing the values using pna" << endl;

    cout << "na[0]: " << na[0] << ", &na[0]: " << &na[0] << ", pna: " << pna << endl;
    cout << "na[1]: " << na[1] << ", &na[1]: " << &na[1] << ", pna + 1: " << pna + 1 << endl;
    cout << "na[2]: " << na[2] << ", &na[2]: " << &na[2] << ", pna + 2: " << pna + 2 << endl;

    cout << endl;

    cout << "sizeof(int): " << sizeof(int) << endl;

    cout << endl;

    pna[0] = 4;
    pna[1] = 5;
    pna[2] = 6;

    cout << "after changing the values using pna" << endl;

    cout << "na[0] = " << na[0] << endl;
    cout << "na[1] = " << na[1] << endl;
    cout << "na[2] = " << na[2] << endl;

    int b;
    pna = &b;

    return 0;
}
