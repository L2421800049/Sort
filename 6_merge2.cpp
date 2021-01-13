// 二路迭代归并
# include<stdio.h>
# include<stdlib.h>

# define elemType int
# define MAXSIZE 27

int len(int *arr){
    int length= 0;
    while (arr[length]!=NULL) length++;
    return length;
}

void show(int *arr,int length){
    for(int i=0;i<length;i++){
        printf("%d ",arr[i]);
    }
    printf("\n\n");
}
elemType *temp = (elemType *)malloc(MAXSIZE*sizeof(elemType));   // 申请中间数组内存空间

void initTemp(int *arr){
    for(int i=0;i<MAXSIZE;i++){
        arr[i]=-1;
    }
}

void merge(int *arr,int mid,int left,int right){
    // printf("%d %d %d\n",left,mid,right);
    // arr1 left-mid  || arr2 mid+1-right

    // 0 0 1
    int i=left,j=mid+1,t=left;

    //copy
    while(left<=right){temp[left++]=arr[left];}

    // printf("left:%d mid:%d right:%d\n",left,right);
    // printf("i:%d j:%d t:%d\n",i,j,t);
    
    // 索引没有越界
    while (i<=mid&&j<=right)  
    {
        //如果左边的数组值小于右边
        // printf("temp[i]<temp[j]? %d\n",temp[i]<temp[j]);
        if(temp[i]<temp[j]){  
            //新数组的对应索引值为左边数组的值
            arr[t++] = temp[i++];
        }else if(temp[i]>temp[j]){
            //上述不成立，则为右边数组的值
            arr[t++] = temp[j++];
        }else{
            //如果俩个值相等，则同时添加俩个元素，并且保证稳定性
            arr[t++] =temp[i++]; 
            arr[t++] = temp[j++];
        }
    }

    // 越界之后的判断
    // 左子数组索引小于mid，则右边的数组越界
    if(i<=mid){  
        //新数组的索引小于右边数组的最大值
        while(t<=right){ 
             // 索引自加
            arr[t++] = temp[i++]; 
        }
    }else{
        while(t<=right){
            arr[t++] = temp[j++];
        }
    }
    
}

void mergeSort(int *arr,int left,int right){
    if(left<right){
        int mid = (right+left)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        // printf("merge %d to %d\n",left,right);
        merge(arr,mid,left,right);
        // show(arr,MAXSIZE);
    }
}

void bubble(int *p,int length){

    int i,temp,count=0;
    while (1)
    {
        for(i=0;i<length-1;i++){
            if(p[i]>p[i+1]) {
                temp = p[i];p[i] = p[i+1];p[i+1] = temp;count++;
            }
        }
        if (count == 0) break;
        count = 0;
    }
}

int main(){
    elemType arr[MAXSIZE] = {13,6,27,16,69,89,80,11,73,32,51,9,17,37,13,92,75,99,53,13,62,44,84,61,51,17,16};
    initTemp(temp);
    show(temp,MAXSIZE);
    show(arr,MAXSIZE);
    mergeSort(arr,0,MAXSIZE-1);
    printf("===========================merge================================\n");
    show(arr,MAXSIZE);

    printf("===========================bubble===============================\n");
    elemType arr2[MAXSIZE] = {13,6,27,16,69,89,80,11,73,32,51,9,17,37,13,92,75,99,53,13,62,44,84,61,51,17,16};
    bubble(arr2,MAXSIZE);
    show(arr2,MAXSIZE);
    return 0;
}