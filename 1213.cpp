#include<bits/stdc++.h>
using namespace std;
// 1213 �Ӹ���� ����� 

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
		cnt[c]++; // ���ڿ� ī��Ʈ �߰� 
	}
	
	for (int i = 'Z'; i >= 'A'; i--)
	{
		if (cnt[i] != 0)
		{
			if (cnt[i] % 2 != 0) // Ȧ��
			{
				// �߰��� �� ���� ����
				mid = char(i);
				flag++;
				cnt[i]--;
			} 
			
			if (flag >= 2)
			{
				// �߰��� �� ���ڰ� 2�� �̻��̸� �Ӹ������ ���� �� ���� 
				break;
			}
			
			for (int j = 0; j < cnt[i]; j += 2)
			{
				// �� �ڷ� ���̱�
				// �� �ڷ� �ٿ����ϴϱ� ī��Ʈ 2���� �Ἥ j += 2 
				ret = char(i) + ret;
				ret = ret + char(i);
			}
		}
	}
	
	if (mid) // mid�� ������ 
	{
		// �߰��� mid �����ֱ� 
		ret.insert(ret.begin() + ret.size() / 2, mid);
	}
	
	if (flag >= 2) // Ȧ���� 2�� �̻��̸� �Ӹ���� �Ұ� 
	{
		cout << "I'm Sorry Hansoo\n";
	}
	else // Ȧ���� 2�� ���϶�� �Ӹ���� ��� 
	{
		cout << ret << "\n";
	}
	 
}

