// 希尔排序
#include <windows.h>　
# include<stdio.h>

int count=0;

void show(int *p,int length){
    for(int i=1;i<length;i++){
         printf("%d ",p[i]);
    }
    printf("\n");
}

void swag(int &a,int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
    // printf("swap %d   |    %d\n",a,b);
    count++;
}


void shell(int *p,int length){
    // show(p,length);
    for(int d=length/2;d>=1;d/=2){
        for(int i=d+1;i<length;i++){
            for(int j=i;j>d;j-=d){
                if(p[j]<p[j-d]){
                    swag(p[j],p[j-d]);
                }
            }
        }
    }
    
    // int d,i,j;
    // for(d=length/2;d>=1;d/=2){
    //     for(i = d+1;i<=length;++i){
    //         if(p[i]<p[i-d]){
    //         p[0] = p[i];
    //         for(j=i-d;j>0&&p[0]<p[j];j-=d)
    //             p[j+d] = p[0];
    //         }
    //     }
    // }
    // show(p,length);

}

int main(){
    DWORD t1,t2;
    t1 = GetTickCount(); 
    int nums[]  = {1,5,6,2};
    int length = sizeof(nums)/sizeof(int);
    shell(nums,length);
    printf("len is %d count is %d\n",length,count);

    t2 = GetTickCount();
    printf("cost %lf",((t2-t1)*1.0/1000));
    getchar();
    
    return 1;
}