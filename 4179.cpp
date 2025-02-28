#include<bits/stdc++.h>
using namespace std;

int r, c, y, x, ret, fire_check[1004][1004], j_check[1004][1004];
char a[1004][1004];
pair<int,int> jCell;

int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// input
	cin >> r >> c;
	
	queue<pair<int,int>> q;
	fill(&fire_check[0][0], &fire_check[0][0] + 1004 * 1004, -1);
	fill(&j_check[0][0], &j_check[0][0] + 1004 * 1004, -1);
	
	for (int i = 0; i < r; i++)
	{
		for(int j = 0; j < c; j++)
		{
            cin >> a[i][j];
            
            if (a[i][j] == 'F')
			{
                fire_check[i][j] = 1;
				q.push({i, j});
            }
			else if (a[i][j] == 'J')
			{
                jCell = {i, j};
            }
        }
	}
	
	// �� �ִܰŸ� ���ϱ� bfs
	while(q.size())
	{
		tie(y, x) = q.front();
		q.pop();
		
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
			if (fire_check[ny][nx] == -1 && a[ny][nx] != '#')
			{
				fire_check[ny][nx] = fire_check[y][x] + 1;
				q.push({ny, nx});
			}
		}
	}
	
	// ���� �ִܰŸ� ���ϱ� bfs 
	j_check[jCell.first][jCell.second] = 1;
	q.push({jCell.first, jCell.second});
	while(q.size())
	{
		tie(y, x) = q.front();
		q.pop();
		
		if (x == c - 1 || y == r - 1 || x == 0 || y == 0)
		{
			// �����ڸ��̹Ƿ� Ż�� ����
			ret = j_check[y][x]; // �ִܰŸ��� ret�� �ѱ�� 
			break; 
		}
		
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
			if (j_check[ny][nx] != -1) continue;
			if (a[ny][nx] == '#') continue;
			if (fire_check[ny][nx] != -1 && fire_check[ny][nx] <= j_check[y][x] + 1) continue;
			
			// �Һ��� ���� ������ �� �ִ� ������ 
			j_check[ny][nx] = j_check[y][x] + 1;
			q.push({ny, nx});
		}
	}
	
	if (ret == 0)
	{
		cout << "IMPOSSIBLE\n";
	}
	else
	{
		cout << ret << "\n";
	}
	
	return 0;
}
