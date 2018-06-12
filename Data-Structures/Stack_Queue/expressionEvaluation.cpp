#include<bits/stdc++.h>
#define fr(i,n) for(int i=0;i<n;i++)
using namespace std;

int prec(char c)
{
    switch(c)
    {
        case '^' : return 3;
        case '/' :
        case '*' : return 2;
        case '+' :
        case '-' : return 1;
        case '(' : return 0;
    }
}

bool isOperator(char c)
{
    if(c=='^' || c=='/' || c=='*' || c=='+' || c=='-')
        return true;
    return false;
}

string infixToPostfix(string s)
{
 //A*(B+C)/D
 //ABC+*D/
    stack<char> st;
    string res;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='(')
            st.push(s[i]);
        else if(s[i]==')')
        {
            while(!st.empty() && st.top()!='(')
            {
                res.push_back(st.top());
                st.pop();
            }
            st.pop();
        }
        else if(isOperator(s[i]))
        {
            while(!st.empty() && prec(st.top())>=prec(s[i]))
            {
                res.push_back(st.top());
                st.pop();
            }
            st.push(s[i]);
        }
        else //if operand
          res.push_back(s[i]);
    }
    while(!st.empty()) res.push_back(st.top()),st.pop();
    return res;
}

float getResult(float a,float b,char c)
{
    switch(c)
    {
        case '^' : return (int)pow(a,b);
        case '/' : return a/b;
        case '*' : return a*b;
        case '+' : return a+b;
        case '-' : return a-b;
    }
}

float evaluatePostfix(string s)
{
    stack<float> st;
    for(int i=0;i<s.length();i++)
    {
        if(isOperator(s[i]))
        {
            float b=st.top();st.pop();
            float a=st.top();st.pop();
            float res=getResult(a,b,s[i]);
            //cout<<res<<endl;
            st.push(res);
        }
        else
            st.push(s[i]-'0');
    }
    return st.top();
}

string removeSpaces(string s)
{
	string res;
	for(int i=0;s[i];i++)
	{
		if(int(s[i])==32)
			continue;
		res.push_back(s[i]);
	}
	return res;
}

int main()
{
	string s;
	getline(cin,s);
	s=removeSpaces(s);
	s=infixToPostfix(s);
	float result = evaluatePostfix(s);
	cout<<result<<endl;
	return 0;
}
