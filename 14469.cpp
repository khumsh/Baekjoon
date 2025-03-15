#include<bits/stdc++.h>
using namespace std;
#define time aaa

int n, a, b, time;
vector<pair<int,int>> v;
priority_queue<int> pq;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		// a : 도착 시각, b : 검문 시간 
		cin >> a >> b;
		
		v.push_back({a, b});
	}
	
	// 도착 시각에 따라 정렬 
	sort(v.begin(), v.end());
	
	// 가장 먼저 도착한 소 검문 완료 시간으로 초기화. 
	time = v[0].first + v[0].second; 
	
	for (int i = 1; i < n; i++)
	{
		if (v[i].first > time) // 검문 완료까지 도착안했으면 
			time += v[i].first - time; // 도착시까지 대기 
			
		time += v[i].second;
	}
	
	cout << time << "\n";
	
	return 0;
} 
