#include<bits/stdc++.h>
using namespace std;

// https://www.acmicpc.net/problem/16637

string s;
int n, ret = -1e9;

vector<int> num;
vector<char> oper;

int calc(int a, char c, int b)
{
	if (c == '+')
	{
		return a + b;
	}
	else if (c == '-')
	{
		return a - b;
	}
	else if (c == '*')
	{
		return a * b;
	}
}

void go(int idx, int calcN) // calcN�� ������� ����� �� 
{
	if (idx == num.size() - 1) // ������ ����ߴٸ� 
	{
		ret = max(ret, calcN); // �ִ밪 ���� 
		return;
	}	
	
	// ��ȣ �Ⱦ���� �׳� ��� 
	// [calcN] [op] [idx+1]
	go(idx + 1, calc(calcN, oper[idx], num[idx+1]));
	
	// ��ȣ ����� ���
	if (idx + 2 <= num.size() - 1) // �� �հ� �� �ڴ� ��ȣ �ǹ� ����
	{
		// �տ��� ����°� �ǹ� ������ �����ʿ� ����� 
		// ��ȣ �������� �� ��� 
		// [calcN] [op] ([idx+1] [op+1] [idx+2])
		// => [calcN] [op] [temp]
		int temp = calc(num[idx+1], oper[idx+1], num[idx+2]);
		// ��ȣ ������ ��ǻ� 2�� ����� => idx+2 
		go(idx+2, calc(calcN, oper[idx], temp));
	}	
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	cin >> s;
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
			num.push_back(s[i] - '0');
		else
			oper.push_back(s[i]);
	}
	
	go(0, num[0]);
	
	cout << ret << "\n"; 
	
	return 0;
}
