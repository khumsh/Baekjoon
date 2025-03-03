#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, mxCnt, a[300004];
ll ret = 1e18;

// 보석을 k로 나눌 수 있는지 확인. 
bool check(ll k)
{
	ll num = 0;
	for (int i = 0; i < m; i++)
	{
		num += a[i] / k;
		if (a[i] % k) num++;
	}
	
	return num <= n; // 보석을 전부 나눠줄 수 있을때만 true 
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// 질투심 최소값 구하기 문제...
	// 모든 질투심 구해서(for: 1 -> max ~~) 풀기엔 범위가 너무 넓음. (완전탐색 불가) 
	// => 질투심이 n일 때, 학생들이 같은 색상의 보석을 가져갈 수 있는지 확인하는 문제. 
	
	// 질투심이 n이면, 최대로 가져갈 수 있는 보석이 n이므로, 학생들의 수를 n명씩 나눌 수 있는지 확인.
	// 나눌 수 있으면 최소값 업데이트 후 더 작은 값으로 나눌 수 있는지 계속해서 확인.
	// 나눌 수 없어지면 최소값 출력. 
	
	// input
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a[i];
		
		mxCnt = max(mxCnt, a[i]);
	}
	
	//
	ll l = 1, r = mxCnt, mid;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (check(mid)) // 보석을 mid개로 나눠줄 수 있으면 
		{
			ret = min(ret, mid);
			r = mid - 1; // 더 작은 값이 있는지 찾기 
		}
		else // 나눠줄 수 없으면 더 큰값에서 찾기 
		{
			l = mid + 1;
		}
	}
	
	cout << ret << "\n";
	
	
	return 0;
}
