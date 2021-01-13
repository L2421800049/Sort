# include<stdio.h>
// 选择排序
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
}

void choose(int *p,int length){
    int i,j,min,minp,count=0;
    // i 外层循环 j 内层循环 min 最小值 minp 最小值指针 
    show(p,length);
    for(i=0;i<length;i++){
        min = p[i];
        minp = i;
        for(j=i+1;j<length;j++){
            if(p[j]<min){
                minp = j;
                min = p[j];
            }
        }
        if(i!=minp)
            {
                swag(p[i],p[minp]);
                count++;
            }
    }
    show(p,length);
    printf("count is %d\n",count);
}

int main(){
    int nums[]={13,6,27,16,69,89,80,11,73,32,51,9,17,37,13,92,75};
    int length = sizeof(nums)/sizeof(int);
    choose(nums,length);
    return 1;
}