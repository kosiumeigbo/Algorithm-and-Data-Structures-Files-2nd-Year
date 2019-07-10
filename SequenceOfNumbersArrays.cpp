#include <iostream>
using namespace std;

int main(){

    int int_a[128];
    // declaring an array of int called int_a
    // allocating memory for 128 integers
    // this will allocate 128 cells
    // that initially have no meaningful values
    // 128 is the physical size of this array
    // (expressed in number of elements)
    // and it's the maximum number of elements it can contain

    int tmp;

    int i = 0;
    // declaring an index i
    // initialized at 0

    cout << "Enter a number:" << endl;
    cin >> tmp;

    while(tmp != 0){
        int_a[i] = tmp;
        // at each iteration
        // we overwrite the previous (non-meaningful)
        // content of the cell

        i++;
        // we update the index by incrementing it

        cout << "Enter a number:" << endl;
        cin >> tmp;
    }

    int int_a_size = i;
    // when we are out of the loop i contains the logical size of the array, that is how many elements have been stored
    // we need to save this information somewhere (if it's overwritten it can't be retrieved)

    cout << "You entered the following numbers:" << endl;
    // similar to what we would do with vectors
    // (but we don't have a size() member function
    // the index of the first element is 0
    // the index of the last element is int_a_size - 1

    for(int i = 0; i < int_a_size; i++){
        cout << int_a[i] << endl;
    }

    cout << "That in reverse order are:" << endl;

    for(int i = int_a_size - 1; i >= 0; i--){
        cout << int_a[i] << endl;
    }

    return 0;
}
