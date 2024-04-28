#include<bits/stdc++.h>
using namespace std;
// 9375 ÆÐ¼Ç¿Õ ½ÅÇØºó 

int c, n;
string a, b;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> c;
	
	for (int i = 0; i < c; i++)
	{
		map<string, int> m;
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			cin >> a >> b;
			m[b]++;
		}
		long long ret = 1;
		for(auto c : m)
		{
			ret *= ((long long)c.second + 1);
		}
		
		ret -= 1;
		cout << ret << "\n";
	}
}
