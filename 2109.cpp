#include<bits/stdc++.h>
using namespace std;

int n, d, p, ret;
vector<pair<int,int>> v;
priority_queue<int, vector<int>, greater<int>> pq; // �������� 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p >> d;
		
		v.push_back({d, p}); // ������ ���ؼ� day�� ������  
	}
	
	// day ���� �������� ����. 
	sort(v.begin(), v.end());
	
	for (int i = 0; i < n; i++)
	{
		pq.push(v[i].second); // pay�� pq�� �ֱ�
		if (pq.size() > v[i].first) 
		// ���� day������ pq ����� Ŀ������
		// day�ϱ����� �ִ� day��ŭ�� �ϸ� �� �� ����. (���� �Ϸ翡 �ִ� 1��) 
		{
			pq.pop(); // ���� ������ ���� �� ���� 
		} 
	}
	
	while (pq.size())
	{
		ret += pq.top();
		pq.pop();
	} 
	
	cout << ret << "\n";
	
	return 0;
}
