#include <bits/stdc++.h>
using namespace std;
// 9996 한국이 그리울 땐 서버에 접속하지

// 접두사 접미사 확인 

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
		
		// 반례 제거용 
		// 패턴이 ab*ab라고 했을 때
		// ab만 입력해도 참이라고 되는 경우 생길 수 있음 
		if (pStart.size() + pEnd.size() > input.size())
		{
			cout << "NE\n";
		}
		else
		{
			// 시작과 끝부분의 길이만큼만 확인 
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
