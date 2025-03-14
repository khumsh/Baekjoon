#include<bits/stdc++.h>
using namespace std;

int n, d, p, ret;
vector<pair<int,int>> v;
priority_queue<int, vector<int>, greater<int>> pq; // 오름차순 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p >> d;
		
		v.push_back({d, p}); // 정렬을 위해서 day를 앞으로  
	}
	
	// day 기준 오름차순 정렬. 
	sort(v.begin(), v.end());
	
	for (int i = 0; i < n; i++)
	{
		pq.push(v[i].second); // pay값 pq에 넣기
		if (pq.size() > v[i].first) 
		// 만약 day값보다 pq 사이즈가 커버리면
		// day일까지는 최대 day만큼의 일만 할 수 있음. (일은 하루에 최대 1개) 
		{
			pq.pop(); // 제일 수익이 낮은 일 제거 
		} 
	}
	
	while (pq.size())
	{
		ret += pq.top();
		pq.pop();
	} 
	
	cout << ret << "\n";
	
	return 0;
}
