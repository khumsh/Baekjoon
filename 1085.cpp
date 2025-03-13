#include<bits/stdc++.h>
using namespace std;

int x, y, w, h;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> x >> y >> w >> h;
	
	int mnX = min(x, w - x);
	int mnY = min(y, h - y);
	
	int ret = min(mnX, mnY);
	
	cout << ret << "\n";
	
	return 0;
}
