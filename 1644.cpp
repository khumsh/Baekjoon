#include<bits/stdc++.h>
using namespace std;

int n;
bool che[4000004];
vector<int> v;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	// 소수 체크 
	for (int i = 2; i <= n; i++)
	{
		if (che[i]) continue;
		for (int j = 2*i; j <= n; j += i)
		{
			che[j] = 1;
		}
	}
	
	// n 이하의 소수 v에 넣기 
	for (int i = 2; i <= n; i++)
	{
		if (che[i]) continue;
		
		v.push_back(i);
	}
	
	
	int lo = 0, hi = 0, sum = 0, ret = 0;
	while (true)
	{
		if (sum >= n) // 합이 n보다 크면 
		{
			// 값 줄이기
			sum -= v[lo];
			lo++; 
		}
		else // 합이 n보다 작으면 
		{
			// 값 늘리기 전 사이즈 체크 
			// 더 늘릴 수 없으면 break; 
			if (hi == v.size())
				break;
			
			sum += v[hi];
			hi++;
		}
					
		if (sum == n)
			ret++;
	} 
	
	cout << ret << "\n";
	
	
	return 0;
}
