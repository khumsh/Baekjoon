#include <bits/stdc++.h>
using namespace std;
// 10808 ¾ËÆÄºª °³¼ö 
string input;
int cnt[26]; 

int main()
{
	cin >> input;
	
	for(char a : input)
	{
		cnt[a - 'a']++;
	}
	
	for(int i = 0; i < 26; i++)
		cout << cnt[i] << " ";
		
	
	
	return 0;
}
