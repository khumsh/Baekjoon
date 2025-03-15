#include<bits/stdc++.h>
using namespace std;

int n, a, b, ret;
vector<pair<int,int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		// a : �������, b : ���� 
		cin >> a >> b;
		
		v.push_back({a, b});
	}
	
	// ������� �������� ���� 
	sort(v.begin(), v.end());
	
	for (int i = 0; i < n; i++)
	{
		pq.push(v[i].second);
		if (pq.size() > v[i].first)
		{
			// ������� �Ѱ����� ���� ���� ������ ����
			pq.pop();
		}
	} 
	
	while(pq.size())
	{
		ret += pq.top();
		pq.pop();
	}
	
	cout << ret << "\n";
	
	return 0;
}
