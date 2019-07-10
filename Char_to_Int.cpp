#include <iostream>
#include <cstdlib>
#include <string>

int main(){
    char num1[100];
    std::cout << "Enter the node value: " << std::endl;
    std::cin >> num1;
    std::cout << std::endl;
    std::cout << "You entered this node value:" << num1 << std::endl;
    char num2[100];
    for(int i = 0; i + 1 < 100; i++){
        num2[i] = num1[i + 1];
    }
    std::cout << "New node value is: " << num2 << std::endl;
    int i1 = atoi(num1);
    int i2 = atoi(num2);
    std::cout << std::endl;
    std::cout << "The converted integer form of num1 is: " << i1 << std::endl;
    std::cout << "The converted integer form of num2 is: " << i2 << std::endl;

    return 0;
}
