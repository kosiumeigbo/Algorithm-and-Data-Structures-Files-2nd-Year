#include<iostream>
#include<string>
#include<sstream>

int main(){

    int num;
    std::cout << "Put in an integer number greater than 9" << std::endl;
    std::cin >> num;
    std::stringstream ss;
    std::string a;
    ss << num;
    ss >> a;
    int num_size = a.size();
    for(int i = 0; i < num_size; i++){
        std::cout << a[i] << std::endl;
    }

    return 0;

}
