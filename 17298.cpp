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
	stack<int> stk; // 오큰수가 결정되지 않은 인덱스 저장 
	
	for (int i = 0; i < n; i++)
	{	 
		// 스택이 비어있지 않고, 현재 원소가 스택 최상단 인덱스에 해당하는 값보다 크면 
		while (stk.size() && v[stk.top()] < v[i])
		{
			// 오큰수 저장 
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
