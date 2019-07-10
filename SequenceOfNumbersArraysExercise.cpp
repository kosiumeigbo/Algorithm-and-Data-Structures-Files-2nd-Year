#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(){

    ifstream infile;

    infile.open("SequenceOfNumbersArraysExercise.txt");

    if(!infile.is_open()){

        cout << "File could not be opened" << endl;

        exit(EXIT_FAILURE);
    }

    int num[120];
    int n;
    int i = 0;

    while(infile >> n){
        num[i] = n;
        i++;
    }

    int num_size = i;

    cout << "We will now print out the numbers on the list" << endl;
    cout << endl;

    for(int j = 0; j < num_size; j++){
        cout << num[j] << endl;
    }

    cout << endl;

    int random_number;
    cout << "Enter an integer number" << endl;
    cin >> random_number;

    cout << "We will now check to see if your number is on the list" << endl;
    cout << "If you get no confirmation at the end, it is not on the list" << endl;
    cout << endl;

    int k = 0;

    while((k < num_size)&&(num[k] != random_number)){
        k++;
    }

    if(num[k] == random_number){
        cout << "The number is in the list" << endl;
        cout << "The index is " << k << endl;
    }

    else{
        cout << "The number is not in the list" << endl;
    }

    return 0;
}
