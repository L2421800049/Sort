#pragma once
template <typename T>
struct HEAP
{                                  ////////////////////////
	int HeapSize;                  //数组中该堆元素的个数//
	int length;                    //     数组长度       //
	T* HeapArray = new T[length];  //   为数组分配内存   //
};                                 ////////////////////////

inline  int PARENT(int i) noexcept{ return (i+1)/2 - 1;   }
//返回i的父节点
inline  int LEFT  (int i) noexcept{ return 2*(i+1)-1;     }
//返回i的左子节点
inline  int RIGHT (int i) noexcept{ return 2*(i+1); }
//返回i的右子节点
template <typename T>                 ////////////////////////////////
void MAX_HEAPIFY(HEAP<T>& heap,int i);//维护最大堆性质（O(lgn)）    //
template <typename T>                 //                            //
void BUILD_MAX_HEAP(HEAP<T>& heap);   //建立一个最大堆（O(n)）      //
template <typename T>                 //                            //
void HEAPSORT(HEAP<T>& heap);         //堆排序<原址排序>（O(nlgn)） //
                                      ////////////////////////////////


/*___________________________________________*/
/*                                           */
/*    下面是利用堆排序建立一个最大优先队列   */
/*                                           */
/*___________________________________________*/


template <typename T>                        //_________________________________________________
void MAX_HEAP_INSERT(HEAP<T>& heap,T key);   // 将x插入到队列中（O(lgn)）
template <typename T>                        //
T HEAP_EXTRACT_MAX(HEAP<T>& heap);           //返回并去掉队列中具有最大关键词的元素（O(lgn)）
template <typename T>                        //
T HEAP_MAXIMUM(const HEAP<T>& heap);         //返回堆最大元素（O(1)）
template <typename T>                        //
bool HEAP_INCREASE_KEY                       //
(HEAP<T>& heap, int i, T key);               //将队列中下标为i的元素关键词增加到key（O(lgn)）
                                             //__________________________________________________