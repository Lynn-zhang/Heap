#include"Heap.hpp"
//#include"Heap(Less).hpp"


 /////*******for Heap.cpp**********//
void Test1()
{
	int arr[10] = { 10, 16, 18, 12, 11, 13, 15, 17, 14, 19 };
	Heap<int, Greater> hp(arr, 10);
	Heap<int> hp1(hp);
	Heap<int, Less> hp2(arr, 10);
	cout << hp.Top() << endl;;
	/*hp.Push(20);
	hp.Pop();*/

	/*PriorityQueue<int, Greater> pq;
	pq.Push(1);
	pq.Push(13);
	pq.Push(5);
	pq.Push(21);
	pq.Push(7);*/

}

///// for Heap(Less).cpp  ********************* //
//void Test2()   
//{
//	int arr[10] = { 20, 16, 18, 12, 11, 13, 15, 17, 14, 19 };
//	Heap<int> hp(arr, 10);
//	Heap<int> hp1(hp);
//	Heap<int> hp2(arr, 10);
//
//	cout<<hp.Top();
//	/*hp.Push(10);
//	hp.Pop();*/
//}


int main()
{
	Test1();
	//Test2();
	
	system("pause");
	return 0;
}