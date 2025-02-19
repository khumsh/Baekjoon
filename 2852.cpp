#include<bits/stdc++.h>
using namespace std;

// https://www.acmicpc.net/problem/2852

int n, score[4], time_win[4], prev_time, win_team; // 0:�����־���, 1:1��, 2:2�� 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	while(n--)
	{
		int t, mm, ss;
		string s, s_mm, s_ss;
		cin >> t;
		cin >> s;
		
		s_mm = s.substr(0, 2);
		s_ss = s.substr(3);
		
		mm = stoi(s_mm);
		ss = stoi(s_ss);
		int current_time = (mm * 60 + ss);
		
		score[t]++;
		if (win_team == 0) // �������� draw 
		{
			win_team = t;
		}
		else if (score[1] == score[2]) // ���� draw
		{
			time_win[win_team] += current_time - prev_time;

			win_team = 0;
		}
		else // win_team�� �̱�� �־���, ��� �̱�� ���� 
		{
			time_win[win_team] += current_time - prev_time;
		}
		
		prev_time = (mm * 60 + ss);
	}
	
	// ������ �ð� +
	time_win[win_team] += 48 * 60 - prev_time;
	
	for (int i = 1; i < 3; i++)
	{
		int minutes = time_win[i] / 60;
        int seconds = time_win[i] % 60;
        cout << setw(2) << setfill('0') << minutes << ":"
             << setw(2) << setfill('0') << seconds << "\n";
	}
	
	return 0;
} 
