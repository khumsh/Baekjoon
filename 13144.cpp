#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, a[100004], cnt[100004];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	
	
	ll l = 0, ret = 0;
	for (int r = 0; r < n; r++)
	{
		// 카운트 증가 
		cnt[a[r]]++;
		
		// 카운트가 2회 이상일 시
		// 중복 없도록 왼쪽 포인터 조정
		while (cnt[a[r]] > 1)
		{
			cnt[a[l]]--;
			l++;
		}
		
		// 구간 내 개수 세기
		// [l, r] 구간은 중복 없음. 
		// 오른쪽 끝을 r로 고정하면, 왼쪽 끝은 l에서 r까지 가능 
		ret += (r - l + 1);
	}
	
	cout << ret << "\n";
	
	return 0;
}
