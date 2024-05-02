#include<bits/stdc++.h>
using namespace std;

long long a, b, c;

long long go(long long a, long long b)
{
	// (a * b) % c == ((a % c) * (b % c)) % c이므로
	// 숫자가 너무 커지지 않도록 미리 미리 나눠주기 
	
	if (b == 1) // 재귀함수 기저사례 
		return a % c; 
	
	long long ret = go(a, b / 2);
	ret = (ret * ret) % c;
	if (b % 2 != 0) // 홀수라면 한 번 더 곱해주기 
		ret = (ret * a) % c;
		
	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> a >> b >> c;
	
	cout << go(a, b) << "\n";
	return 0;
} 
