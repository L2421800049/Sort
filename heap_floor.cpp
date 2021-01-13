// 层序遍历
# include<stdio.h>
# include <stdlib.h>

# define true 1
# define false 0
# define MAXSIZE 27

struct node
{
    int data; 
    // char lfull;//左边是否满了
    // char rfull;//右边是否满了
    struct node *ltree;
    struct node *rtree;
};
typedef node *Tree;


typedef struct QNode{
    node *data;
    struct QNode *next;
}QNode,*Queue;

static node *popNode; // 三个全局变量
static int index = 0;
// static int t[0].data;

void swap(node *p1,node *p2){
    int temp;
    temp = p1->data;p1->data=p2->data;p2->data=temp;
}

bool initQueue(Queue &Q){
    Q = (QNode *)malloc(sizeof(QNode));
    Q ->next = NULL;
    printf("succed init a queue\n");
    return true;
}

bool push(Queue &Q,node *e){
    QNode *p = Q;
    QNode *s = (QNode *)malloc(sizeof(QNode));
    while (p->next != NULL)
    {
        p = p->next;
    }
    s->next = p->next;
    s->data = e;
    p->next = s;
    // printf("succed push elem %d\n",e);
    return true;
}

bool pop(Queue &Q,node* &node){  // 如果使用node 怎么使用引用类型呢 
                                        // node* 是结构体类型指针 相当于Tree
    QNode *p = Q;
    if (p->next == NULL){
        // printf("queue empty,can not pop!\n");
        return false;
    }
    node = p->next->data;
    p->next = p->next->next;
    return true;
}

node *initTree(node* t){
    //创建树的结构，并返回树根。
    for(int i=1;i<=MAXSIZE;i++){
        t[i].ltree = NULL;t[i].rtree= NULL;
    }

    for(int i=1;i<=MAXSIZE/2;i++){
        if(2*i<=MAXSIZE)
            t[i].ltree = &t[2*i];  //左子树是2*i
        if(2*i+1<=MAXSIZE)//保证不越界  由子树是2*i+1
            t[i].rtree = &t[2*i+1];
    }
    return &(t[1]);
}

//层序遍历，并插入值
void traverse(Queue &Q,Tree &T,int *arr,int length){
    if(T!=NULL&&index<length){     //  其实主要还是判断根结点是不是空的
        T->data = arr[index];
        if(T->ltree!=NULL)    // 左节点是不是存在
            push(Q,T->ltree);  // 把左节点插入队列
        if (T->rtree!=NULL)
            push(Q,T->rtree);   // 同上，改为操作右节点
        index++;
        if(pop(Q,popNode))        // 删除队头元素，如果不存在，就是没了 说明遍历结束了  返回0 不执行下面的递归
            traverse(Q,popNode,arr,length);  // 递归传递删除的队头节点
    }
}

/*
    t 是存堆的数组，其中索引为0的没有给值
    len 是要给赋值的索引
*/

void heapfy(struct node *t,int len){
    for(int i=len/2;i>0;i--){  // 只需要考虑分支节点，也就是长度的一半
        if(t[i].rtree==NULL){  // 缺少右子树，则只和左边树对比
            if(t[i].data < t[i].ltree->data){
                swap(&t[i],t[i].ltree);
            }
        }
        else{  // 完整二叉树
            
             //当作缺少右子树处理,并且这个时候的索引的节点 正好是他的子节点，
            if(len%2==0&&len/2==i){ //只需要管左边的哪个，相当于从堆里面排除了这个点
                if(t[i].data<t[i].ltree->data){
                    swap(&t[i],t[i].ltree);
                }
            }
            else{

                if(t[i].rtree->data > t[i].ltree->data){  // 子树最大的是右边
                    // 根值小于子树值，则互换
                    if(t[i].data < t[i].rtree->data){
                        swap(&t[i],t[i].rtree);
                    }
                }
                else if(t[i].rtree->data < t[i].ltree->data){ // 子树最大在左边
                    // 根值小于子树
                    if(t[i].data < t[i].ltree->data){
                        swap(&t[i],t[i].ltree);
                    }
                }
                else{
                if(t[i].data < t[i].rtree->data){
                    swap(&t[i],t[i].rtree);
                    }
                }

            }
        }
    }

    // 该节点的值就是堆的根结点的值，二者互换
    swap(&t[1],&t[len]);
}

void show(Queue &Q,Tree &T){
     if(T!=NULL){     //  其实主要还是判断根结点是不是空的
        if(T->ltree!=NULL)    // 左节点是不是存在
            push(Q,T->ltree);  // 把左节点插入队列
        if (T->rtree!=NULL)
            push(Q,T->rtree);   // 同上，改为操作右节点
        printf("%d ",T->data);
        if(pop(Q,popNode))        // 删除队头元素，如果不存在，就是没了 说明遍历结束了  返回0 不执行下面的递归
            show(Q,popNode);  // 递归传递删除的队头节点
    }
}

int main(){       
    
    Queue Q;  // 辅助队列
    initQueue(Q);

    int arr[MAXSIZE] = {13,6,27,16,69,89,80,11,73,32,51,9,17,37,13,92,75,99,53,13,62,44,84,61,51,17,16};
    int k=MAXSIZE;
    struct node t[MAXSIZE+1];
    node *head = initTree(t); 
    traverse(Q,head,arr,k);index = 0;
    show(Q,head);index=0;printf("\n");

    int len=MAXSIZE;

    // 对于大根堆，从右往左选择
    while (len>0)
    {
       heapfy(t,len--);  // 大根堆化，并使索引-1
    }
    
    show(Q,head);index=0;printf("\n");
    free(Q);
    return true;
}