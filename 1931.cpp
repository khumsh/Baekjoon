#include<bits/stdc++.h>
using namespace std;

int n, a, b, lastTime,ret;
vector<pair<int,int>> v;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		// a : 회의 시작 시간, b : 회의 종료 시간 
		cin >> a >> b;
		
		v.push_back({b, a});
	}
	
	// 회의 종료 시간 기준으로 정렬 
	sort(v.begin(), v.end());
	
	lastTime = v[0].first;
	ret++;
	for (int i = 1; i < n; i++)
	{
		// 이전 회의 종료 이후에 다음 회의 시작
		if (lastTime <= v[i].second)
		{
			ret++;
			lastTime = v[i].first;
		}
	}
	
	cout << ret << "\n";
	
	return 0;
} 
