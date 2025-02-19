#include<bits/stdc++.h>
using namespace std;

// https://www.acmicpc.net/problem/2910

int n, c, a[1004];
map<int,int> cnt, cnt_first; // 개수 세기, 몇 번째에 나왔는지 
vector<pair<int,int>> v; // sort용 벡터 

// sort용 비교 함수 (파라미터: {나온개수, 숫자})
bool cmp(pair<int,int> a, pair<int,int> b)
{
	if (a.first == b.first) // 나온 개수가 같다면 
	{
		// 나온 순서대로 정렬
		// cnt_first값이 작을 수록 먼저 나옴 
		return cnt_first[a.second] < cnt_first[b.second];
	}
	
	return a.first > b.first;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// input
	cin >> n >> c;
	
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		
		cnt[a[i]]++; // 나올때마다 cnt++ 
		if (cnt_first[a[i]] == 0)
		{
			cnt_first[a[i]] = i + 1; // 나온 순서 저장 
		}
	}
	
	for (auto it : cnt) // it: {숫자, 나온 개수}
	{
		// 나온 개수대로 정렬하기 위해 it.second를 v.first에 넣기 
	
		v.push_back({it.second, it.first}); 
	}
	
	sort(v.begin(), v.end(), cmp);
	
	for (auto it : v)
	{
		for (int i = 0; i < it.first; i++)
		{
			cout << it.second << " ";
		}
	}
	
	return 0;
}
