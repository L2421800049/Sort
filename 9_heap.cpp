//堆排序
// 大根堆
# include<stdio.h>
# include<stdlib.h>

# define MAXSIZE 16

struct node
{
    int data;
    // char lfull;//左边是否满了
    // char rfull;//右边是否满了
    struct node *ltree;
    struct node *rtree;
};
// typedef node *tree;

struct queue
{
    int data;
    struct queue *next;
};

queue *createQueue(int *arr){
    queue *head = (queue *)malloc(sizeof(queue));
    queue *p = (queue *)malloc(sizeof(queue));
    head->data = arr[0];
    head->next =NULL;
    
    p=head;
    int index=1;
    while (index<MAXSIZE)
    {   
        queue *newNode = (queue *)malloc(sizeof(queue));
        newNode->next = p->next; 
        p->next = newNode;
        newNode->data = arr[index++];
        p=newNode;
    }
    return head;
}

node *initTree(int *arr,node* t){
    for(int i=1;i<=MAXSIZE/2;i++){
        t[i].ltree = &t[2*i];
        t[i].rtree = &t[2*i+1];
    }
    node *head = &(t[1]);
    return head;
}



int main(int argc,char *argv[]){
    int arr[MAXSIZE] = {13,6,27,16,69,89,80,11,73,32,51,9,17,37,92,75};
    struct node t[MAXSIZE];
    node *head = initTree(arr,t); 
     
    // queue *q = createQueue(arr);
    for(int i=1;i<MAXSIZE/2;i++){
        printf("this node is %d\tltree is %d\trtree is %d\n",arr[i-1],arr[2*i],arr[2*i]);
    }
    return 0;
}