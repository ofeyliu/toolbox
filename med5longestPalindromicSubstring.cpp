#include<iostream>
#include<string>
using namespace std;

int main()
{
	string test("bb");
	string result("");
	string set("");
	size_t pos,rPos;
	int max = 0;
	for (int i = 0; i < test.length(); ++i)
	{
		pos=set.find(test[i]);
		if (pos != string::npos)
			continue;
		set.push_back(test[i]);
		rPos = test.find_last_of(test[i]);
		if (rPos == string::npos || rPos-i<=0)
			continue;
		if (rPos - i > max)
		{
			max = rPos - i;
			result = test.substr(i, max+1);
		}
	}
	if ((max == 0)||(max==test.size())||(result.size()==test.size()))
		//return test[0];
		return 1;
	else
		//return result;
	cout << result << endl;
	
	return 0;

}