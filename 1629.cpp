#include<bits/stdc++.h>
using namespace std;

long long a, b, c;

long long go(long long a, long long b)
{
	// (a * b) % c == ((a % c) * (b % c)) % c�̹Ƿ�
	// ���ڰ� �ʹ� Ŀ���� �ʵ��� �̸� �̸� �����ֱ� 
	
	if (b == 1) // ����Լ� ������� 
		return a % c; 
	
	long long ret = go(a, b / 2);
	ret = (ret * ret) % c;
	if (b % 2 != 0) // Ȧ����� �� �� �� �����ֱ� 
		ret = (ret * a) % c;
		
	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> a >> b >> c;
	
	cout << go(a, b) << "\n";
	return 0;
} 
