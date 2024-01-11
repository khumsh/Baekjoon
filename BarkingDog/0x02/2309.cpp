#include <bits/stdc++.h>
using namespace std;
// 2309 일곱난쟁이

int arr[9], sum;

pair<int, int> solve()
{
	// 전체 합에서 2명 빼면 100
	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < i; j++)
		{
			// 2명 순서 상관없이 뽑기
			if (sum - arr[i] - arr[j] == 100)
			{
				return {i, j};
			}  
		}
	} 
}

int main()
{
	vector<int> v;
	pair<int, int> p;
	
	for(int i = 0; i < 9; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	
	p = solve();
	for(int i = 0; i < 9; i++)
	{
		if (p.first == i || p.second == i) continue;
		v.push_back(arr[i]);
	}
	
	sort(v.begin(), v.end()); // 오름차순 정렬 
	for(int i : v) cout << i << "\n";
	return 0;
}


