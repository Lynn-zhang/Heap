#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;

//��������������ʵ�ִ�С��

template<class T>
struct Less
{
	bool operator()(const T& left, const T& parent)
	{
		return left < parent;
	}
};

template<class T>
struct Greater
{
	bool operator()(const T& left, const T& parent)
	{
		return left>parent;
	}
};

//template<class T>
template <class T, template<class> class Compare = Greater>  //Ĭ��ʵ�ִ��
class Heap
{
public:
	Heap()
	{}
	//���캯��
	Heap(const T* array,size_t size)
	{
		for (size_t i = 0; i < size; i++)
		{
			_array.push_back(array[i]);
		}
		//����
		for (int start = (_array.size() - 1 - 1) / 2; start >= 0; --start)
		{
			// �������� �� �ӵ�һ���к��ӵĸ��ڵ㿪ʼ �����µ�����
			AdjustDown(start);
		}
	}
	//��������
	Heap(const Heap& hp)
	{
		//_array.reserve(hp._array.size());
		for (size_t i = 0; i < hp._array.size(); i++)
		{
			_array.push_back(hp._array[i]);
		}
	}
	//��ֵ���������
	Heap &operator=(Heap hp)
	{
		if (this->_array != hp._array)
		{
			swap(hp._array, _array);
		}
		return *this;
	}
	//�������
	void Push(const T x)
	{
		// β�� Ȼ�� �ϵ�
		_array.push_back(x);
		AdjustUp(_array.size() - 1);
	}
	//ɾ���Ѷ�
	void Pop()
	{
		swap(_array[0], _array[_array.size() - 1]);
		//_array[0] = _array[_array.size() - 1];
		_array.pop_back();
		AdjustDown(0);
	}
	//���ʸ��ڵ�
	T& Top()
	{
		assert(_array.size()>0);
		return _array[0];
	}
protected:
	//�ϵ�
	void AdjustDown(int parent)    // ��С�� ���������µ�������� ��С�����µ���
	{
		size_t left = parent * 2 + 1;
		size_t right = left + 1;
		Compare<T> cp;           //����Ǵ�Ѵ����������ô�ѵ��߼���С�Ѿ�ʵ��С�ѵ��߼�
		while (left < _array.size())
		{
			// �Ƚ����Һ��ӣ���֤�±�leftΪ��С��ϴ�Ľڵ��±�
			if (right < _array.size() && cp(_array[right] , _array[left]))
			{
				left = right;
			}
			if (left<_array.size() && cp(_array[left], _array[parent]))
			{
				// ����֮������� ����Խϴ����Խ�С����ѭ�����µ�
				swap(_array[left], _array[parent]);
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
	//�ϵ�
	void AdjustUp(int child)
	{
		// ����β�����x ���������Ѿ����ն������ź��� ����ֻ�轫�ո�β�����x�������ϵ� ֱ�������ŵ����ʵ�λ��  
		int parent = (child - 1) / 2;
		Compare<T> cp;  //����Ǵ�Ѵ����������ô�ѵ��߼���С�Ѿ�ʵ��С�ѵ��߼�
		while (child>0)
		{
			if (cp( _array[child],_array[parent]))
			{
				swap(_array[parent], _array[child]);
				child = parent;
				parent = (child - 1) / 2;
			}
			else
			{
				// ������������˵�������Ѿ��źã����������С��x
				break;
			}
		}
	}
private:
	vector<T> _array;   //��vector�洢��������
};

template <class T, template<class> class Compare = Greater>
class PriorityQueue
{
public:
	void Push(const T x)
	{
		_heap.Push(x);
	}
	void Pop()
	{
		_heap.Pop();
	}
	T& Top()
	{
		return _heap.Top();
	}
protected:
	Heap<T, Compare> _heap;
};


