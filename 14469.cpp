#include<bits/stdc++.h>
using namespace std;
#define time aaa

int n, a, b, time;
vector<pair<int,int>> v;
priority_queue<int> pq;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		// a : ���� �ð�, b : �˹� �ð� 
		cin >> a >> b;
		
		v.push_back({a, b});
	}
	
	// ���� �ð��� ���� ���� 
	sort(v.begin(), v.end());
	
	// ���� ���� ������ �� �˹� �Ϸ� �ð����� �ʱ�ȭ. 
	time = v[0].first + v[0].second; 
	
	for (int i = 1; i < n; i++)
	{
		if (v[i].first > time) // �˹� �Ϸ���� ������������ 
			time += v[i].first - time; // �����ñ��� ��� 
			
		time += v[i].second;
	}
	
	cout << time << "\n";
	
	return 0;
} 
