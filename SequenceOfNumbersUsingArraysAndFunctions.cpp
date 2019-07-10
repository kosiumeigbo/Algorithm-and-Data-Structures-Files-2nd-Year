#include <iostream>
#define ASIZE 128

using namespace std;

void reverseintar(int in[], int arraysize, int out[]);

int main(){

    int int_a[ASIZE], int_a2[ASIZE];

    int tmp;

    int i = 0, int_a_size = 0, int_a2_size = 0;

    cout << "enter a number: " << endl;
    cin >> tmp;

    while(tmp != 0){
        int_a[i] = tmp;
        i++;

        cout << "enter a number: " << endl;
        cin >> tmp;
    }

    int_a_size = i;

    reverseintar(int_a, int_a_size, int_a2);
    int_a2_size = int_a_size;

    cout << "You entered the following points: " << endl;

    for(int i = 0; i < int_a_size; i++){
        cout << int_a[i] << endl;
    }

    cout << "That in reverse order are: " << endl;

    for(int i = 0; i < int_a2_size; i++){
        cout << int_a2[i] << endl;
    }

    return 0;
}

void reverseintar(int in[], int arraysize, int out[]){
    int j = 0;
    for(int i = arraysize - 1; i >= 0; i--){
        out[j] = in[i];
        j++;
    }
}
