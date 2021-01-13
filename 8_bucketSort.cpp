// 桶排序
# include<stdio.h>
# include<stdlib.h>


# define MAXSIZE 100
# define RANGE 1000

void swag(int &a,int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
    // printf("\nexchange %d  %d\n",*&a,*&b);
}

void sort(int *p){//
    
    int length = p[0];// 实际上是p[0]-1个等待排序元素 是一个  arr[length]的数组
    int i,temp,count=0;
    while (1)
    {
        for(i=1;i<length-1;i++){  // 对于待排序的length个元素，从1号索引开始
            if(p[i]>p[i+1]) {
                temp = p[i];p[i] = p[i+1];p[i+1] = temp;count++;
            }
        }
        if (count == 0) break;
        count = 0;
    }
}

void buckerSort(int *arr){
    int res,j;
    int *box[RANGE/MAXSIZE];//指针数组，数组里面存放的是指针
    
    // 给数组分配内存
    for(int i=0;i<RANGE/MAXSIZE;i++){
        box[i] = (int *)malloc((MAXSIZE+1)*sizeof(int));
        box[i][0] = 1;//第一个元素存放当前长度
    }    

    // 遍历arr 给box里面的数组赋值
    for(int i=0;i<MAXSIZE;i++){
        res = arr[i]/(RANGE/MAXSIZE);
        // 从1开始
        box[res][box[res][0]++] = arr[i];
    }

    // 遍历box，给里面长度超过2的数组排序
    for(int i=0;i<RANGE/MAXSIZE;i++){
        // printf("ere");
        if(box[i][0]>1) sort(box[i]);
    }


    // 遍历数组，给arr赋值
    for(int boxIndex=0,arrIndex = 0;boxIndex<RANGE/MAXSIZE;boxIndex++){
        for(int inBoxIndex=1;inBoxIndex<box[boxIndex][0];inBoxIndex++){
            arr[arrIndex++] = box[boxIndex][inBoxIndex];
        }
        
    }
    

}
int main(){
    int arr[MAXSIZE] = {29, 47, 1, 80, 90, 38, 56, 96, 96, 0, 58,
     71, 21, 70, 50, 11, 36, 1, 74, 53, 85, 79, 60, 44, 67, 43, 65,
      37, 70, 46, 0, 64, 23, 92, 20, 1, 93, 26, 34, 87, 33, 65, 70,
       61, 53, 21, 83, 77, 21, 83, 67, 43, 92, 84, 67, 76, 50, 30, 12,
        34, 88, 23, 11, 34, 41, 82, 54, 68, 3, 86, 0, 19, 57, 4, 30, 45,
         42, 54, 84, 3, 46, 21, 66, 28, 42, 84, 7, 91, 6, 81, 4, 44, 16,
          22, 57, 65, 89, 85, 76, 58};
    buckerSort(arr);
    for(int i=0;i<MAXSIZE;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 1;
}