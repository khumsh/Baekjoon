#include<bits/stdc++.h>
using namespace std;

double sum, scoreSum, score;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	for (int i = 0; i < 20; i++)
	{
		string s, grade;
		double n;
		
		cin >> s >> n >> grade;
		
		if (grade == "P")
			continue;
			
		sum += n;
		
		if (grade == "A+") score = 4.5;
		else if (grade == "A0") score = 4.0;
		else if (grade == "B+") score = 3.5;
		else if (grade == "B0") score = 3.0;
		else if (grade == "C+") score = 2.5;
		else if (grade == "C0") score = 2.0;
		else if (grade == "D+") score = 1.5;
		else if (grade == "D0") score = 1.0;
		else if (grade == "F") score = 0.0;
	
		scoreSum += n * score;
	}
	
	cout << scoreSum / sum << "\n";
	
	return 0;
}
