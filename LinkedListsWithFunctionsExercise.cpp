#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

//this program only performs the concatenation function from the exercises
typedef int list_t;

struct listnode{
    list_t val;
    listnode* next;
};

typedef listnode* mlist;

mlist concatenate(mlist lx, mlist ly);

int main(){

    mlist la = NULL;
    mlist lb = NULL;
    list_t num1, num2;

    std::ifstream infile1, infile2;
    std::string filename1, filename2;
    std::cout << "Please enter the name of the file for list 1" << std::endl;
    std::cin >> filename1;
    std::cout << "Please enter the name of the file for list 2" << std::endl;
    std::cin >> filename2;
    std::cout << std::endl;

    //opening file for list 1
    infile1.open(filename1.c_str());

    if(!infile1.is_open()){

        std::cout << "File 1 could not be opened" << std::endl;

        exit(EXIT_FAILURE);
    }

    //dealing with list 1 in the next section
    while(infile1 >> num1){
        mlist tmpp1 = new listnode;
        tmpp1->val = num1;
        tmpp1->next = la;
        la = tmpp1;
    }

    mlist lit1 = la;

    std::cout << "Linked List 1 is as follows:" << std::endl;

    while(lit1 != NULL){
        std::cout << lit1->val << std::endl;
        lit1 = lit1->next;
    }

    std::cout << std::endl;

    //opening file for list 2
    infile2.open(filename2.c_str());

    if(!infile2.is_open()){

        std::cout << "File 2 could not be opened" << std::endl;

        exit(EXIT_FAILURE);
    }

    //dealing with list 2 in the next section
    while(infile2 >> num2){
        mlist tmpp2 = new listnode;
        tmpp2->val = num2;
        tmpp2->next = lb;
        lb = tmpp2;
    }

    mlist lit2 = lb;

    std::cout << "Linked List 2 is as follows:" << std::endl;

    while(lit2 != NULL){
        std::cout << lit2->val << std::endl;
        lit2 = lit2->next;
    }

    std::cout << std::endl;

    mlist flist = concatenate(la, lb);
    mlist lit3 = flist;
    std::cout << "The combined list is as follows:" << std::endl;

    while(lit3 != NULL){
        std::cout << lit3->val << std::endl;
        lit3 = lit3->next;
    }

    return 0;
}

mlist concatenate(mlist lx, mlist ly){
    mlist tmp = lx;
    while(tmp->next != NULL){
        tmp = tmp->next;
    }

    tmp->next = ly;
    tmp = lx;
    return tmp;
}
