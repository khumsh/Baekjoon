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
	
	// �Ҽ� üũ 
	for (int i = 2; i <= n; i++)
	{
		if (che[i]) continue;
		for (int j = 2*i; j <= n; j += i)
		{
			che[j] = 1;
		}
	}
	
	// n ������ �Ҽ� v�� �ֱ� 
	for (int i = 2; i <= n; i++)
	{
		if (che[i]) continue;
		
		v.push_back(i);
	}
	
	
	int lo = 0, hi = 0, sum = 0, ret = 0;
	while (true)
	{
		if (sum >= n) // ���� n���� ũ�� 
		{
			// �� ���̱�
			sum -= v[lo];
			lo++; 
		}
		else // ���� n���� ������ 
		{
			// �� �ø��� �� ������ üũ 
			// �� �ø� �� ������ break; 
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
