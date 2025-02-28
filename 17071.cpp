#include<bits/stdc++.h>
using namespace std;

const int MAX = 500000;
int n, k, visited[MAX+4][2], t;

int getK(int time)
{
	return k + time * (time + 1) / 2;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// input
	cin >> n >> k;
	
	// bfs
	visited[n][0] = 1;
	t = 0;
	
	queue<int> q;
	q.push(n);
	
	while(q.size())
	{
		// t초 후 k의 위치 
		int targetPos = getK(t);
		
		// t초 후 타겟이 범위 밖으로 나가면 -1 출력 
		if (targetPos > MAX)
		{
			cout << -1 << "\n";
			return 0; 
		}
		
		// t초 후 타겟의 위치에 도달했다면 정답 출력
		if (visited[targetPos][t%2] > 0)
		{
			cout << t << "\n";
			break;
		}
		
		int qSize = q.size();
		// 현재 q에 있는 모든 위치들은 t초에 도달한 상태.
		// 이들을 확장하여 t+1초 후 도달 가능한 상태들을 구하기. 
		for (int i = 0; i < qSize; i++)
		{
			int cur = q.front();
			q.pop();
			
			for (int nxt : { cur-1, cur+1, cur*2 })
			{
				if (nxt < 0 || nxt > MAX) continue;
				if (visited[nxt][(t+1)%2] > 0) continue;
				
				// t+1초 후에 도달하는 곳에 도달 상태 체크 
				visited[nxt][(t+1)%2] = t + 1;
				q.push(nxt);
			}
		}
		
		t++;
	}
	
	return 0;
}
