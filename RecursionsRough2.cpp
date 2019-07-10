#include <iostream>

void print_n_asterisks(int n);

int main(){
    int num;
    std::cout << "Please enter the number of asterisks you want:" << std::endl;
    std::cin >> num;
    print_n_asterisks(num);
    return 0;
}

void print_n_asterisks(int n){
    if(n == 1){
        std::cout << "*";
    }
    else{
        std::cout << "*";
        print_n_asterisks(n - 1);
    }
}
