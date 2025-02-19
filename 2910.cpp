#include<bits/stdc++.h>
using namespace std;

// https://www.acmicpc.net/problem/2910

int n, c, a[1004];
map<int,int> cnt, cnt_first; // ���� ����, �� ��°�� ���Դ��� 
vector<pair<int,int>> v; // sort�� ���� 

// sort�� �� �Լ� (�Ķ����: {���°���, ����})
bool cmp(pair<int,int> a, pair<int,int> b)
{
	if (a.first == b.first) // ���� ������ ���ٸ� 
	{
		// ���� ������� ����
		// cnt_first���� ���� ���� ���� ���� 
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
		
		cnt[a[i]]++; // ���ö����� cnt++ 
		if (cnt_first[a[i]] == 0)
		{
			cnt_first[a[i]] = i + 1; // ���� ���� ���� 
		}
	}
	
	for (auto it : cnt) // it: {����, ���� ����}
	{
		// ���� ������� �����ϱ� ���� it.second�� v.first�� �ֱ� 
	
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
