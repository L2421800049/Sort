# include<stdio.h>
// 插入排序
int count = 0;
void show(int *p,int length){
    for(int i=0;i<length;i++){
         printf("%d ",p[i]);
    }
    printf("\n");
}

void swag(int &a,int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
    count++;
}

void choose(int *p,int length){
    show(p,length);
    int i,num,j;
    int *newp = p; // 指针指向p指针
    for(i=0;i<length-1;i++){   // 控制i 指针指向每一个元素
        for(j = i+1;j>0;j--)   // 控制j 指针 判断二者的值是否相等
            {   
                if(p[j]<p[j-1])
                swag(p[j],p[j-1]);
            }
    }
    show(p,length);
}


int main(){
    int nums[]={13,6,27,16,69,89,80,11,73,32,51,9,17,37,13,92,75};
    int length = sizeof(nums)/sizeof(int);
    choose(nums,length);
    printf("count is %d\n",count);
   // getchar();
    return 1;
}