#include<bits/stdc++.h>
using namespace std;

int n, m, visitedWater[1504][1504], visitedSwan[1504][1504], cnt;
char a[1504][1504];

queue<pair<int,int>> waterQ, waterNextQ, swanQ, swanNextQ;

vector<pair<int,int>> swanCell;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// input
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		
		for (int j = 0; j < m; j++)
		{
			a[i][j] = s[j];
			
			if (a[i][j] == 'L')
			{
				swanCell.push_back({i, j});
				a[i][j] = '.'; // 물로 취급
				
				visitedWater[i][j] = 1;
				waterQ.push({i, j});
			}
			else if (a[i][j] == '.')
			{
				visitedWater[i][j] = 1;
				waterQ.push({i, j});
			}
		}
	}
	
	//
	visitedSwan[swanCell[0].first][swanCell[0].second] = 1;
	swanQ.push(swanCell[0]);
	
	while (true)
	{
		// 백조 만날 수 있는지 체크 
		bool meet = false;
		while(swanQ.size())
		{
			int y, x;
			tie(y, x) = swanQ.front();
			swanQ.pop();
			
			if (y == swanCell[1].first && x == swanCell[1].second)
			{
				meet = true;
				break;
			}
			
			for (int i = 0; i < 4; i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];
				
				if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
				if (visitedSwan[ny][nx]) continue;
				
				visitedSwan[ny][nx] = 1;
				if (a[ny][nx] == '.')
				{
					// 물이면 그 날 큐에 넣기
					swanQ.push({ny, nx});
				}
				else if (a[ny][nx] == 'X')
				{
					// 얼음이면 다음날 녹으므로 다음날 큐에 넣기
					swanNextQ.push({ny, nx}); 
				}
			}
		}
		if (meet) break;
		
		while(waterQ.size())
		{
			int y, x;
			tie(y, x) = waterQ.front();
			waterQ.pop();
			
			for (int i = 0; i < 4; i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];
				
				if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
				if (visitedWater[ny][nx]) continue;
				if (a[ny][nx] == 'X')
				{
					visitedWater[ny][nx] = 1;
					
					// 물과 인접한 얼음 다음날 물 큐에 넣기 
					a[ny][nx] = '.';
					waterNextQ.push({ny, nx});					
				}
			}
		}
		
		// 다음날 큐 옮기기
		while(swanNextQ.size())
		{
			swanQ.push(swanNextQ.front());
			swanNextQ.pop();
		}
		
		while(waterNextQ.size())
		{
			waterQ.push(waterNextQ.front());
			waterNextQ.pop();
		}
		
		cnt++;
	}
	
	
	cout << cnt << "\n";
	
	return 0;
}
