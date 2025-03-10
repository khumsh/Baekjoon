#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll s, c, sum, a[1000004];

bool check(ll mid)
{
	ll res = 0;
	for (int i = 0; i < s; i++)
	{
		res += a[i] / mid; 
	}
	
	//cout << "mid: " << mid << ", res: " << res << "\n";
	
	//  mid만큼의 길이로 파닭을 c개 이상 만들 수 있으면 true 
	return res >= c;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s >> c;
	for (int i = 0; i < s; i++)
	{
		cin >> a[i];
		
		sum += a[i];
	}
	
	ll l = 1, r = 1e9, mid, res = 1;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (check(mid))
		{
			// 파닭에 쓸 파의 길이를 더 늘려보기 
			res = mid;
			l = mid + 1;
		}
		else
		{
			// 파닭 c개 제조 불가 
			// 파 길이 좀 더 줄여보기 
			r = mid - 1;
		}
	}
	
	cout << sum - res * c << "\n";
	
	
	return 0;
}
