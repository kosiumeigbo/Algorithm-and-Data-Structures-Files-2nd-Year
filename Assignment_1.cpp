#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <vector>

struct bnode{
    std::string val;
    bnode* left;
    bnode* right;
};

typedef bnode* bdt;

bdt buildbdt(const std::vector<std::string>& fvalues);
//std::string evalbdt(bdt t, const std::string& input);
void printroot(bdt t);
void printtree(bdt t);
bdt constree(bdt l, bdt r);
bdt initial_tree(int h, bdt t);
bdt insert_char(char digit, bdt t, int n);
bdt insert_string(std::string num, bdt t);


int main(){
    //std::vector<std::string> input;
    //std::string in1, in2;
    //std::cin >> in1;
    //input.push_back(in1);
    //std::cin >> in2;
    //input.push_back(in2);
    //bdt m = NULL;
    //m = buildbdt(input);
    //printtree(m);
    return 0;
}

bdt buildbdt(const std::vector<std::string>& fvalues){
    bdt t = NULL;
    int k = fvalues[0].size();
    t = initial_tree(k, t);
    int fvalues_length = fvalues.size();
    for(int j = 0; j < fvalues_length; j++){
        t = insert_string(fvalues[j], t);
    }
    return t;
}

//std::string evalbdt(bdt t, const std::string& input){

//}

void printroot(bdt t){
    std::cout << t->val << std::endl;
}

void printtree(bdt t){
    if(t != NULL){
        printtree(t->left);
        printroot(t);
        printtree(t->right);
    }
}

bdt constree(bdt l, bdt r){
    bdt tmp = new bnode;
    tmp->val = "0";
    tmp->left = l;
    tmp->right = r;
    return tmp;
}

//Function creates initial tree of zeros with height h
bdt initial_tree(int h, bdt t){
    if(h == 0){
        return constree(NULL, NULL);
    }
    else if(h != 0){
        t = constree(NULL, NULL);
        t->left = initial_tree(h - 1, t->left);
        t->right = initial_tree(h - 1, t->right);
        return t;
    }
}

//Function takes in input a character and inserts into the tree as a string with "1" in the last node
bdt insert_char(char digit, bdt t, int n){
    if(n == 0){
        std::stringstream ss;
        std::string a, x;
        ss << digit;
        ss >> a;
        t->val = a;
        t->right->val = "1";
        return t;
    }
    else{
        if(digit == '0'){
            t->left = insert_char(digit, t->left, n - 1);
            return t;
        }
        else if(digit == '1'){
            t->right = insert_char(digit, t->right, n - 1);
            return t;
        }
    }
}

//Function takes in input a string and inserts it into the tree automatically making the end node "1"
bdt insert_string(std::string num, bdt t){
    int length = num.size();
    for (int i = 0; i < length; i++){
        t = insert_char(num[i], t, i);
    }
    return t;
}

//Function to check char
bdt insert_char(char digit, bdt t, int n){
    if(n == 0){
        std::stringstream ss;
        std::string a, x;
        ss << digit;
        ss >> a;
        t->val = a;
        t->right->val = "1";
        return t;
    }
    else{
        if(digit == '0'){
            t->left = insert_char(digit, t->left, n - 1);
            return t;
        }
        else if(digit == '1'){
            t->right = insert_char(digit, t->right, n - 1);
            return t;
        }
    }
}
