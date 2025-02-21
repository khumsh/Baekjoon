#include<bits/stdc++.h>
using namespace std;

// https://www.acmicpc.net/problem/4949

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	while(getline(cin, s))
	{
		if (s == ".")
			break;
			
		bool isBalanced = true;
        stack<char> st;
        
        for (char c : s){
            if (c == '(' || c == '[')
			{
				// 열린 괄호 스택에 넣기 
                st.push(c);
            }
            else if (c == ')')
			{
                if (st.empty() || st.top() != '(')
				{
                    isBalanced = false;
                    break;
                }
                
                st.pop();
            }
            else if (c == ']'){
                if (st.empty() || st.top() != '[')
				{
                    isBalanced = false;
                    break;
                }
                
                st.pop();
            }
        }
        
        if (!st.empty())
            isBalanced = false;
        
        cout << (isBalanced ? "yes" : "no") << "\n";
	}
	
	return 0;
}
