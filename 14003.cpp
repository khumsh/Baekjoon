#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 4;

int n, a[1000004], prevList[1000004], lis[1000004], lisIdx[1000004], len;

/*

prevList[i]는 바로 앞 원소의 인덱스 저장 (복원용)
lis[i]는 길이가 i+1인 증가 부분 수열의 마지막 원소값(최소값) 저장 
lisIdx[i]는 lis[i]에 해당하는 실제 수열 a에서의 인덱스 저장 

*/

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	
	fill(prevList, prevList + 1000004, -1);
	fill(lis, lis + 1000004, INF);
	
	for (int i = 0; i < n; i++)
	{
		// a[i]가 들어갈 위치 찾기.
		// lis는 최대값으로 초기화되어있어서 처음에는 무조건 0 
		int pos = lower_bound(lis, lis + len, a[i]) - lis;
		 
		lis[pos] = a[i];
		lisIdx[pos] = i; // a[i]가 실제 입력 배열의 어느 위치에 있었는지 저장 
		
		// a[i]가 기존 부분 수열보다 큰 값이면, 길이 늘리기 
		if (pos == len)
			len++;
		
		// pos > 0이면, a[i]의 바로 이전 원소는 lisIdx[pos-1] 
		if (pos > 0)
			prevList[i] = lisIdx[pos - 1];
	}
	
	int idx = lisIdx[len - 1];
	vector<int> v;
	for (int i = idx; i != -1; i = prevList[i])
	{
		v.push_back(a[i]);
	}
	
	reverse(v.begin(), v.end());
	
	cout << v.size() << "\n";
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	
	
	return 0;
}
