#include <bits/stdc++.h>
using namespace std;
// 2309 �ϰ�������

int arr[9], sum;

pair<int, int> solve()
{
	// ��ü �տ��� 2�� ���� 100
	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < i; j++)
		{
			// 2�� ���� ������� �̱�
			if (sum - arr[i] - arr[j] == 100)
			{
				return {i, j};
			}  
		}
	} 
}

int main()
{
	vector<int> v;
	pair<int, int> p;
	
	for(int i = 0; i < 9; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	
	p = solve();
	for(int i = 0; i < 9; i++)
	{
		if (p.first == i || p.second == i) continue;
		v.push_back(arr[i]);
	}
	
	sort(v.begin(), v.end()); // �������� ���� 
	for(int i : v) cout << i << "\n";
	return 0;
}


