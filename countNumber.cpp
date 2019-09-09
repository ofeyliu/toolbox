// 利用二分查找，找到之后再分别利用二分查找，找出第一次出现的位置和最后一次出现的位置  

#include<iostream>  
#include<algorithm>  
#include<time.h>  
using namespace std;

int* findFirst(int * arr, int size, int target) {
	if (arr == NULL || size <= 0) {
		return NULL;
	}
	int * mid = arr + (size >> 1);
	if (*mid > target) {
		return findFirst(arr, mid - arr, target);
	}
	else if (*mid < target) {
		return findFirst(mid + 1, size - (mid - arr) - 1, target);
	}
	else {
		if (mid == arr || mid > arr && *(mid - 1) < target) {  //  注意边界条件检查 mid == arr （mid为第一个）  
			return mid;
		}
		else {
			return findFirst(arr, mid - arr, target);  // 利用二分查找向前找第一个  
		}
	}
}

int * findLast(int * arr, int size, int target) {
	if (arr == NULL || size <= 0) {
		return NULL;
	}
	int * mid = arr + (size >> 1);
	if (*mid > target) {
		return findLast(arr, mid - arr, target);
	}
	else if (*mid < target) {
		return findLast(mid + 1, size - (mid - arr) - 1, target);
	}
	else {
		if (mid == arr + size - 1 || mid < arr + size && *(mid + 1) > target) { //  mid == arr + size - 1  （mid为最后一个）  
			return mid;
		}
		else {
			return findLast(mid + 1, size - (mid - arr) - 1, target);  //  利用二分查找向后找最后一个  
		}
	}
}

int getCount(int * arr, int size, int target) {
	int * first = findFirst(arr, size, target);
	int * last = findLast(arr, size, target);
	if (first == NULL || last == NULL) {  // 注意不存在的情况  
		return 0;
	}
	return last - first + 1;
}

void printArr(int * arr, int size) {
	for (int i = 0; i < size; ++i) {
		cout << *(arr + i) << " ";
	}
	cout << endl;
}

int main() {
	srand((int)time(0));
	const int SIZE = 20;
	int arr[SIZE];
	for (int i = 0; i < SIZE; i++) {
		arr[i] = rand() % SIZE;
	}
	printArr(arr, SIZE);
	sort(arr, arr + SIZE);
	printArr(arr, SIZE);
	int target = 0;
	int cnt = SIZE >> 1;
	while (cnt--) {
		cout << "Input target: ";
		cin >> target;
		cout << target << "'s count: " << getCount(arr, SIZE, target) << endl;
	}
	return 0;
}