#include<bits/stdc++.h>
using namespace std;

int n, cnt[30];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		string str1, str2;
		cin >> str1 >> str2;
		
		fill(cnt, cnt+30, 0);
		
		for (char c : str1) cnt[c - 'a']++;
		for (char c : str2) cnt[c - 'a']--;
		
		int maxN = *max_element(cnt, cnt+30);
		int minN = *min_element(cnt, cnt+30);
		
		if (maxN == 0 && minN == 0) cout << "Possible" << "\n";
		else cout << "Impossible" << "\n";
	}
	
	return 0;
}
