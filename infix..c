#include<stdio.h>
#include<string.h>
#include<ctype.h>
# define max 10
char s[max];
int top=-1;
int isoperator(char);
int prec(char);
void push(char item)
{
	if(top==max-1)
		printf("overflow");
	else
	{
		top=top+1;
		s[top]=item;
	}

}
char pop()
{
	char item;
	if(top==-1)
		printf("underflow");
	else
	{
		item =s[top];
		top=top-1;;
	}
	return item;
}
int prec(char c)
{
	if(c=='^')
		return 3;
	else if(c=='*'||c=='/')
		return 2;
	else if(c=='+'||c=='-')
		return 1;
	else 
		return 0;
}
int isoperator(char c)
{
	if(c=='+'||c=='-'||c=='/'||c=='*'||c=='^')
		return 1;
	else 
		return 0;
}
void infixtopostfix(char infix[],char postfix[])
{
	int i,j;
	push('(');
	strcat(infix,")");
	i=0;j=0;
	while(infix[i]!='\0')
	{
		if(isdigit(infix[i])||isalpha(infix[i]))
		{
			postfix[j]=infix[i];
			j++;
		}
		else if (infix[i]=='(')
		{
			push(infix[i]);
		}
		else if(isoperator(infix[i]))
		{
			while(prec(s[top])>=prec(infix[i]))
					{
					postfix[j]=pop();
					j++;
					}
			push(infix[i]);
		}
		else if (infix[i]==')')
		{
			while(s[top]!='(')
			{
				postfix[j]=pop();
				j++;
			}
			pop();
		}
		else
			printf("invalid expression");
		i++;
	}
	postfix[j]='\0';
}
void main()
{
	char infix[20],postfix[20];
	printf("input infix expression");

	scanf("%s",infix);
	infixtopostfix(infix,postfix);
	printf("postfix expression %s",postfix);
}
