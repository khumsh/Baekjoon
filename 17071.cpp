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
		// t�� �� k�� ��ġ 
		int targetPos = getK(t);
		
		// t�� �� Ÿ���� ���� ������ ������ -1 ��� 
		if (targetPos > MAX)
		{
			cout << -1 << "\n";
			return 0; 
		}
		
		// t�� �� Ÿ���� ��ġ�� �����ߴٸ� ���� ���
		if (visited[targetPos][t%2] > 0)
		{
			cout << t << "\n";
			break;
		}
		
		int qSize = q.size();
		// ���� q�� �ִ� ��� ��ġ���� t�ʿ� ������ ����.
		// �̵��� Ȯ���Ͽ� t+1�� �� ���� ������ ���µ��� ���ϱ�. 
		for (int i = 0; i < qSize; i++)
		{
			int cur = q.front();
			q.pop();
			
			for (int nxt : { cur-1, cur+1, cur*2 })
			{
				if (nxt < 0 || nxt > MAX) continue;
				if (visited[nxt][(t+1)%2] > 0) continue;
				
				// t+1�� �Ŀ� �����ϴ� ���� ���� ���� üũ 
				visited[nxt][(t+1)%2] = t + 1;
				q.push(nxt);
			}
		}
		
		t++;
	}
	
	return 0;
}
