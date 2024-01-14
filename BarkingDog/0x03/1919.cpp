#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string str1, str2;
	cin >> str1 >> str2;
	
	int res = 0, cnt[26] = {};
	
	for (char c : str1) cnt[c - 'a']++;
	for (char c : str2) cnt[c - 'a']--;
	
	for (int i = 0; i < 26; i++)
	{
		if (cnt[i] > 0) res += cnt[i];
		else res += cnt[i] * (-1);
	}
	
	cout << res;
	
	return 0;
}
