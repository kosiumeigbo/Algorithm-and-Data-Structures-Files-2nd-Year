#include <iostream>

void reverse_vertical(int n);

int main(){
    int num;
    std::cout << "Please enter the number:" << std::endl;
    std::cin >> num;
    reverse_vertical(num);
    return 0;
}

void reverse_vertical(int n){
    if(n < 10){
        std::cout << n << std::endl;
    }
    else{
        std::cout << n % 10 << std::endl;
        reverse_vertical(n / 10);
    }
}
