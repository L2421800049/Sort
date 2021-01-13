#include<iostream>
using namespace std;


typedef struct linkode{
    int data;
    int length;
    struct linknode *next;
}*link,linkNode;

void init(link &L);
link createLink(link &L,int *e); 
void show(link L);   