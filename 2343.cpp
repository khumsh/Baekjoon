#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, mx, a[100004];
ll sum, ret = 1e18;

// 현재 용량(mid)로 m개 이하의 블루레이에 분할 가능한지 
bool check(int mid)
{
	int cnt = 1;
	ll currentSum = 0;
	for (int i = 0; i < n; i++)
	{
		if (currentSum + a[i] <= mid)
		{
			currentSum += a[i];
		}
		else
		{
			currentSum = a[i];
			cnt++;
		}
	}
	
	// m개 이하의 블루레이로 모든 강의를 담을 수 있으면 true 
	return cnt <= m;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// input
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		mx = max(mx, a[i]);
		sum += a[i];
	}
	
	//
	ll l = mx, r = sum, mid;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (check(mid)) // m개 이하로 모든 강의를 담을 수 있으면 용량 줄여보기 
		{
			ret = min(ret, mid); 
			r = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}
	
	cout << ret << "\n";
	
	return 0;
}
