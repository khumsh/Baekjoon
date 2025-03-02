#include<bits/stdc++.h>
using namespace std;

int k, visited[12], mx, mn;
char c[12];
vector<string> ret;

bool check(char a, char op, char b)
{
	if (op == '<') return a < b;
	else if (op == '>') return a > b;
}

void go(int idx, string s)
{
	if (idx == k + 1)
	{
		ret.push_back(s);
		return;
	}
	
	for (int i = 0; i <= 9; i++)
	{
		if (visited[i]) continue;
		if (idx == 0 || check(s[idx - 1], c[idx - 1], i + '0'))
		{
			// idx�� 0�̰ų� i�� �ε�ȣ�� ������Ű�� �־�� 
			visited[i] = 1;
			go (idx + 1, s + to_string(i));
			visited[i] = 0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// input
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> c[i];
	}
	
	//
	go(0, "");
	
	// �ڸ����� ������ �Ȱ����ϱ� sort�� ���� ���� 
	sort(ret.begin(), ret.end()); 

	cout << ret[ret.size() - 1] << "\n" << ret[0] << "\n";
	
	return 0;
}
