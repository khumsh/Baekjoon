#include<bits/stdc++.h>
using namespace std;

int n, a, b, lastTime,ret;
vector<pair<int,int>> v;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		// a : ȸ�� ���� �ð�, b : ȸ�� ���� �ð� 
		cin >> a >> b;
		
		v.push_back({b, a});
	}
	
	// ȸ�� ���� �ð� �������� ���� 
	sort(v.begin(), v.end());
	
	lastTime = v[0].first;
	ret++;
	for (int i = 1; i < n; i++)
	{
		// ���� ȸ�� ���� ���Ŀ� ���� ȸ�� ����
		if (lastTime <= v[i].second)
		{
			ret++;
			lastTime = v[i].first;
		}
	}
	
	cout << ret << "\n";
	
	return 0;
} 
