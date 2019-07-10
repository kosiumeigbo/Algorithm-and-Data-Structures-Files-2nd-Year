#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <sstream>

struct bnode {
	std::string val;
	bnode *left;
	bnode *right;
};

typedef bnode *bdt;

bdt buildbdt (const std::vector <std::string> &fvalues);
void maketree (bdt &t, std::string x, int i);
void placevalue (bdt &t, std::string x,int i);
std::string evalinput (bdt t, const std::string &input,int i);
std::string evalbdt(bdt t,const std::string &input);
std::string convert_to_string(int n);


bdt buildbdt (const std::vector <std::string> &fvalues){
	bdt t=NULL;
	int i=0;
	std::string y;
	std::string x = fvalues[0];
	maketree(t,x,i);
	
	for(int a=0;a<fvalues.size();a++){
	y=fvalues[a];
	placevalue (t,y,i);
}
	return t;
}

void placevalue (bdt &t, std::string x,int i){
	if((t->left == NULL) && (t->right == NULL)){
	t->val="1";
		return;
	}
	 if(x[i] == '0'){
	i++;
			placevalue(t->left,x,i);		
	}
	else  {
		i++;
		placevalue(t->right,x,i);		
	}
}


// need to pass the stringstream into the function and need to get the treelength 
void maketree (bdt &t, std::string x, int i){
	if (i<x.size()){
		bdt newnode = new bnode ;
		newnode->val = convert_to_string(i+1);
		t=newnode;
		t->left= NULL;
		t->right=NULL;
		
		maketree(t->left, x,i+1);
		maketree(t->right,x,i+1);
	}
	else {
		bdt newnode = new bnode;
		newnode->val="0";
		t=newnode;
		t->right = NULL;
		t->left = NULL;
	}
}
	

std::string evalinput (bdt t, const std::string &input,int i){
	if ((t->left == NULL) && (t->right == NULL)){
		return t->val;
	}
	if(input[i]=='0'){
		i++;
		return evalinput (t->left,input,i);
	}
	else{
		i++;
		return evalinput (t->right,input,i);
	}
}

std::string evalbdt (bdt t, const std::string &input){
	int i=0;
	return evalinput(t,input,i);
}

std::string convert_to_string(int n){
	std::stringstream ss;
	ss<<"x"<<n;
	return ss.str();
}

