#include<bits/stdc++.h>
using namespace std;

int n, a[12][12], visited[12][12], ret = 1e9;

int dy[] = {0, -1, 0, 1, 0};
int dx[] = {0, 0, 1, 0, -1};

void go(int cnt, int price)
{
	if (cnt >= 3)
	{
		ret = min(ret, price);
		return;
	}
	
	for (int i = 1; i < n - 1; i++)
	{
		for (int j = 1; j < n - 1; j++)
		{
			if (visited[i][j] || visited[i-1][j] || visited[i][j+1]
			 || visited[i+1][j] || visited[i][j-1]) continue;
			
			int priceSum = 0;
			
			for (int k = 0; k < 5; k++)
			{
				int ny = i + dy[k];
				int nx = j + dx[k];
				visited[ny][nx] = 1;
				priceSum += a[ny][nx];
			}
			
			go (cnt+1, price + priceSum);
			
			for (int k = 0; k < 5; k++)
			{
				int ny = i + dy[k];
				int nx = j + dx[k];
				visited[ny][nx] = 0;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// input
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	
	//
	go(0, 0);
	
	cout << ret << "\n";
	
	return 0;
}
