#include<bits/stdc++.h>
using namespace std;

int n, k, a, b;
vector<pair<int,int>> v;
priority_queue<int> pq;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		// a : ����, b : ���� 
		cin >> a >> b;
		v.push_back({a, b});
	}
	
	vector<int> bag(k); 
	for (int i = 0; i < k; i++)
	{
		cin >> bag[i];
	}
	
	// ���� �������� ���� 
	sort(v.begin(), v.end()); 
	// ���� ���Դ� �����ͺ��� 
	sort(bag.begin(), bag.end());
	
	// ���� �������� ���� �� ���濡 ���� �� �ִ°� �� PQ�� ���.
	// �� ����� 1���� ���� �� �����Ƿ�, ���� �� �ִ� �� �߿� ���� ��Ѱɷ� ����.
	
	long long ret = 0;
	int j = 0;
	for (int i = 0; i < k; i++)
	{
		// i : ���� ���� �ε��� 
		while (j < n && v[j].first <= bag[i])
		{
			// ���� ���濡 ���� �� �ִ� ���� �� PQ�� �ֱ� 
			// ������ ���� ������ ���ĵǾ� �־ ���� ���濡�� ���� �� ���� 
			pq.push(v[j].second);
			j++;
		}
		
		// ���� ���濡 ���� �� �ִ� ���� �ĺ����� �ִٸ� 
		if (pq.size())
		{
			// ���� ��� ���� ���濡 �ֱ� 
			ret += pq.top();
			pq.pop();
		}
	}

	cout << ret << "\n"; 
	
	return 0;
}
