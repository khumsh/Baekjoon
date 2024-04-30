#include<bits/stdc++.h>
using namespace std;
// 1213 팰린드롬 만들기 

string input, ret;
char mid; 
int cnt[200], flag;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> input;
	
	for (char c : input)
	{
		cnt[c]++; // 문자열 카운트 추가 
	}
	
	for (int i = 'Z'; i >= 'A'; i--)
	{
		if (cnt[i] != 0)
		{
			if (cnt[i] % 2 != 0) // 홀수
			{
				// 중간에 들어갈 문자 설정
				mid = char(i);
				flag++;
				cnt[i]--;
			} 
			
			if (flag >= 2)
			{
				// 중간에 들어갈 문자가 2개 이상이면 팰린드롬을 만들 수 없음 
				break;
			}
			
			for (int j = 0; j < cnt[i]; j += 2)
			{
				// 앞 뒤로 붙이기
				// 앞 뒤로 붙여야하니까 카운트 2개씩 써서 j += 2 
				ret = char(i) + ret;
				ret = ret + char(i);
			}
		}
	}
	
	if (mid) // mid가 있으면 
	{
		// 중간에 mid 끼워넣기 
		ret.insert(ret.begin() + ret.size() / 2, mid);
	}
	
	if (flag >= 2) // 홀수가 2개 이상이면 팰린드롬 불가 
	{
		cout << "I'm Sorry Hansoo\n";
	}
	else // 홀수가 2개 이하라면 팰린드롬 출력 
	{
		cout << ret << "\n";
	}
	 
}

