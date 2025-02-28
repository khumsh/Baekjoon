#include<bits/stdc++.h>
using namespace std;

// https://www.acmicpc.net/problem/1436

int t;

bool contain666(int number)
{
	string s = to_string(number);
	
	return s.find("666") != string::npos;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// input
	cin >> t;
	
	int n = 666;
	while(t > 0)
	{
		if (contain666(n))
		{
			t--;
			//cout << "t: " << t << ", n: " << n << "\n";
		}
			
		n++;
	}
	
	cout << n - 1 << "\n";
	
	return 0;	
}
