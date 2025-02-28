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

void go(int idx, int calcN) // calcN은 여기까지 계산한 값 
{
	if (idx == num.size() - 1) // 끝까지 계산했다면 
	{
		ret = max(ret, calcN); // 최대값 갱신 
		return;
	}	
	
	// 괄호 안씌우고 그냥 계산 
	// [calcN] [op] [idx+1]
	go(idx + 1, calc(calcN, oper[idx], num[idx+1]));
	
	// 괄호 씌우고 계산
	if (idx + 2 <= num.size() - 1) // 맨 앞과 맨 뒤는 괄호 의미 없음
	{
		// 앞에는 씌우는거 의미 없으니 오른쪽에 씌우기 
		// 괄호 씌워놓은 식 계산 
		// [calcN] [op] ([idx+1] [op+1] [idx+2])
		// => [calcN] [op] [temp]
		int temp = calc(num[idx+1], oper[idx+1], num[idx+2]);
		// 괄호 씌워서 사실상 2번 계산함 => idx+2 
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
