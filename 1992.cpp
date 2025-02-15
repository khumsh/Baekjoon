#include<bits/stdc++.h>
using namespace std;

// https://www.acmicpc.net/problem/1992

int n;
string a[65][65];

// (sy, sx)�� ���� ��ǥ�� �Ͽ� ũ�Ⱑ n�� ������ �����ϴ� �Լ� 
string quadTree(int sy, int sx, int n)
{
	// ���� ������ ù ĭ�� ��
	// ������ ���� ��� ������� init�� �����ϱ� ���� 
	string init = a[sy][sx];
	bool same = true;
	
	for (int i = sy; i < sy + n; i++)
	{
		for (int j = sx; j < sx + n; j++)
		{
			if (a[i][j] != init)
			{
				same = false;
				break;
			}
		}
		
		if (same == false)
			break;
	}
	
	// ���� ���� ���� ��� ���� ��� �ش� �� ���� 
	if (same)
	{
		return init;
	}
	
	// �ٸ��� ������ 4����ؼ� ��������� ������ ����� ��ħ
	int half = n / 2;
	string topLeft = quadTree(sy, sx, half);
	string topRight = quadTree(sy, sx + half, half);
	string bottomLeft = quadTree(sy + half, sx, half);
	string bottomRight = quadTree(sy + half, sx + half, half);
	
	string ret = "(" + topLeft + topRight + bottomLeft + bottomRight + ")";
	
	/*
	//debug
	cout << "========" << "n: " << n <<"========" << "\n";
	cout << "-----topLeft-----" << "\n";
	for (int i = sy; i < sy + half; i++)
	{
		for (int j = sx; j < sx + half; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
	
	cout << "-----topRight-----" << "\n";
	for (int i = sy; i < sy + half; i++)
	{
		for (int j = sx + half; j < sx + half*2; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
	
	cout << "-----bottomLeft-----" << "\n";
	for (int i = sy + half; i < sy + half*2; i++)
	{
		for (int j = sx; j < sx + half; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
	
	cout << "-----bottomRight-----" << "\n";
	for (int i = sy + half; i < sy + half*2; i++)
	{
		for (int j = sx + half; j < sx + half*2; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "return: " << ret << "\n";
	cout << "====================" << "\n";
	*/
	
	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// input
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < n; j++)
		{
			a[i][j] = s[j];
		}
	}
	
	string ret = quadTree(0, 0, n);
	cout << ret << "\n";
	
	return 0;
} 
