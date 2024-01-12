#include<bits/stdc++.h>
using namespace std;

int a, b, c, cnt[10], r;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> a >> b >> c;
	r = a * b * c;
	
	while(r > 0)
	{
		int t = r % 10;
		
		cnt[t]++;
		
		r /= 10;
	}
	
	for(int i : cnt) cout << i << "\n";
	
	return 0;
}
