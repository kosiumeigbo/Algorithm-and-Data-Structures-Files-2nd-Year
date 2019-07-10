#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>

int node_value_int(std::string node_value);

int main(){
    std::string value;
    std::cout << "Input a string value in the format of x followed by any integer number" << std::endl;
    std::cin >> value;
    int index_value = node_value_int(value);
    std::cout << "The index value is " << index_value << std::endl;

    return 0;
}

int node_value_int(std::string node_value){
    int string_size = node_value.size();
    char index[string_size - 1];
    for(int i = 0; i < string_size - 1; i++){
        index[i] = node_value[i + 1];
    }
    int x = atoi(index);
    return x;
}

//removed from Assignment 2
std::string print_leaf(bdt t, const std::string &input, int i){
    if((t->left == NULL)&&(t->right == NULL)){
        return t->val;
    }
    else{
        if(input[i] == '0'){
            return print_leaf(t->left, input, i + 1);
        }
        else{
            return print_leaf(t->right, input, i + 1);
        }
    }
}

//removed from Assignment 2
void fill_tree(std::string value, bdt &t, int i){
    if((t->left == NULL)&&(t->right == NULL)){
        t->val = "1";
    }
    else{
        if(value[i] == '0'){
            fill_tree(value, t->left, i + 1);
        }

        else{
            fill_tree(value, t->right, i + 1);
        }
    }
}
