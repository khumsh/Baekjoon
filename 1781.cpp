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
		// a : 데드라인, b : 보상 
		cin >> a >> b;
		
		v.push_back({a, b});
	}
	
	// 데드라인 기준으로 정렬 
	sort(v.begin(), v.end());
	
	for (int i = 0; i < n; i++)
	{
		pq.push(v[i].second);
		if (pq.size() > v[i].first)
		{
			// 데드라인 넘겼으면 보상 가장 작은거 빼기
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
