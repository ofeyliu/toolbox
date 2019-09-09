#include<iostream>
#include<map>
#include<vector>

using namespace std;
vector<int> twoSum(vector<int>& nums, int target)
{
	//vector<int> ::iterator it = nums.begin();
	vector<int> result;
	int count = 0;
	for (int i=0; i < nums.size(); i++)
	{
		int a = target - nums[i];
		for (int j = i+1; j < nums.size(); j++)
		{
			if (a == nums[j])
			{
				result.push_back(i);
				result.push_back(j);
			}
		}
	}
	return result;
}

int main()
{
	vector<int> nums = { 2, 7, 11, 15 };
	int t = 9;
	vector<int> result = twoSum(nums, t);
	for (int i = 0; i < result.size(); i=i+2)
	{
		cout << result[i] <<'\t'<<result[i+1]<< endl;
	}
	system("pause");

}
