#include<bits/stdc++.h>
using namespace std;

string s, boom, ret;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s;
	cin >> boom;
	int boomLen = boom.size();
	for (int i = 0; i < s.size(); i++)
	{
		ret.push_back(s[i]);
		
		if (ret.size() >= boomLen && ret.substr(ret.size() - boomLen) == boom)
		{
			ret.erase(ret.size() - boomLen);
		}
	}
	
	if (ret == "")
		ret = "FRULA";
	
	cout << ret << "\n";
	
	return 0;
}
