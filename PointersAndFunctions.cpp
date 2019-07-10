#include <iostream>
using namespace std;

void swapintp(int* pn1, int* pn2);

int main(){

    int a, b;

    cin >> a >> b;
    cout << "a: " << a << ", " << "b: " << b << endl;

    swapintp(&a, &b);

    cout << "a: " << a << ", " << "b: " << b << endl;

    return 0;

}

void swapintp(int* pn1, int* pn2){

    int tmp = *pn1;
    *pn1 = *pn2;
    *pn2 = tmp;

}
