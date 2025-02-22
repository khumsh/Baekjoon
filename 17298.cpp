#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> v;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// input
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		v.push_back(t);
	}
	
	vector<int> result(n, -1);
	stack<int> stk; // ��ū���� �������� ���� �ε��� ���� 
	
	for (int i = 0; i < n; i++)
	{	 
		// ������ ������� �ʰ�, ���� ���Ұ� ���� �ֻ�� �ε����� �ش��ϴ� ������ ũ�� 
		while (stk.size() && v[stk.top()] < v[i])
		{
			// ��ū�� ���� 
			result[stk.top()] = v[i];
			stk.pop();
		}
		
		stk.push(i);
	}
	
	for (int i = 0; i < n; i++)
	{
		cout << result[i] << " ";
	}
	
	
	return 0;
}
