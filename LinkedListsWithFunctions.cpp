#include <iostream>

typedef int list_t;

struct listnode{
    list_t val;
    listnode* next;
};

typedef listnode* mlist;

void consref(list_t el, mlist& l);
mlist consret(list_t el, mlist l);
void printlist(mlist l);
void deallocate_c(mlist l);
void deallocate_r(mlist& l);

int main(){

    mlist la = NULL;
    mlist lb = NULL;

    int n;
    list_t el;
    std::cout << "How many elements?" << std::endl;
    std::cin >> n;

    for(int i = 0; i < n; i++){
        std::cout << "Enter element " << i+1 << std::endl;
        std::cin >> el;

        consref(el, la);
        lb = consret(el, lb);
    }

    std::cout << std::endl;

    printlist(la);

    std::cout << std::endl;

    printlist(lb);

    deallocate_c(la);

    deallocate_r(lb);

    return 0;
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

void printlist(mlist l){
    while(l != NULL){
        std::cout << l->val << std::endl;
        l = l->next;
    }
}

void deallocate_c(mlist l){
    while(l != NULL){
        mlist next1 = l->next;
        delete l;
        l = next1;
    }
}

void deallocate_r(mlist& l){
    while(l != NULL){
        mlist next1 = l->next;
        delete l;
        l = next1;
    }
}
