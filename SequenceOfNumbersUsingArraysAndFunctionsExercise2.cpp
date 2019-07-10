#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

int getarraysize(int num1_array[], int num1_ar_size, int ran_number);
void printlessthan(int num1_array[], int num1_ar_size, int num2_array[], int ran_number);

int main(){

    ifstream infile;
    string filename;
    cout << "Please enter the name of the file for input" << endl;
    cin >> filename;

    infile.open(filename.c_str());

    if(!infile.is_open()){

        cout << "File could not be opened" << endl;

        exit(EXIT_FAILURE);
    }

    int num1[120];
    int num2[120];
    int n;
    int i = 0;

    while(infile >> n){
        num1[i] = n;
        i++;
    }

    int num1_size = i;
    int num2_size = 0;

    cout << "These are the  numbers on the list as they appear:" << endl;

    for(i = 0; i < num1_size; i++){
        cout << num1[i] << endl;
    }

    cout << endl;
    int random_number;
    cout << "Please enter a random integer number:" << endl;
    cin >> random_number;
    cout << "This program prints a list of numbers in the file that are less than the number you input" << endl;
    num2_size = getarraysize(num1, num1_size, random_number);

    cout << "First of all, the size of the second array is:" << endl;
    cout << num2_size << endl;

    printlessthan(num1, num1_size, num2, random_number);

    cout << "The following are the numbers less than the number you input" << endl;
    for(int k = 0; k < num2_size; k++){
        cout << num2[k] << endl;
    }

    return 0;
}

int getarraysize(int num1_array[], int num1_ar_size, int ran_number){
    int j = 0;
    for(int i = 0; i < num1_ar_size; i++){
        if(num1_array[i] < ran_number){
            j++;
        }
    }

    int num2_ar_size = j;
    return num2_ar_size;
}

void printlessthan(int num1_array[], int num1_ar_size, int num2_array[], int ran_number){
    int j = 0;
    for(int i = 0; i < num1_ar_size; i++){
        if(num1_array[i] < ran_number){
            num2_array[j] = num1_array[i];
            j++;
        }
    }
}
