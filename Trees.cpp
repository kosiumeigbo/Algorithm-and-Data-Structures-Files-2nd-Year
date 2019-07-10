#include <iostream>

typedef int tree_t;

struct treenode{
    tree_t val;
    treenode* left;
    treenode* right;
};

typedef treenode* mtree;

mtree constree(tree_t el, mtree l, mtree r);

mtree instree(tree_t el, mtree t);
void instree_ref(tree_t el, mtree& t);

void printtree(mtree t);

mtree deletefromtree_nmr(tree_t el, mtree t);

tree_t minvalnode(mtree t);

void deletetree(mtree t);

int main(){
    int n;
    mtree t = NULL, t2 = NULL;
    tree_t tmp;
    std::cout << "How many elements?" << std::endl;
    std::cin >> n;
    for(int i = 0; i < n; i++){
        std::cin >> tmp;
        t = instree(tmp, t);
        instree_ref(tmp, t2);
    }

    std::cout << std::endl;
    printtree(t);
    std::cout << std::endl;
    printtree(t2);

    std::cout << "Enter element to delete" << std::endl;
    std::cin >> n;

    t = deletefromtree_nmr(n, t);
    t2 = deletefromtree_nmr(n, t2);

    std::cout << std::endl;
    printtree(t);
    std::cout << std::endl;
    printtree(t2);

    deletetree(t);
    t = NULL;
    deletetree(t2);
    t2 = NULL;

    return 0;
}

mtree constree(tree_t el, mtree l, mtree r){
    mtree tmp = new treenode;
    tmp->val = el;
    tmp->left = l;
    tmp->right = r;
    return tmp;
}

mtree instree(tree_t el, mtree t){
    if(t == NULL){
        return constree(el, NULL, NULL);
    }

    else if(el < t->val){
        t->left = instree(el, t->left);
        return t;
    }

    else{
        t->right = instree(el, t->right);
        return t;
    }
}

void instree_ref(tree_t el, mtree& t){
    if(t == NULL){
        mtree tmp = new treenode;
        tmp->val = el;
        tmp->left = NULL;
        tmp->right = NULL;
        t = tmp;
    }
    else if(el < t->val){
        instree_ref(el, t->left);
    }
    else{
        instree_ref(el, t->right);
    }
}

void printroot(mtree t){
    std::cout << t->val << std::endl;
}

void printtree(mtree t){
    if(t != NULL){
        printtree(t->left);
        printroot(t);
        printtree(t->right);
    }
}

tree_t minvalnode(mtree t){
    if(t->left == NULL){
        return t->val;
    }
    else{
        return minvalnode(t->left);
    }
}

mtree deletefromtree_nmr(tree_t el, mtree t){
    if(t == NULL){
        return t;
    }
    else if(el == t->val){
        if((t->left == NULL)&&(t->right == NULL)){
            delete t;
            return NULL;
        }
        else if(t->left == NULL){
            mtree temp = t->right;
            delete t;
            return temp;
        }
        else if(t->right == NULL){
            mtree temp = t->left;
            delete t;
            return temp;
        }
        else{
            t->val = minvalnode(t->right);
            t->right = deletefromtree_nmr(t->val, t->right);
            return t;
        }
    }
    else if(el < t->val){
        t->left = deletefromtree_nmr(el, t->left);
        return t;
    }
    else{
        t->right = deletefromtree_nmr(el, t->right);
        return t;
    }
}

void deletetree(mtree t){
    if(t != NULL){
        deletetree(t->left);
        deletetree(t->right);
        delete t;
    }
}
