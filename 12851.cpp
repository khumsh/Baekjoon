#include<bits/stdc++.h>
using namespace std;

// https://www.acmicpc.net/problem/12851

int n, k, visited[100004], cnt[100004];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// input
	cin >> n >> k;
	
	// bfs
	visited[n] = 1;
	cnt[n] = 1;
	
	queue<int> q;
	q.push(n);
	
	while(q.size())
	{
		int here = q.front();
		q.pop();
		
		for (int i = 0; i < 3; i++)
		{
			int there;
			
			if (i == 0) there = here + 1;
			else if (i == 1) there = here - 1;
			else if (i == 2) there = here * 2;
			
			if (there < 0 || there > 100000) continue;
			if (!visited[there])
			{
				visited[there] = visited[here] + 1;
				q.push(there);
				cnt[there] += cnt[here];
			}
			else if (visited[there] == visited[here] + 1)
			{
				// 이미 갔던곳도 경우의 수 체크할 수 있게 
				cnt[there] += cnt[here]; 
			}
				
		}
		
	}
	
	cout << visited[k] - 1 << "\n";
	cout << cnt[k] << "\n";
	
	return 0;
}
