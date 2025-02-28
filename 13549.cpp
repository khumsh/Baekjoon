#include<bits/stdc++.h>
using namespace std;

// https://www.acmicpc.net/problem/13549

int n, k, visited[200004];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// input
	cin >> n >> k;
	
	//bfs
	visited[n] = 1;
	
	deque<int> dq;
	dq.push_back(n);
	
	while(dq.size())
	{
		int cur = dq.front();
		dq.pop_front();
		
		for (int next : {cur-1, cur+1, cur*2})
		{
			if (next < 0 || next > 200000) continue;
			
			if (next == cur*2)
			{
				if (visited[next] && visited[next] <= visited[cur]) continue;
				
				visited[next] = visited[cur];
				
				dq.push_front(next); // 우선순위 앞으로 
			}
			else
			{
				if (visited[next]) continue;
				
				visited[next] = visited[cur] + 1;
				
				dq.push_back(next); // 우선순위 뒤로 
			}
				
			
		}
	}
	
	// print
	cout << visited[k] - 1 << "\n";
    
	return 0;
}
