#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;

class snode
{
	public:
    	int data;
    	snode *next;
    	snode()
    	{
        	next=NULL;
    	}
};

class Stack
{
    snode *top;
    int stackSize;
    public:
    	Stack()
    	{
        top=NULL;
        stackSize=0;
    	}
    	void push(int d);
    	int pop();
    	bool isEmpty();
};

void Stack::push(int d)
{
    snode *temp=new snode;
    temp->data=d;
    temp->next=top;
    top=temp;
    stackSize++;
}

int Stack::pop()
{
    if(top!=NULL)
    {
       	snode *temp=top;
        int t=top->data;
        top=top->next;
        delete temp;
        stackSize--;
        return t;
    }
    else
        return 0;
}

bool Stack::isEmpty()
{
    if(stackSize==0)
        return true;
    else
        return false;
}

int getPriority(char ch)
{
   switch(ch)
   {
       case '-': return 1;break;
       case '+': return 1;break;
       case '*': return 2;break;
       case '/': return 2;break;
   }
}

bool isOperator(char c)
{
    if(c=='+'||c=='/'||c=='*'||c=='-')
    	return true;
    else
		return false;
}

bool isBracket(char c)
{
    if(c=='['||c==']'||c=='('||c==')' || c=='{' || c=='}')
        return true;
    else
        return false;
}

bool isOpenBracket(char c)
{
    if(c=='['||c=='{'||c=='(')
        return true;
    else
        return false;
}

bool isClosingBracket(char c)
{
    if(c==']'||c=='}'||c==')')
        return true;
    else
        return false;

}

bool isPair(char br1,char br2)
{
    switch(br1)
    {
    case '(': if(br2==')')
                return true;
              else
                return false;
    case '[': if(br2==']')
                return true;
              else
                return false;
    case '{': if(br2=='}')
                return true;
              else
                return false;
    case ')': if(br2=='{')
                return true;
              else
                return false;
    case ']': if(br2=='[')
                return true;
              else
                return false;
    case '}': if(br2=='{')
                return true;
              else
                return false;

    }
}

bool balanceBrackets(char exp[])
{
    Stack s;
    int ctr=0;
    char buff;
    while(ctr<strlen(exp))
    {
        if(isBracket(exp[ctr]))
        {
            if(s.isEmpty())
            {
                s.push(exp[ctr]);
                ctr++;
                continue;
            }
            else
                buff=s.pop();

            if(isClosingBracket(buff))
            {
                return false;
            }
            else if(isOpenBracket(buff)&&isOpenBracket(exp[ctr]))
            {
                s.push(buff);
                s.push(exp[ctr]);
            }
            else if(isClosingBracket(exp[ctr]))
            {
                if(isPair(buff,exp[ctr]))
                {
                    ctr++;continue;
                }
                else
                {
                    return false;
                }
            }


        }
        ctr++;
    }

    if(!s.isEmpty())
        return false;

    return true;
}

bool chkInfix(char infix[])
{
    int ctr=0,openBr=0,closingBr=0;
    if(!balanceBrackets(infix))
    return false;
    
    while(ctr<strlen(infix)-1)
    {
        if(isOpenBracket(infix[ctr]))
        {
            ctr++;
            continue;
        }
        if(isClosingBracket(infix[ctr]))
        {
            return false;
        }
        if(!isdigit(infix[ctr])&&!isalpha(infix[ctr]))
            return false;
        if(!isOperator(infix[ctr+1])&&!isdigit(infix[ctr+1])&&!isClosingBracket(infix[ctr+1]))
            return false;
        if(isOpenBracket(infix[ctr+1]))
            return false;
        while(isdigit(infix[ctr+1])&&!isalpha(infix[ctr]))
            ctr=ctr+1;

        if(isClosingBracket(infix[ctr+1]))
        {
            if(ctr+2<(strlen(infix)-1)&&!isOperator(infix[ctr+2])&&!isClosingBracket(infix[ctr+2]))
            {
                return false;
            }
            while(isClosingBracket(infix[ctr+2]))
            {
                ctr++;
            }
              ctr+=3;
        }
        else
            ctr+=2;
    }
    
    if(!isdigit(infix[strlen(infix)-1])&&!isalpha(infix[strlen(infix)-1])&&!isClosingBracket(infix[strlen(infix)-1])||(isOperator(infix[strlen(infix)-2])&&isClosingBracket(infix[strlen(infix)-1])))
    {
       return false;
    }

    return true;
}

char* infixToPostfix(char infix[],char postfix[])
{
    char ch,*temp;
    Stack s;
    int length=strlen(infix),ctr=0,postCtr=0;
    while(ctr<length)
    {
        if(isOperator(infix[ctr])||isBracket(infix[ctr]))
        {

            if(s.isEmpty())
                s.push(infix[ctr]);
            else
            {
                if(infix[ctr]=='(' || infix[ctr]=='{' || infix[ctr]=='[')
                {
                    s.push(infix[ctr]);
                    ctr++;
                    continue;
                }
                else if(infix[ctr]==')' || infix[ctr]=='}' || infix[ctr]==']')
                {
                    ch=s.pop();
                    while(ch!='(' && ch!='{' && ch!='[' && !s.isEmpty())
                    {
                        postfix[postCtr++]=ch;
                        ch=s.pop();
                    }
                    ctr++;
                    continue;
                }

                ch=s.pop();
                while(getPriority(ch)>=getPriority(infix[ctr]) && ch!='(' && ch!='{' && ch!='[' )
                {
                    postfix[postCtr]=ch;
                    postCtr++;
                    if(s.isEmpty())
                    break;
                    ch=s.pop();
                }
                if(getPriority(ch)<getPriority(infix[ctr]) || ch=='(' || ch=='{' || ch=='[')
                s.push(ch);
                s.push(infix[ctr]);
            }
            ctr++;
        }
        else
            postfix[postCtr++]=infix[ctr++];
    }

    while(!s.isEmpty())
    {
        postfix[postCtr++]=s.pop();
    }

    postfix[postCtr]='\0';
    return postfix;
}

void reverse(char str[])
{
    char temp;
    for(int i=0;i<=strlen(str)/2;i++)
    {
        temp=str[i];
        str[i]=str[strlen(str)-i-1];
        str[strlen(str)-i-1]=temp;
    }
}

void exchangeBrackets(char str[])
{
    for(int i=0;i<strlen(str);i++)
    {
	switch(str[i])
    {
    case '(': str[i]=')';break;
    case '[': str[i]=']';break;
    case '{': str[i]='}';break;
    case ')': str[i]='(';break;
    case ']': str[i]='[';break;
    case '}': str[i]='{';break;

    }
    }
}

char* infixToPrefix(char infix[],char prefix[])
{
    char tmp[50];
    strcpy(tmp,infix);
    reverse(tmp);
    exchangeBrackets(tmp);
    infixToPostfix(tmp,prefix);
    reverse(prefix);
    return prefix;
}

int main()
{
	char infix[50],postfix[50];
    cout<<"\nEnter the infix expression :: ";
    gets(infix);
    if(chkInfix(infix)==false)
    {
    	cout<<"\nInvalid Infix Expression!!!\n\n";
    }
    else
    {
	cout<<"\nPostfix Expression is = "<<infixToPostfix(infix,postfix)<<"\n\n";
    cout<<"\nPrefix Expression is = "<<infixToPrefix(infix,postfix)<<"\n\n";
	}
	system("pause");
    return 0;
}
