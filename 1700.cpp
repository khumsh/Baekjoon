#include<bits/stdc++.h>
using namespace std;

int n, k, a[104], plugged[104], ret;
vector<int> plug;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> a[i];
	}
	
	for (int i = 0; i < k; i++)
	{
		// �÷��׿� ���������� �ѱ�� 
		if (plugged[a[i]]) continue;
		if (plug.size() == n) // �÷��װ� ���������� 
		{
			int lastIdx = 0, pos = 0;
			for (int p : plug) // �����ִ� �÷��� Ž�� 
			{
				int idx = 1e9;
				
				for (int j = i + 1; j < k; j++)
				{
					if (p == a[j])
					{
						idx = j;
						break;
					}
				}
				
				// �����ִ� �÷��� �߿� ���� ���߿� ����ϴ� �÷��� ���� 
				if (lastIdx < idx)
				{
					lastIdx = idx;
					pos = p;
				}
			} 
			
			// �÷��� �̱� 
			plugged[pos] = 0;
			plug.erase(find(plug.begin(), plug.end(), pos));
			ret++;
		}
		
		// �÷��׿� �ȱ� 
		plug.push_back(a[i]);
		plugged[a[i]] = 1;
	}
	
	cout << ret << "\n";
	
	return 0;
}
