#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

typedef int list_t;

struct listnode{
    list_t val;
    listnode* next;
};

typedef listnode* mlist;

void consref(list_t el, mlist& l);
mlist consret(list_t el, mlist l);

mlist constail_rec(list_t el, mlist l);

void printlist_rec(mlist l);
void printrevlist_rec(mlist l);

void deallocate_r_rec(mlist& l);
mlist deallocate_c_rec(mlist l);
void deallocate_r_rec_wrong(mlist& l);

int xpowerp_rec(int x, int p);
int list_length_rec(mlist la, int i);
int equal_to_rec(mlist la, list_t el, int i);

int mfact(int n);

int main(){

    list_t el;
    mlist la = NULL;
    mlist lb = NULL;

    std::ifstream infile;
    std::string filename;
    std::cout << "Please enter the name of the file for input" << std::endl;
    std::cin >> filename;

    infile.open(filename.c_str());

    if(!infile.is_open()){

        std::cout << "File could not be opened" << std::endl;

        exit(EXIT_FAILURE);
    }

    while(infile >> el){

        la = consret(el, la);
    }

    std::cout << std::endl;

    int n = 0;
    int num;
    int how_many;

    std::cout << "Enter a number to search on the list:" << std::endl;
    std::cin >> num;
    how_many = equal_to_rec(la, num, n);
    std::cout << "There are " << how_many << " elements of " << num << "that are in the list" << std::endl;


    std::cout << std::endl;

    std::cout << "Printed in normal form:" << std::endl;

    printlist_rec(la);

    return 0;
}

int mfact(int n){
    if(n == 1){
        return 1;
    }

    else{
        return n*mfact(n - 1);
    }
}

void consref(list_t el, mlist& l){
    mlist tmpp = new listnode;
    tmpp->val = el;
    tmpp->next = l;
    l = tmpp;
}

mlist consret(list_t el, mlist l){
    mlist tmpp = new listnode;
    tmpp->val = el;
    tmpp->next = l;
    return tmpp;
}

mlist constail_rec(list_t el, mlist l){
    if(l == NULL){
        return consret(el, l);
    }

    else{
        l->next = constail_rec(el, l->next);
        return l;
    }
}

void printhead(mlist l){
    std::cout << l->val << std::endl;
}

void printlist_rec(mlist l){
    if(l != NULL){
        printhead(l);
        printlist_rec(l->next);
    }
}

void printrevlist_rec(mlist l){
    if(l != NULL){
        printrevlist_rec(l->next);
        printhead(l);
    }
}

void deallocate_r_rec_wrong(mlist& l){
    if(l != NULL){
        mlist next1 = l->next;
        delete l;
        deallocate_r_rec_wrong(next1);
    }
}

void deallocate_r_rec(mlist& l){
    if(l != NULL){
        mlist tmp = l;
        l = l->next;
        delete tmp;
        deallocate_r_rec(l);
    }
}

mlist deallocate_c_rec(mlist l){
    if(l == NULL){
        return l;
    }

    else{
        mlist next1 = l->next;
        delete l;
        return deallocate_c_rec(next1);
    }
}

int xpowerp_rec(int x, int p){
    if(p < 1){
        return 1;
    }

    else{
        return x*xpowerp_rec(x, p - 1);
    }
}

int list_length_rec(mlist la, int i){
    if(la == NULL){
        return i;
    }

    else{
        i = i + 1;
        la = la->next;
        return list_length_rec(la, i);
    }
}

int equal_to_rec(mlist la, list_t el, int i){
    if(la == NULL){
        return i;
    }
    else{
        if(la->val == el){
            i = i + 1;
            la = la->next;
            return equal_to_rec(la, el, i);
        }
        else{
            return equal_to_rec(la->next, el, i);
        }
    }
}
