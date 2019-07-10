#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

struct intlist{
    int val;
    intlist* next;
};

int main(){

    std::ifstream infile;
    std::string filename;
    std::cout << "Please enter the name of the file for input" << std::endl;
    std::cin >> filename;

    infile.open(filename.c_str());

    if(!infile.is_open()){

        std::cout << "File could not be opened" << std::endl;

        exit(EXIT_FAILURE);
    }

    //The next line is to initialize the list to be NULL
    intlist* l = NULL;
    int n;

    //The next section fills the linked list with elements from the file
    while(infile >> n){
        intlist* tmp = new intlist;
        tmp->val = n;
        tmp->next = l;
        l = tmp;
    }

    //The next section is to print out the contents of the linked list
    intlist* lit1 = l;

    while(lit1 != NULL){
        std::cout << lit1->val << std::endl;
        lit1 = lit1->next;
    }

    //The next section is to find the list size
    int i = 0;

    intlist* lit2 = l;

    while(lit2 != NULL){
        lit2 = lit2->next;
        i++;
    }

    int listsize = i;
    std::cout << std::endl;
    std::cout << "There are " << listsize << " elements in the list" << std::endl;
    std::cout << std::endl;

    //The next section is to find if a number is on the list or not
    //If it is, we will print out its indices in the linked list and in the input file
    intlist* lit3 = l;
    int number;

    std::cout << "Enter number to search for on the list:" << std::endl;
    std::cin >> number;

    int j = 0;

    while((lit3 != NULL)&&(lit3->val != number)){
        lit3 = lit3->next;
        j++;
    }

    if(lit3 == NULL){
        std::cout << "Your number was not found" << std::endl;
    }

    else if(lit3->val == number){
        std::cout << "The number you entered, " << number << " , is in the list" << std::endl;
        std::cout << "It is in the index " << j << " in the linked list" << std::endl;

        int inputfile_index = listsize - j - 1;
        std::cout << "The index in the input file is " << inputfile_index << std::endl;
    }

    //The next section is to delete an instance of a number for only the first time it is found
    //The next section also prints out the new list whether an item was deleted or not
    std::cout << std::endl;
    int num_to_delete;
    std::cout << "Please enter the number you want to delete:" << std::endl;
    std::cin >> num_to_delete;
    std::cout << "This routine only deletes the first instance of the number" << std::endl;

    intlist* lit4 = l;

    while((lit4 != NULL)&&(lit4->val != num_to_delete)){
        lit4 = lit4->next;
    }

    intlist* lit5;
    intlist* lit6;

    if(lit4 == NULL){
        lit5 = l;

        std::cout << "That number was not on the list" << std::endl;
        std::cout << "The linked list is still as follows:" << std::endl;

        while(lit5 != NULL){
            std::cout << lit5->val << std::endl;
            lit5 = lit5->next;
        }
    }

    else{
        lit5 = l;
        while((lit5->next->val != num_to_delete)&&(lit5 != NULL)){
            lit5 = lit5->next;
        }

        if(lit5->next->val == num_to_delete){
            intlist* discard = lit5->next;
            lit5->next = discard->next;
            delete discard;
        }

        lit6 = l;

        std::cout << "The linked list is now as follows:" << std::endl;

        while(lit6 != NULL){
            std::cout << lit6->val << std::endl;
            lit6 = lit6->next;
        }
    }
    std::cout << std::endl;

    //The next section now deletes all instances of the same number in the list
    //We then print out the new list without the number
    std::cout << "Please enter the number you want to delete:" << std::endl;
    std::cin >> num_to_delete;
    std::cout << "This routine deletes all instances of the same number in the list" << std::endl;

    lit4 = l;

    while((lit4 != NULL)&&(lit4->val != num_to_delete)){
        lit4 = lit4->next;
    }

    if(lit4 == NULL){
        lit5 = l;

        std::cout << "The number is not on the list. It remains as the same" << std::endl;
        while(lit5 != NULL){
            std::cout << lit5->val << std::endl;
            lit5 = lit5->next;
        }
    }

    else{
        lit5 = l;
        while(lit5 != NULL){
            if(lit5->next->val != num_to_delete){
                intlist* discard = lit5->next;
                lit5->next = discard->next;
                lit5 = lit5->next;
            }

            else{
                lit5 = lit5->next;
            }
        }

        lit6 = l;

        while(lit6 != NULL){
            std::cout << lit6->val << std::endl;
            lit6 = lit6->next;
        }
    }
    return 0;
}
