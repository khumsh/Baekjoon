#include<bits/stdc++.h>
using namespace std;

int n, len, lis[504];

const int INF = 1e9;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	vector<pair<int,int>> a(n);
	for (int i = 0; i < n; i++)
	{
		// 왼쪽 전봇대, 오른쪽 전봇대 
		cin >> a[i].first >> a[i].second;
	}
	
	// 왼쪽 전봇대 기준으로 정렬 
	sort(a.begin(), a.end());
	
	// 오른쪽 전봇대가 오름차순이면 교차안함.
	// => LIS (최장 증가 부분 수열) 
	fill(lis, lis + 504, INF);
	for (int i = 0; i < n; i++)
	{
		int pos = lower_bound(lis, lis + len, a[i].second) - lis;
		
		lis[pos] = a[i].second;
		
		if (pos == len) len++;
	}
	
	cout << n - len << "\n";
	
	return 0;
}
