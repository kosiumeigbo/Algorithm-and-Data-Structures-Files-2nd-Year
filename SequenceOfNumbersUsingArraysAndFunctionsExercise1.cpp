#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int checklistfornumber(int num_array[], int ar_size, int ran_number);

int main(){
    ifstream infile;

    infile.open("SequenceOfNumbersUsingArraysAndFunctionsExercise1.txt");

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

    cout << "We will now print out the list of numbers" << endl;

    for(int j = 0; j < num_size; j++){
        cout << num[j] << endl;
    }

    int random_number;

    cout << "You will enter a random integer below" << endl;
    cout << "We will check if it is in the list" << endl;
    cout << "Please enter the number below: " << endl;
    cin >> random_number;

    int result = checklistfornumber(num, num_size, random_number);

    cout << "The index of your number is:" << endl;
    cout << result << endl;
    cout << "If the number above is not -1, that is the index in the list of the number you entered" << endl;
    cout << "If the number above is -1, then the number you entered is not in the list" << endl;

    return 0;
}

int checklistfornumber(int num_array[], int ar_size, int ran_number){
    int k = 0;

    while((k < ar_size)&&(num_array[k] != ran_number)){
        k++;
    }

    if(num_array[k] == ran_number){
        return k;
    }

    else{
        return -1;
    }
}
