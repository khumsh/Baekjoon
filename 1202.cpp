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
		// a : 무게, b : 가격 
		cin >> a >> b;
		v.push_back({a, b});
	}
	
	vector<int> bag(k); 
	for (int i = 0; i < k; i++)
	{
		cin >> bag[i];
	}
	
	// 무게 기준으로 정렬 
	sort(v.begin(), v.end()); 
	// 가방 무게는 낮은것부터 
	sort(bag.begin(), bag.end());
	
	// 무게 기준으로 정렬 후 가방에 담을 수 있는거 다 PQ에 담기.
	// 각 가방당 1개씩 넣을 수 있으므로, 담을 수 있는 것 중에 가장 비싼걸로 선택.
	
	long long ret = 0;
	int j = 0;
	for (int i = 0; i < k; i++)
	{
		// i : 현재 가방 인덱스 
		while (j < n && v[j].first <= bag[i])
		{
			// 현재 가방에 넣을 수 있는 보석 다 PQ에 넣기 
			// 가방은 무게 순으로 정렬되어 있어서 다음 가방에도 넣을 수 있음 
			pq.push(v[j].second);
			j++;
		}
		
		// 만약 가방에 넣을 수 있는 보석 후보군이 있다면 
		if (pq.size())
		{
			// 제일 비싼 보석 가방에 넣기 
			ret += pq.top();
			pq.pop();
		}
	}

	cout << ret << "\n"; 
	
	return 0;
}
