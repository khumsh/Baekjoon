#include<bits/stdc++.h>
using namespace std;

int n, cnt[10], maxN;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	while(n > 0)
	{
		int t = n % 10;
		
		if (t == 6 && cnt[t] > cnt[9]) cnt[9]++;
		else if (t == 9 && cnt[t] > cnt[6]) cnt[6]++;
		else cnt[t]++;
		
		n /= 10;
	}
	
	for (int i = 0; i < 10; i++)
	{
		if (maxN < cnt[i]) maxN = cnt[i];
	}
	
	cout << maxN;
	
	return 0;
}
