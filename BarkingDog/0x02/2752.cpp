#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a, b, c, minNum, maxNum, t;
	cin >> a >> b >> c;
	minNum = min({a, b, c});
	maxNum = max({a, b, c});
	t = a + b + c - minNum - maxNum;
	cout << minNum << ' ' << t << ' ' << maxNum;

	return 0;
}
