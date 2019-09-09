
/*
** reference:http://www.cnblogs.com/kedebug/archive/2009/12/09/2791763.html
**
*/

#include <iostream>

#include <time.h>   //clock, gettimeofday, time
using namespace std;


class QuickSort
{
	const int arraySize;
	float  * array;
public:
	QuickSort(int arraySize);
	~QuickSort();
	void Initital();
	int Partition(int first, int last);
	void Quicksort(int first, int last);
	void Sort();
	void PrintIt();
};



QuickSort::QuickSort(int Size) :arraySize(Size)
{
}

void QuickSort::Initital()
{
	array = new float[arraySize];
	for (int i = 0; i < arraySize; i++)
	{
		cout << "Input the number " << i + 1 << " : ";
		cin >> array[i];
	}
	cout << "Entered !" << endl;
}

int QuickSort::Partition(int first, int last)
{
	int i, j;
	j = first - 1;
	for (i = first; i < last; i++)       //Partition的精华思想，把last当做是标准
	{
		if (array[i] < array[last])
		{
			j++;
			float temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}
	float temp = array[last];
	array[last] = array[++j];
	array[j] = temp;

	return j;
}

void QuickSort::Quicksort(int first, int last)
{
	int pivot;
	if (first < last)                           //算法的基本实现
	{
		pivot = Partition(first, last);
		Quicksort(first, pivot - 1);
		Quicksort(pivot + 1, last);
	}
}

void QuickSort::Sort()
{
	Quicksort(0, arraySize - 1);
}

void QuickSort::PrintIt()
{
	cout << "After QuickSort :" << endl;
	for (int i = 0; i < arraySize; i++)
	{
		cout << array[i] << "  ";
	}
	cout << endl;
}

QuickSort::~QuickSort()
{
	delete[]array;
}

int main()
{
	int size;
	cout << "Enter the size of the array : ";
	cin >> size;
	if (size > 0)
	{
		QuickSort sort(size);
		sort.Initital();
		clock_t startTime = clock();
		sort.Sort();
		clock_t endTime = clock();
		clock_t elapsed = endTime - startTime;
		cout << "time comsumption: " << elapsed<<endl;
		sort.PrintIt();
		system("pause");
	}
	return 0;
}
