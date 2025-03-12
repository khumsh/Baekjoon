#include<bits/stdc++.h>
using namespace std;

int a, b, c;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> a >> b;
	cin >> c;
	
	int now = a * 60 + b;
	int fin = now + c;
	
	int h = fin / 60;
	h %= 24;
		
	int m = fin % 60;
	
	cout << h << " " << m << "\n";
	
	return 0;
}
