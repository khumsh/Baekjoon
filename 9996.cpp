#include <bits/stdc++.h>
using namespace std;
// 9996 �ѱ��� �׸��� �� ������ ��������

// ���λ� ���̻� Ȯ�� 

int n;
string input, pattern, pStart, pEnd;


int main()
{
	cin >> n;
	cin >> pattern;
	
	int pos = pattern.find('*');
	pStart = pattern.substr(0, pos);
	pEnd = pattern.substr(pos + 1);
	
	for(int i = 0; i < n; i++)
	{
		cin >> input;
		
		// �ݷ� ���ſ� 
		// ������ ab*ab��� ���� ��
		// ab�� �Է��ص� ���̶�� �Ǵ� ��� ���� �� ���� 
		if (pStart.size() + pEnd.size() > input.size())
		{
			cout << "NE\n";
		}
		else
		{
			// ���۰� ���κ��� ���̸�ŭ�� Ȯ�� 
			if (pStart == input.substr(0, pStart.size()) && pEnd == input.substr(input.size() - pEnd.size()))
			{
				cout << "DA\n";
			}
			else
			{
				cout << "NE\n";
			}
		}
		
	}
	
	
	return 0;
}
