# include<stdio.h>
# include<stdlib.h>

# define MAXLENGTH 30

typedef struct seqLink{
    int data;
    int length;
    struct seqLink *next;
}linkNode,*link;

void init(link &L){
    L = (linkNode *)malloc(sizeof(linkNode));
    L->data = -1;
    L->next=NULL;// 带头节点
    L->length = 0;
    printf("succced init a link!\n");
}

void createLink(link &L,int *e){
    linkNode *p = L->next;
    for(int i=0;i<MAXLENGTH;i++){
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
        printf("%d ",p->data);
        p=p->next;
    }
    
}



void bubble(link &L){
    linkNode *p = (linkNode *)malloc(sizeof(linkNode));
    linkNode *q = (linkNode *)malloc(sizeof(linkNode));
    
    bool flag = 0;
    int temp;
    while (1)
    {
        p = L->next;q = p->next;  //让q取值 让p永远做q的前驱
        while (q!=NULL)
        {
            if((q->data)<(p->data)){
                temp = q->data;
                q->data = p->data;
                p->data = temp; // 只换值，不换指针
                flag = 1;
            }
            p = p->next;
            q = q->next;   
        }
        if(flag == 0) break;
        flag = 0;
    } 
}


int main(){
    link L;
    init(L);
    int a[MAXLENGTH] = {92, 73, 46, 44, 31, 35, 80, 16, 7, 66, 25,
     1, 17, 70, 61, 22, 75, 79, 71, 5, 48, 24, 18, 15, 30, 50, 81, 97, 82, 86};
    createLink(L,a);
    show(L);
    bubble(L);
    printf("\n");
    show(L);
    return 1;
}