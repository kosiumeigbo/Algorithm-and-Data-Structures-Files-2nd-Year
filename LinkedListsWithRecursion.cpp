#include <iostream>

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

int mfact(int n);

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

        la = consret(el, la);
        lb = constail_rec(el, lb);
    }

    std::cout << std::endl;

    std::cout << "Print in the normal order:" << std::endl;
    printlist_rec(la);
    std::cout << std::endl;
    printlist_rec(lb);

    std::cout << std::endl;

    std::cout << "Print in reverse order:" << std::endl;
    printrevlist_rec(la);
    std::cout << std::endl;
    printrevlist_rec(lb);

    std::cout << std::endl;

    deallocate_r_rec(la);
    std::cout << la << std::endl;
    lb = deallocate_c_rec(lb);
    std::cout << lb << std::endl;

    return 0;
}

int mfact(int n){
    if(n == 0){
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
