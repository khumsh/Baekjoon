#include<bits/stdc++.h>
using namespace std;

int a[3], ret;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> a[0] >> a[1] >> a[2];
	
	sort(a, a + 3);
	
	// A. 세 막대의 길이가 동일한 경우
	//  그대로 정삼각형을 만든다. 
	// B. 가장 긴 막대가 나머지 막대의 길이 합보다 작은 경우
	//  그대로 삼각형을 만든다. 
	// C. 가장 긴 막대가 나머지 막대의 길이 합보다 긴 경우
	//  나머지 막대의 길이 합이 더 길도록 맞춘다.
	// D. 가장 긴 막대가 나머지 막대의 길이 합과 같은 경우
	//  나머지 막대의 길이 합을 1 줄인다.
	
	if (a[0] == a[1] && a[1] == a[2])
	{
		// Case A
		ret = a[0] * 3;
	} 
	else if (a[2] < a[0] + a[1])
	{
		// Case B
		ret = a[0] + a[1] + a[2];
	}
	else if (a[2] > a[0] + a[1])
	{
		// Case C
		int n = a[0] + a[1] - 1;
		ret = a[0] + a[1] + n;
	}
	else
	{
		// Case D
		ret = a[0] + a[1] - 1 + a[2];
	}
	
	cout << ret << "\n";
	
	return 0;
}
