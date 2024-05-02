#include<bits/stdc++.h>
using namespace std;
// 3986 좋은 단어 

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
			// 스택에 원소가 있고, 가장 위에 있는 원소가 c와 같다면 없애기 
			// 주의: 스택의 top값 참조할 때는 size 있는지 체크 필수 (큐도 마찬가지) 참조에러 발생 가능 
			if (stk.size() && stk.top() == c)
				stk.pop();
			else
				stk.push(c); // 아니라면 집어넣기
		}
		
		if (stk.size() == 0)
			ret++;
	}
	
	cout << ret << "\n";
}
