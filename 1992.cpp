#include<bits/stdc++.h>
using namespace std;

// https://www.acmicpc.net/problem/1992

int n;
string a[65][65];

// (sy, sx)를 시작 좌표로 하여 크기가 n인 영역을 압축하는 함수 
string quadTree(int sy, int sx, int n)
{
	// 현재 영역의 첫 칸의 값
	// 영역의 값이 모두 같을경우 init을 리턴하기 위함 
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
	
	// 영역 내의 값이 모두 같은 경우 해당 값 리턴 
	if (same)
	{
		return init;
	}
	
	// 다르면 영역을 4등분해서 재귀적으로 압축한 결과를 합침
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
