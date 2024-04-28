#include<bits/stdc++.h>
using namespace std; 
// 1620 ���¾� ���ϸ� ������ �̴ټ�

int n, m;
string s, a[100004];
map<string, int> mp;
map<int, string> mp2;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		mp[s] = i + 1; // 1������ 
		mp2[i+1] = s;
		a[i+1] = s;
	}
	
	for (int i = 0; i < m; i++)
	{
		cin >> s;
		// atoi(s.c_str()) == 0 => ���ڿ� 
		// atoi(s.c_str()) != 0 => ���� 
		
		if (atoi(s.c_str()) == 0) // ���ڿ��϶� 
		{
			cout << mp[s] << "\n"; // ������� 
		}
		else // �����϶� 
		{
			// �迭�� O(1)�� �ð����⵵
			// map�� O(logN)�� �ð����⵵
			
			// �迭�� �� ������ ������ map�� ũ�� ���̳����� ����
			// ���ϴ� �ɷ� ���� �� 
			
			cout << a[atoi(s.c_str())] << "\n"; // ���ڿ����
			// cout << mp2[atoi(s.c_str())] << "\n"; 
		}
	}
	
}
