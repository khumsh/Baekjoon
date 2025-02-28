#include<bits/stdc++.h>
using namespace std;
#define prev aaa

// https://www.acmicpc.net/problem/13913

int n, k, visited[200004], prev[200004];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// input
	cin >> n >> k;
	
	//bfs
	visited[n] = 1;
	prev[n] = -1;
	
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
			prev[next] = cur;
			q.push(next);
		}
	}
	
	vector<int> v;
	
	for (int i = k; i != -1; i = prev[i])
	{
		v.push_back(i);
	}
	
	// print
	cout << visited[k] - 1 << "\n";
	
	for (int i = v.size()-1; i >= 0; i--)
	{
		cout << v[i] << " ";
	}
	
	
	return 0;
}
