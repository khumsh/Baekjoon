#include <bits/stdc++.h>
using namespace std;
// 10988 �Ӹ�������� Ȯ���ϱ�
// �Ӹ���� : �Ųٷ� �о ���� �ܾ� (ȸ��) 

string str, temp;

void Solve1()
{
	bool ok = true;
	
	cin >> str;
	
	for (int i = 0; i < str.length() / 2; i++)
	{
		if (str[i] != str[str.length()-i-1])
		{
			ok = false;
			break;
		}
			
	}
	
	cout << ok;
}

void Solve2()
{
	cin >> str;
	temp = str;
	
	reverse(temp.begin(), temp.end());
	
	cout << (temp == str) << "\n";
}

int main()
{
	//Solve1();
	Solve2();
	
	return 0;
}
