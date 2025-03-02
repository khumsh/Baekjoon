#include<bits/stdc++.h>
using namespace std;

int k;
vector<int> a, ret[14];

void go(int startIdx, int endIdx, int lv)
{
	if (startIdx == endIdx)
	{
		ret[lv].push_back(a[startIdx]);
		
		//cout << "Lv: " << lv << "| push:" << a[startIdx] << "\n";
		return;
	}
	
	int center = (startIdx + endIdx) / 2;
	ret[lv].push_back(a[center]);
	//cout << "Lv: " << lv << "| push:" << a[center] << "\n";
	
	go(startIdx, center-1, lv+1);
	go(center+1, endIdx, lv+1);
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// input
	cin >> k;
	int nodeSize = pow(2, k) - 1;
	for (int i = 0; i < nodeSize; i++)
	{
		int n;
		cin >> n;
		a.push_back(n);
	}
	
	//
	go(0, nodeSize-1, 0);
	
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < ret[i].size(); j++)
		{
			cout << ret[i][j] << " ";
		}
		cout << "\n";
	}
	
	
	return 0;
}
