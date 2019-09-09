#include <ctime>
#include <iostream>
#include <chrono>   
#include <ratio>
#include <thread>

using namespace std;
using namespace chrono;

void f()
{
	std::this_thread::sleep_for(std::chrono::seconds(1));
}


int main()
{
	clock_t start = clock();
	auto start2 = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < 30; i++)
	{
		f();
	}
	clock_t end = clock();
	cout << "花费了" << (double)(end - start) / CLOCKS_PER_SEC << "秒" << endl;

	auto end2 = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<microseconds>(end2 - start2);
	cout << "花费了"
		<< double(duration.count()) * microseconds::period::num / microseconds::period::den
		<< "秒" << endl;
}
