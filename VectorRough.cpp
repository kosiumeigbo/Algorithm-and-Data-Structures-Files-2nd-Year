#include <iostream>
#include <string>

int main(){
    std::string name;

    std::cout << "Enter your first name:" << std::endl;
    std::cin >> name;
    std::cout << "The size of your vector is " << name[0] << std::endl;

    return 0;
}
