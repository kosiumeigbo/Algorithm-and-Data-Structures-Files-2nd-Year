#include <iostream>

void write_down(int n);

int main(){
    int num;
    std::cout << "Please enter the number:" << std::endl;
    std::cin >> num;
    write_down(num);
    return 0;
}

void write_down(int n){
    if(n >= 1){
        std::cout << n << " ";
        write_down(n - 1);
    }
}
