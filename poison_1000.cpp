/*
*1000瓶药水，其中至多有1瓶剧毒，小狗服完药20小时后才能判断是否中毒。

*现在给你10只小狗、在24小时内、通过小狗试药的方式找出哪瓶药有毒或者全部无毒
*/


#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

class Tester
{
	bool  m_began;
	int   m_poison;
	bool  m_dogs[10];

public:
	Tester()
		: m_began(false)
	{
		this->begin();
		this->end();
	}

	void begin(int i = -1)
	{
		m_began = true;
		memset(m_dogs, 0, sizeof(m_dogs));
		m_poison = (i == -1 ? (rand() % 1000) + 1 : i);
	}

	void feed(int dog0to9, int bottle1to1000)
	{
		assert(m_began);
		if (bottle1to1000 == m_poison){
			m_dogs[dog0to9] = true;
		}
	}

	void end()
	{
		m_began = false;
	}

	bool query(int dog0to9)
	{
		assert(!m_began);
		return m_dogs[dog0to9];
	}

	void judge(int poison)
	{
		assert(!m_began);
		if (m_poison != poison){
			cerr << "test failed: estimate " << poison << ", fact " << m_poison << endl;
			exit(0);
		}
	}
};

void testCase(Tester & t, int x = -1)
{
	t.begin(x);
	for (int i = 1; i <= 1000; ++i){ // for each bottle
		for (int x = i, n = 0; x; x >>= 1, ++n){ // each bit
			if (x & 1){
				t.feed(n, i);
			}
		}
	}

	t.end();
	int id = 0;
	for (int i = 9; i >= 0; --i){
		id = (id << 1) | (t.query(i) ? 1 : 0);
	}

	t.judge(id);
}

int main()
{
	Tester t;

	// cover
	for (int x = 0; x < 1001; ++x){
		testCase(t, x);
	}

	// random test
	for (int x = 0; x < 100; ++x){
		testCase(t);
	}

	cout << "passed" << endl;

	return 0;
}
