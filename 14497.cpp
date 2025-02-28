#include<bits/stdc++.h>
using namespace std;

int n, m, yy, xx, y2, x2, cnt, visited[304][304];
char a[304][304];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void debugPrint()
{
	// debug
	cout << "cnt: " << cnt << "\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// input
	cin >> n >> m;
	cin >> yy >> xx >> y2 >> x2;
	yy--; xx--; y2--; x2--;
	
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		
		for (int j = 0; j < m; j++)
		{
			a[i][j] = s[j];
		}
	}
	
	
	//
	visited[yy][xx] = 1;
	
	queue<pair<int,int>> q;
	queue<pair<int,int>> temp;
	q.push({yy, xx});
	
	while(a[y2][x2] != 'X')
	{
		while(q.size())
		{
			int y, x;
			tie(y, x) = q.front();
			q.pop();
			
			for (int i = 0; i < 4; i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];
				
				if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
				if (visited[ny][nx]) continue;
				
				visited[ny][nx] = cnt + 1;
				
				if (a[ny][nx] == '0')
				{
					q.push({ny, nx});
				}
				else
				{
					temp.push({ny, nx});
					
					if (a[ny][nx] != '#')
						a[ny][nx] = '0';
					else
						a[ny][nx] = 'X';
				}
				
			}
		}
		
		q = temp;
		
		//debugPrint();
		
		cnt++;
	}
	
	
	cout << cnt << "\n";
	
	
	return 0;
}
