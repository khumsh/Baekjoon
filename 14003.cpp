#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 4;

int n, a[1000004], prevList[1000004], lis[1000004], lisIdx[1000004], len;

/*

prevList[i]�� �ٷ� �� ������ �ε��� ���� (������)
lis[i]�� ���̰� i+1�� ���� �κ� ������ ������ ���Ұ�(�ּҰ�) ���� 
lisIdx[i]�� lis[i]�� �ش��ϴ� ���� ���� a������ �ε��� ���� 

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
		// a[i]�� �� ��ġ ã��.
		// lis�� �ִ밪���� �ʱ�ȭ�Ǿ��־ ó������ ������ 0 
		int pos = lower_bound(lis, lis + len, a[i]) - lis;
		 
		lis[pos] = a[i];
		lisIdx[pos] = i; // a[i]�� ���� �Է� �迭�� ��� ��ġ�� �־����� ���� 
		
		// a[i]�� ���� �κ� �������� ū ���̸�, ���� �ø��� 
		if (pos == len)
			len++;
		
		// pos > 0�̸�, a[i]�� �ٷ� ���� ���Ҵ� lisIdx[pos-1] 
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
