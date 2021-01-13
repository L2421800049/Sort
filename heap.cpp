#include"HEAP.h"
#include<exception>
#include<climits>
#include<cfloat>
#include<cstdlib>
#include<iostream>

template <typename T>
void MAX_HEAPIFY(HEAP<T>& heap, int i)
{
	int left = LEFT(i);
	int right = right(i);
	int largest;
	if (left <= heap.HeapSize&&heap.HeapArray[left] > heap.HeapArray[i])
		largest = left;
	else
		largest = i;
	if (right <= heap.HeapSize&&heap.HeapArray[right] > heap.HeapArray[largest])
		largest = right;
	if (largest != i)
	{
		auto exchange = heap.HeapArray[i];
		heap.HeapArray[i] = heap.HeapArray[largest];
		heap.HeapArray[largest] = exchange;
	}
	MAX_HEAPIFY(heap, largest);
}
template <typename T>
void BUILD_MAX_HEAP(HEAP<T>& heap)
{
	heap.HeapSize = heap.length;
	for (int i = (heap.length + 1) / 2 - 1 ; i >= 0; i--)
		MAX_HEAPIFY(heap, i);
	return;
}
template <typename T>
void HEAPSORT(HEAP<T>& heap)
{
	for (int i = heap.length-1; i > 0; i--)
	{
		auto exchange = heap.HeapArray[i];
		heap.HeapArray[i] = heap.HeapArray[0];
		heap.HeapArray[0] = exchange;
	}
	heap.HeapSize--;
	MAX_HEAPIFY(heap, 1);
}
template <typename T>
T HEAP_MAXIMUM(const HEAP<T>& heap)
{
	return heap.HeapArray[0];
}
template <typename T>
T HEAP_EXTRACT_MAX(HEAP<T>& heap)
{
	try 
	{
		if (heap.HeapSize < 1)
			throw("heap underflow");
	}
	catch(const char*)
	{
		std::cout << "heap underflow\n";
		std::abort();
	}
	auto max = heap.HeapArray[0];
	heap.HeapArray[0] = heap.HeapArray[heap.HeapSize - 1];
	heap.HeapSize--;
	MAX_HEAPIFY(heap, 0);
	return max;
}
template <typename T>
bool HEAP_INCREASE_KEY(HEAP<T>& heap, int i, T key)
{
	i--;
	try
	{
		if (key < heap.HeapArray[i])
			throw("new key is smaller than current key");
	}
	catch(const char*)
	{
		std::cout << "new key is smaller than current key\n";
		std::abort();
	}
	heap.HeapArray[i] = key;
	while (i > 0 && heap.HeapArray[PARENT(i)] < heap.HeapArray[i])
	{
		auto exchange = heap.HeapArray[i];
		heap.HeapArray[i] = heap.HeapArray[PARENT(i)];
		heap.HeapArray[PARENT(i)] = exchange;
		i = PARENT(i);
	}
	return true;
}
template <typename T>
void MAX_HEAP_INSERT(HEAP<T>& heap, T key)
{
	int i = heap.HeapSize++;
	heap.HeapArray[i] = key;
	while (i > 0 && heap.HeapArray[PARENT(i)] < heap.HeapArray[i])
	{
		auto exchange = heap.HeapArray[i];
		heap.HeapArray[i] = heap.HeapArray[PARENT(i)];
		heap.HeapArray[PARENT(i)] = exchange;
		i = PARENT(i);
	}
}