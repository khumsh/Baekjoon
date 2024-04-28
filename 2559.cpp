#include <bits/stdc++.h>
using namespace std;
// 2559 ¼ö¿­ 

int n, k, a[100004];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int max, temp = 0;
	
	cin >> n >> k;
	
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	
	for (int i = 0; i < n-k+1; i++)
	{
		if (i == 0)
		{
			for (int j = i; j < k + i; j++)
				temp += a[j];
		}
		else
		{
			temp -= a[i-1];
			temp += a[i-1+k];
		}
		
		if (i == 0 || max < temp) max = temp;
		
		//cout << "i : " << i << ", temp : " << temp << ", max : " << max << "\n";
	}
	
	cout << max;
}
