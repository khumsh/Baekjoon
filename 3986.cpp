#include<bits/stdc++.h>
using namespace std;
// 3986 ���� �ܾ� 

int n, ret;
string input;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		stack<char> stk;
		for (char c : input)
		{
			// ���ÿ� ���Ұ� �ְ�, ���� ���� �ִ� ���Ұ� c�� ���ٸ� ���ֱ� 
			// ����: ������ top�� ������ ���� size �ִ��� üũ �ʼ� (ť�� ��������) �������� �߻� ���� 
			if (stk.size() && stk.top() == c)
				stk.pop();
			else
				stk.push(c); // �ƴ϶�� ����ֱ�
		}
		
		if (stk.size() == 0)
			ret++;
	}
	
	cout << ret << "\n";
}
