#include<bits/stdc++.h>
using namespace std;

// https://www.acmicpc.net/problem/1697

int n, k, visited[200004];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// input
	cin >> n >> k;
	
	//bfs
	visited[n] = 1;
	
	queue<int> q;
	q.push(n);
	
	while(q.size())
	{
		int cur = q.front();
		q.pop();
		
		for (int next : {cur-1, cur+1, cur*2})
		{
			if (next < 0 || next >= 200000) continue;
			if (visited[next]) continue;
			
			visited[next] = visited[cur] + 1;
			q.push(next);
		}
	}
	
	// print
	cout << visited[k] - 1 << "\n";
    
	return 0;
}
