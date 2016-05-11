#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<assert.h>
using namespace std;

// 找出n个数中 最大 的前k个数

void AdjustDown(int *array, int parent, int size)  // 建小堆 将大数向下调
{
	int left = parent * 2 + 1;
	int right = left + 1;
	while (left < size)
	{
		// 比较左右孩子，保证下标left为最小的节点下标
		if (right <size && array[right] < array[left])
		{
			left = right;
		}
		// 如果父节点大于左右孩子中较小的节点时，就交换这两个节点，要保证两个子节点都大于父节点
		if (left<size && array[parent]>array[left])
		{
			// 交换之后还需继续 将相对较大的数循环向下调
			swap(array[left], array[parent]);
			parent = left;
			left = parent * 2 + 1;
			right = left + 1;
		}
		else
		{
			break;
		}
	}
}
void Print(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int*  HeapFindK(int* arr, int *heap,int size, int k)
{
	assert(arr);
	for (int i = 0; i < k; i++)
	{
		heap[i] = arr[i];
	}
	for (int start = (size - 1 - 1) / 2; start >= 0; start--)
	{
		AdjustDown(heap, start, k);
	}
	for (int begin = k; begin < size; begin++)
	{
		if (heap[0]<arr[begin])
		{
			heap[0] = arr[begin];
			AdjustDown(heap, 0, k);
		}
	}
	return heap;
}


void Test()
{
	int arr[10] = { 10, 16, 18, 12, 11, 13, 15, 17, 14, 19 };
	int heap[5] = { 0 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int k = 5;
	HeapFindK(arr, heap, size, k);
	Print(heap, k);
}
int main()
{
	Test();
	system("pause");
	return 0;
}


