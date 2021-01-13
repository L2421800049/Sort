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
typedef struct QNode{
    node *data;
    struct QNode *next;
}QNode,*Queue;
// typedef node *tree;

// struct queue
// {
//     int data;
//     struct queue *next;
// };
// 
// queue *createQueue(int *arr){
//     queue *head = (queue *)malloc(sizeof(queue));
//     queue *p = (queue *)malloc(sizeof(queue));
//     head->data = arr[0];
//     head->next =NULL;
    // 
//     p=head;
//     int index=1;
//     while (index<MAXSIZE)
//     {   
//         queue *newNode = (queue *)malloc(sizeof(queue));
//         newNode->next = p->next; 
//         p->next = newNode;
//         newNode->data = arr[index++];
//         p=newNode;
//     }
//     return head;
// }

node *initTree(int *arr,node* t){

    for(int i=1;i<=MAXSIZE/2;i++){
        t[i].data = arr[(i-1)];
        t[i].ltree = &t[2*i];
        t[i].rtree = &t[2*i+1];
    }
    node *head = &(t[1]);
    return head;
}

bool initQueue(Queue &Q){
    Q = (QNode *)malloc(sizeof(QNode));
    Q ->next = NULL;
    printf("succed init a queue\n");
    return true;
}
bool traverse(Queue &Q,Tree T){
    // printf("lenth of  Q is %d\n",len(Q));
    if(T!=NULL){     //  其实主要还是判断根结点是不是空的
        if(T->ltree!=NULL)    // 左节点是不是存在
            push(Q,T->ltree);  // 把左节点插入队列
        if (T->rtree!=NULL)
            push(Q,T->rtree);   // 同上，改为操作右节点
        outData[index++] = T;
        printf("data[%d] = %d\n",index-1,T->data);
        // printf("node[%d] is  %d\n",index-1,outData[index-1]);          // 输出
        // popNode = T;
        if(pop(Q,popNode))        // 删除队头元素，如果不存在，就是没了 说明遍历结束了  返回0 不执行下面的递归
            traverse(Q,popNode);  // 递归传递删除的队头节点
    }
    return true;
}

int main(int argc,char *argv[]){
    int arr[MAXSIZE] = {13,6,27,16,69,89,80,11,73,32,51,9,17,37,92,75};
    struct node t[MAXSIZE/2+1];
    node *head = initTree(arr,t); 
     
    // queue *q = createQueue(arr);
    printf("%d",head->ltree->ltree->ltree->ltree->data);
    return 0;
}