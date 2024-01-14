#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, v, cnt = 0;
	cin >> n;
	
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	
	cin >> v;
	
	for (int i = 0; i < n; i++) 
		if (v == a[i]) cnt++;
	
	cout << cnt;
	
	return 0;
}
