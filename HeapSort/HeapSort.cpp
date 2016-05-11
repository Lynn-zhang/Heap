#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<assert.h>
using namespace std;

//������

//�µ�
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
//��ӡ
void Print(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
//������
int* HeapSort(int *heap, int size)
{
	for (int start = (size - 1 - 1) / 2; start >= 0; start--)
	{
		AdjustDown(heap, start, size);
	}
	for (int i = size - 1; i >= 0; --i)
	{
		swap(heap[0], heap[i]);
		AdjustDown(heap, 0, i);
	}
	return heap;
}


void Test()
{
	int arr[10] = { 10, 16, 18, 12, 11, 13, 15, 17, 14, 19 };
	int size = sizeof(arr) / sizeof(arr[0]);
	HeapSort(arr, size);
	Print(HeapSort(arr, size), size);
}
int main()
{
	Test();
	system("pause");
	return 0;
}