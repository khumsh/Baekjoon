#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
  	cin.tie(0);
  
	int a, b, c, d;
	for (int i = 0; i < 3; i++)
	{
		cin >> a >> b >> c >> d;
		int t = a + b + c + d;
		
		if (t == 3) cout << "A" << "\n";
		else if (t == 2) cout << "B" << "\n";
		else if (t == 1) cout << "C" << "\n";
		else if (t == 0) cout << "D" << "\n";
		else if (t == 4) cout << "E" << "\n";
		
	}
	
	return 0;
}
