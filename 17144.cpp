#include<bits/stdc++.h>
using namespace std;

int n, m, t, x, y, a[54][54];

pair<int,int> topAir, bottomAir, airDir[54][54];

queue<pair<int,int>> q;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

struct spreadInfo
{
	int y;
	int x;
	int value;
};

void spread()
{
	vector<spreadInfo> oriV;
	vector<spreadInfo> spreadV;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] > 0)
				q.push({i, j});
		}
	}
	
	while(q.size())
	{
		tie(y, x) = q.front();
		q.pop();
		
		oriV.push_back({y, x});
		
		int cnt = 0;
		int k = a[y][x] / 5;
		
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (a[ny][nx] == -1) continue;
			
			spreadV.push_back({ny, nx, k});
			cnt++;
		}
		
		oriV.push_back({y, x, k * cnt});
	}
	
	for (auto i : oriV)
	{
		a[i.y][i.x] = max(0, a[i.y][i.x] - i.value);
	}
	
	for (auto i : spreadV)
	{
		a[i.y][i.x] += i.value;
	}
}

void doAir()
{
	int temp[54][54] = {0,};
	
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] != -1)
			{
				int ny = i + airDir[i][j].first;
				int nx = j + airDir[i][j].second;
				
				if (a[ny][nx] != -1)
					temp[ny][nx] = a[i][j];
			}
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] != -1)
			{
				a[i][j] = temp[i][j];
			}
		}
	}
	
}

void printA()
{
	cout << "\n **printA** \n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
}

void printAirDir()
{
	cout << "\n **printAirDir** \n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << "{" << airDir[i][j].first << ","<<airDir[i][j].second<<"}"  << " ";
		}
		cout << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> t;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			
			if (a[i][j] == -1)
			{
				if (topAir.first == 0 && topAir.second == 0)
				{
					// 위쪽 공기청정기 
					topAir = {i, j};
					
					for (int c = 0; c < m; c++)
					{
						// 바람 방향 오른쪽으로
						airDir[i][c] = {0, 1}; 
						
						// 바람 방향 왼쪽으로
						airDir[0][c] = {0, -1};
					}
					
					for (int r = 0; r <= i; r++)
					{
						// 바람 방향 위쪽으로
						airDir[r][m - 1] = {-1, 0};
						
						// 바람 방향 아래쪽으로
						airDir[r][0] = {1, 0};
					}
					
					airDir[0][m-1] = {0, -1};
					airDir[i][m-1] = {-1, 0};
					airDir[0][0] = {1, 0};
				}
				else
				{
					// 아래쪽 공기청정기 
					bottomAir = {i, j};
					
					for (int c = 0; c < m; c++)
					{
						// 바람 방향 오른쪽으로
						airDir[i][c] = {0, 1}; 
						
						// 바람 방향 왼쪽으로
						airDir[n-1][c] = {0, -1};
					}
					
					for (int r = i; r < n; r++)
					{
						// 바람 방향 위쪽으로
						airDir[r][0] = {-1, 0};
						
						// 바람 방향 아래쪽으로
						airDir[r][m-1] = {1, 0};
					}
					
					airDir[i][m-1] = {1, 0};
					airDir[n-1][m-1] = {0, -1};
					airDir[n-1][0] = {-1, 0};
				}
					
			}
		}
	}
	
	while (t--)
	{
		spread();
		doAir();
		
		//printA();
	}
	
	int ret = 0;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] > 0)
				ret += a[i][j];
		}
	}
	
	cout << ret << "\n";
	
	return 0;
}
