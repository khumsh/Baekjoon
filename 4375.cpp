#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// 4375 1

int n;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	while(cin >> n)
	{
		ll cnt = 1, ret = 1;
		while(true)
		{
			if (cnt % n == 0) // cnt�� n�� ������ 
			{
				cout << ret << "\n";
				break;
			}
			else // cnt�� n�� ����� �ƴ϶�� 
			{
				cnt = cnt * 10 + 1;
				cnt %= n;
				ret++;
			}
		}
	}
	
	return 0;
}
