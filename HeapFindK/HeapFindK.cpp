#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<assert.h>
using namespace std;

// �ҳ�n������ ��� ��ǰk����

void AdjustDown(int *array, int parent, int size)  // ��С�� ���������µ�
{
	int left = parent * 2 + 1;
	int right = left + 1;
	while (left < size)
	{
		// �Ƚ����Һ��ӣ���֤�±�leftΪ��С�Ľڵ��±�
		if (right <size && array[right] < array[left])
		{
			left = right;
		}
		// ������ڵ�������Һ����н�С�Ľڵ�ʱ���ͽ����������ڵ㣬Ҫ��֤�����ӽڵ㶼���ڸ��ڵ�
		if (left<size && array[parent]>array[left])
		{
			// ����֮������� ����Խϴ����ѭ�����µ�
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


