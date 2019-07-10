#include <iostream>

void write_up(int n);

int main(){
    int num;
    std::cout << "Please enter the number:" << std::endl;
    std::cin >> num;
    write_up(num);
    return 0;
}

void write_up(int n){
    if(n >= 1){
        write_up(n - 1);
        std::cout << n << " ";
    }
}
