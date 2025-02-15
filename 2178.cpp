#include<bits/stdc++.h>
using namespace std;

// https://www.acmicpc.net/problem/2178

int N, M, y, x;
int a[104][104], visited[104][104];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};


void bfs(int sy, int sx)
{
	visited[sy][sx] = 1;
	
	queue<pair<int,int>> q;
	q.push({sy, sx});
	while(q.size())
	{
		tie(y, x) = q.front();
		q.pop();
		
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
			if (a[ny][nx] == 0) continue;
			if (visited[ny][nx]) continue;
			
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ny, nx});
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// input
	scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            scanf("%1d", &a[i][j]);
        }
    } 
    
    // bfs	
	bfs(0, 0);
	
	cout << visited[N-1][M-1] << endl;
	
	return 0;
}
