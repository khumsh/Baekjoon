#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// https://www.acmicpc.net/problem/3474

int n;

// n!의 오른쪽 끝에 있는 0의 개수 구하기
// 0은 10의 배수에서 나오며, 10은 2와 5의 곱
// n!에서는 2가 5보다 훨씬 많음
// 따라서, n!에 포함된 5의 개수를 구하면 됨. 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	while(n--)
	{
		ll num, cnt = 0;
		cin >> num;
		
		// 5의 거듭제곱을 계속 대입하며 num에 나눈 몫을 전부 더함 
		for (ll i = 5; i <= num; i *= 5)
		{
			cnt += num / i; 
		}

		cout << cnt << "\n";
	}
	
	
	return 0;
}
