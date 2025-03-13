#include<bits/stdc++.h>
using namespace std;

int n, k, ret;
vector<int> v;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	v.push_back(1);
	
	int t = 2;
	while (t < n)
	{
		if (n % t == 0)
			v.push_back(t);
		
		t++;
	}
	v.push_back(n);
	
	if (v.size() < k)
		ret = 0;
	else
		ret = v[k-1];
	
	cout << ret << "\n";
	
	
	return 0;
}
