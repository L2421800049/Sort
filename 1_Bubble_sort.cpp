// bubble 冒泡排序
#include<stdio.h>

void show(int *p,int length){
    for(int i=0;i<length;i++){
         printf("%d ",p[i]);
    }
    printf("\n");
}

void bubble(int *p,int length){
    show(p,length);
    int i,temp,count=0,totol = 0;
    while (1)
    {
        for(i=0;i<length-1;i++){
            if(p[i]>p[i+1]) {
                temp = p[i];p[i] = p[i+1];p[i+1] = temp;count++;totol++;
            }
        }
        if (count == 0) break;
        count = 0;
    }
    show(p,length);
    printf("bubble totle is %d\n",totol);
}

int main(){
    int nums[]={13,6,27,16,69,89,80,11,73,32,51,9,17,37,13,92,75};
    int length = sizeof(nums)/sizeof(int);
    bubble(nums,length);
    return 1;
}