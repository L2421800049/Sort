// 二路归并排序
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 10
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

int len(int *arr){
    int length= 0;
    while (arr[length]!=NULL) length++;
    return length;
}

void show(int *arr,int length){
    printf("\n");
    for(int i=0;i<length;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}



void merge(int *arr1,int *arr2,int *newArr){
    int i=0,j=0,k=0;
    while(i<len(arr1)&&j<len(arr2)){
        // printf("arr1[i]%d ,arr2[j]%d\n",arr1[i],arr2[j]);
        if(arr1[i]<arr2[j]){
            newArr[k++] =arr1[i++]; 
        }
        else if(arr1[i]>arr2[j]){
            newArr[k++] = arr2[j++];
        }
        else{
            newArr[k++] =arr1[i++]; 
            newArr[k++] = arr2[j++];
        }    
        // printf("i:%d j:%d\n",i,j);
    }
    if(i<len(arr1)){
        while(k<(len(arr1)+len(arr2))){
            newArr[k++] = arr1[i++];
        }
    }else{ 
        while(k<(len(arr1)+len(arr2))){
            newArr[k++] = arr2[j++];
        }
    }
}



int main(){
    // 冒泡排序得到俩个有序序列
    int arr1[]={13,6,27,16,69,89,80,11,73,32,51,9,17,37,13,92,75};
    bubble(arr1,len(arr1));

    int arr2[] = {99,53,13,62,44,84,61,51,17,16};
    bubble(arr2,len(arr2));

    int arr3[] = {13,6,27,16,69,89,80,11,73,32,51,9,17,37,13,92,75,99,53,13,62,44,84,61,51,17,16};
    bubble(arr3,len(arr3));
    
    printf("shoule be \n");
    show(arr3,len(arr3));
   
    int newLength = len(arr1)+len(arr2);
    int newArr[newLength];
    merge(arr1,arr2,newArr);
    show(newArr,newLength);
    return 0;
}