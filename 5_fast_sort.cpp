// 希尔排序
# include<stdio.h>
# include<stdlib.h>
int count=0;

void show(int *p,int length){
    for(int i=0;i<length;i++){
         printf("%d ",p[i]);
    }
    printf("\n");
}

void swap(int &a,int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
    printf("chage %d %d\n",a,b);
    count++;
}


int pivot;
// int L;
// int R;

int fast(int *p,int length,int base,int Lflag,int Rflag){
    pivot = p[base];//复制基准点值
    while(Lflag<Rflag){
        for(;Lflag<Rflag&&pivot<=p[Rflag];Rflag--); // 找到比high小的，等于也不行  
        p[Lflag] = p[Rflag];
        count++;
        for(;Lflag<Rflag&&pivot>=p[Lflag];Lflag++);
        p[Rflag] = p[Lflag];
        count++;
    }
    p[Lflag] = pivot;
    return Lflag;
}


int pivotPos;
void pa(int *p,int length,int base,int Lflag,int Rflag){
     if(Lflag<Rflag){
         pivotPos = fast(p,length,base,Lflag,Rflag);
         pa(p,length,Lflag,Lflag,pivotPos-1);  
         // low high 范围确定好
         // 父表的low high总是被左右子表调用
         // 基准点也作为左右子表的high和low部分
         pa(p,length,pivotPos+1,pivotPos+1,Rflag);
     }
}

int main(){
    int nums[]={13,6,27,16,69,89,80,11,73,32,51,9,17,37,13,92,75};
    int length = sizeof(nums)/sizeof(int);
    show(nums,length);
    int Lflag = 0;
    int base = Lflag;
    int Rflag = length-1;
    pa(nums,length,base,Lflag,Rflag);
    show(nums,length);
    printf("count is %d\n",count);
    return 1;
}