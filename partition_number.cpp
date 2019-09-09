#include<iostream>
using namespace std;
// �洢���н�
int a[100];
// ���һ�����н�
void Output(int *a, int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
// ��֤��ǰ���Ƿ����
bool IsOk(int* a, int curIndex, int curValue)
{
	for (int i = 0; i < curIndex; ++i)
		if (a[i] == curValue)
			return false;
	return true;
}
// ����Ȼ��n���в�֣�t�������Ʋ�ָ���
void Partition(int n, int t, int *b)
{
	if (n < 0)
		return;
	if (n == 0) // �ҵ�һ�����
		Output(a, t); //���֮
	else
	{
		for (int i = 0; i < n; i++)
		{
			a[t] = b[i];
			if (IsOk(a, t, b[i]))
				Partition(n - b[i], t + 1, b);
		}
	}
}
int main(void)
{
	// ��������ļ��ϣ��൱�ڸ����������������ɸ�����Ŀ�����趨
	int b[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
	// ��������Ϊ10����b��ѡ���ɼ���Ʒ��ʹ��Щ��Ʒ����Ϊ10
	Partition(10, 0, b);
	system("pause");
	return 0;
}