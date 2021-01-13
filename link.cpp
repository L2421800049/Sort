# include<stdio.h>
# include<stdlib.h>

# define TRUE 1
# define FALSE 0


typedef struct linkode{
    int data;
    int length;
    struct linknode *next;
}*link,linkNode;

void init(link &L){
    L->next=NULL;// 头节点为空
    L->length = 0;
}

link createLink(link &L,int *e,int length){
    linkNode *p = L->next;
    for(int i=0;i<length;i++){
        linkNode *node = (linkNode *)malloc(sizeof(linkNode));
        node->data = e[i];
        node->next = L->next;
        L->next = node;
        L->length++;
    }
}

void show(link L){
    linkNode *p = L->next;
    while (p!=NULL)
    {
        printf("%d ",L->data);
        p=p->next;
    }
    
}