#include <iostream>
using namespace std;

struct point{
    double x;
    double y;
};

int main(){
    int a = 5;
    cout << "variable a of type int" << endl;
    cout << "with value: " << a << endl;
    cout << "at address: " << &a << endl;

    int* pa;

    pa = &a;

    cout << endl;

    cout << "variable pa of type pointer to int" << endl;
    cout << "with value: " << pa << endl;
    cout << "(the value will be the address of variable a as printed above)" << endl;
    cout << "at address: " << &pa << endl;
    cout << endl;

    cout << "the value of a can be accessed with *pa:" << endl;
    cout << "a: " << a << " " << "*pa: " << *pa << endl;

    cout << endl;

    *pa = 3;

    cout << "after changing the value of a using pa" << endl;
    cout << "a: " << a << " " << "*pa: " << *pa << endl;

    cout << endl;

    int b = 10;
    pa = &b;
    cout << "pa now points to b: " << endl;
    cout << "&b: " << &b << " " << "pa: " << pa << endl;
    cout << "a: " << a << " " << "b: " << b << " " << "*pa: " << *pa << endl;

    cout << endl;

    point p;
    p.x = 0.5;
    p.y = 0.6;

    cout << "p: " << endl;
    cout << "value: " << p.x << ", " << p.y << endl;
    cout << "address: " << &p << endl;

    cout << endl;

    point* ppoint = &p;

    cout << "ppoint: " << endl;
    cout << "value: " << ppoint << endl;

    (*ppoint).x = 0.7;

    ppoint->y = 0.8;

    cout << endl;

    cout << "p after the coordinates change through ppoint: " << endl;
    cout << p.x << ", " << p.y << endl;

    return 0;
}
