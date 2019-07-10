#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <vector>

struct bdnode{
    std::string val;
    bdnode* left;
    bdnode* right;
};

typedef bdnode* bdt;

bdt buildcompactbdt(const std::vector<std::string>& fvalues);
std::string evalcompactbdt(bdt t, const std::string& input);
bdt buildbdt(const std::vector<std::string>& fvalues);
std::string evalbdt(bdt t, const std::string &input);
void initial_tree(std::string value, bdt &t, int i);
void fill_tree(bdt &t, std::string number_input);
std::string get_eval_value(bdt t, const std::string& number_input);
bool check_subtrees(bdt &t1, bdt &t2);
bool check_tree(bdt &t);
void delete_subtree(bdt &t);
void compact_tree(bdt &t);
int node_value_int(std::string node_value);

int main(){
    /*std::string y_n, input;
    std::vector<std::string> fvalues;
    std::cout << "Please enter the number" << std::endl;
    std::cin >> input;
    fvalues.push_back(input);
    std::cout << "Continue? y/n" << std::endl;
    std::cin >> y_n;
    while(y_n == "y"){
        std::cout << "Please enter the number" << std::endl;
        std::cin >> input;
        fvalues.push_back(input);
        std::cout << "Continue? y/n" << std::endl;
        std::cin >> y_n;
    }

    bdt t = NULL;
    int i = 0;
    initial_tree(fvalues[0], t, i);
    printtree(t);

    bdt t = buildcompactbdt(fvalues);
    std::cout << std::endl;
    std::cout << "The compact form of the tree is:" << std::endl;
    printtree(t);
    std::string right_value, wrong_value;
    right_value = evalcompactbdt(t, fvalues[0]);
    wrong_value = evalcompactbdt(t, "000");
    std::cout << std::endl;
    std::cout << "Eval. value of " << fvalues[0] << ": " << right_value << std::endl;
    std::cout << "Eval. value of 000: " << wrong_value << std::endl;

    std::cout << std::endl;
    bdt t = buildbdt(fvalues);
    printtree(t);
    std::cout << std::endl;
    compact_tree(t);
    std::cout << "The compact form of the tree is:" << std::endl;
    printtree(t);

    bdt t = buildbdt(fvalues);
    delete_subtree(t);
    std::cout << std::endl;
    printtree(t);

    bdt t = buildbdt(fvalues);
    if(check_tree(t)){
        std::cout << "This tree has identical subtrees" << std::endl;
    }
    else{
        std::cout << "This tree doesn't have identical subtrees" << std::endl;
    }

    bdt t = buildbdt(fvalues);
    if(check_subtrees(t->left, t->right)){
        std::cout << "This tree has identical subtrees" << std::endl;
    }
    else{
        std::cout << "This tree doesn't have identical subtrees" << std::endl;
    }

    bdt t = buildbdt(fvalues);
    std::string right_value, wrong_value;
    right_value = get_eval_value(t, fvalues[0]);
    wrong_value = get_eval_value(t, "010");
    std::cout << std::endl;
    std::cout << "Eval. value of " << fvalues[0] << ": " << right_value << std::endl;
    std::cout << "Eval. value of 010: " << wrong_value << std::endl;

    bdt t = NULL;
    int i = 0;
    initial_tree(fvalues[0], t, i);
    fill_tree(t, fvalues[0]);
    printtree(t);

    int k = node_value_int(fvalues[0]);
    std::cout << std::endl;
    std::cout << "The node string value is " << fvalues[0] << std::endl;
    std::cout << "The node integer value is " << k << std::endl;*/

    return 0;
}

bdt buildcompactbdt(const std::vector<std::string>& fvalues){
    bdt t = buildbdt(fvalues);
    compact_tree(t);
    return t;
}

std::string evalcompactbdt(bdt t, const std::string& input){
    return evalbdt(t, input);
}

bdt buildbdt(const std::vector<std::string>& fvalues){
    int i = 0;
    bdt t = NULL;
    initial_tree(fvalues[i], t, i);

    for(int a = 0; a < fvalues.size(); a++){
        fill_tree(t, fvalues[a]);
    }

    return t;
}

std::string evalbdt(bdt t, const std::string &input){
    return get_eval_value(t, input);
}

//building the initial tree
void initial_tree(std::string value, bdt &t, int i){
    if(i < value.size()){
        bdt temp = new bdnode;
        t = temp;
        std::stringstream ss;
        ss << "x" << (i + 1);
        t->val = ss.str();
        t->left = NULL;
        t->right = NULL;

        initial_tree(value, t->left, i + 1);
        initial_tree(value, t->right, i + 1);
    }

    else{
        bdt temp = new bdnode;
        t = temp;
        t->val = "0";
        t->left = NULL;
        t->right = NULL;
    }
}

//fill the tree for one string entry
void fill_tree(bdt &t, std::string number_input){
    if(t != NULL){
        if(t->val.size() > 1){
            int i = node_value_int(t->val);
            if(number_input[i - 1] == '0'){
                fill_tree(t->left, number_input);
            }
            else{
                fill_tree(t->right, number_input);
            }
        }
        else{
            t->val = "1";
        }
    }
}

bool check_subtrees(bdt &t1, bdt &t2){
    if((t1 == NULL)&&(t2 == NULL)){
        return true;
    }
    if((t1->val == t2->val)&&(check_subtrees(t1->left, t2->left))&&(check_subtrees(t1->right, t2->right))){
        return true;
    }
    return false;
}

bool check_tree(bdt &t){
    if(check_subtrees(t->left, t->right)){
        return true;
    }
    else{
        return false;
    }
}

void delete_subtree(bdt &t){
    if((check_tree(t))&&(t != NULL)&&(t->right != NULL)&&(t->left != NULL)){
        bdt temp1, temp2;
        temp1 = t->right;
        temp2 = t;
        temp2->right = temp2->left;
        t = temp1;
        delete temp2;
    }
}

void compact_tree(bdt &t){
    if(t != NULL){
        compact_tree(t->left);
        compact_tree(t->right);
        delete_subtree(t);
    }
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

std::string get_eval_value(bdt t, const std::string& number_input){
    if(t->val.size() > 1){
        int i = node_value_int(t->val);
        if(number_input[i - 1] == '0'){
            return get_eval_value(t->left, number_input);
        }
        else{
            return get_eval_value(t->right, number_input);
        }
    }
    else{
        return t->val;
    }
}
