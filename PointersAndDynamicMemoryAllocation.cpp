#include <iostream>
using namespace std;

struct point{
    double x;
    double y;
};

int main(){

    int a = 15;
    cout << "a: " << a << endl;
    int* pa;
    pa = &a;
    *pa = 3;
    cout << "a (after the change through pa): " << a << endl;

    int* pb;

    pb = new int;

    *pb = 3;

    cout << "*pb: " << *pb << endl;

    delete pb;

    point* ppoint;
    ppoint = new point;
    ppoint->x = 0.1;
    ppoint->y = -0.1;
    cout << "ppoint->x: " <<  ppoint->x << " ppoint->y: " << ppoint->y << endl;
    delete ppoint;

    int* parr;
    int maxsize, lsize = 0;
    cout << "enter amount of memory to enter for array: " << endl;
    cin >> maxsize;
    parr = new int[maxsize];

    parr[0] = 3;
    lsize++;
    parr[1] = 4;
    lsize++;
    for(int i = 0; i < lsize; i++){
        cout << "parr[" << i << "]: " << parr[i] << endl;
    }

    delete[] parr;

    return 0;
}
