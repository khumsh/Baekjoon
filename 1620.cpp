#include<bits/stdc++.h>
using namespace std; 
// 1620 나는야 포켓몬 마스터 이다솜

int n, m;
string s, a[100004];
map<string, int> mp;
map<int, string> mp2;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		mp[s] = i + 1; // 1번부터 
		mp2[i+1] = s;
		a[i+1] = s;
	}
	
	for (int i = 0; i < m; i++)
	{
		cin >> s;
		// atoi(s.c_str()) == 0 => 문자열 
		// atoi(s.c_str()) != 0 => 숫자 
		
		if (atoi(s.c_str()) == 0) // 문자열일때 
		{
			cout << mp[s] << "\n"; // 숫자출력 
		}
		else // 숫자일때 
		{
			// 배열은 O(1)의 시간복잡도
			// map은 O(logN)의 시간복잡도
			
			// 배열이 더 빠르긴 하지만 map도 크게 차이나지는 않음
			// 원하는 걸로 쓰면 됨 
			
			cout << a[atoi(s.c_str())] << "\n"; // 문자열출력
			// cout << mp2[atoi(s.c_str())] << "\n"; 
		}
	}
	
}
