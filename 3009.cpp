#include<bits/stdc++.h>
using namespace std;
#define y1 aaa

int x, y, x1, y1, x2, y2, x3, y3;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	cin >> x3 >> y3;
	
	if (x1 == x2)
		x = x3;
	else if (x1 == x3)
		x = x2;
	else
		x = x1;
	
	if (y1 == y2)
		y = y3;
	else if (y1 == y3)
		y = y2;
	else
		y = y1;
	
	cout << x << " " << y << "\n";
	
	return 0;
}
