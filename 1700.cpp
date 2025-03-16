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
		// 플러그에 꽂혀있으면 넘기기 
		if (plugged[a[i]]) continue;
		if (plug.size() == n) // 플러그가 꽉차있으면 
		{
			int lastIdx = 0, pos = 0;
			for (int p : plug) // 꽂혀있는 플러그 탐색 
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
				
				// 꽂혀있는 플러그 중에 가장 나중에 사용하는 플러그 선택 
				if (lastIdx < idx)
				{
					lastIdx = idx;
					pos = p;
				}
			} 
			
			// 플러그 뽑기 
			plugged[pos] = 0;
			plug.erase(find(plug.begin(), plug.end(), pos));
			ret++;
		}
		
		// 플러그에 꽂기 
		plug.push_back(a[i]);
		plugged[a[i]] = 1;
	}
	
	cout << ret << "\n";
	
	return 0;
}
