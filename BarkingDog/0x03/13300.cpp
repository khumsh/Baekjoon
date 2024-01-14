#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k, s[1004], y[1004], res = 0;
	cin >> n >> k;
	
	for(int i = 0; i < n; i++)
		cin >> s[i] >> y[i]; // S => female : 0, male : 1
	
	for (int i = 1; i < 7; i++) // 1 ~ 6 year
	{
		int cnt_f = 0, cnt_m = 0;
		for (int j = 0; j < n; j++)
		{
			if (s[j] == 0 && y[j] == i) cnt_f++;
			else if (s[j] == 1 && y[j] == i) cnt_m++;
		}
		
		if (cnt_f % k == 0) res += cnt_f / k;
		else if (cnt_f % k != 0) res += cnt_f / k + 1;
		
		if (cnt_m % k == 0) res += cnt_m / k;
		else if (cnt_m % k != 0) res += cnt_m / k + 1;
			 
	}
	
	cout << res;
	
	return 0;
}
