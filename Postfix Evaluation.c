#include<stdio.h>
typedef enum precedence {lparen,rparen,plus,minus,multiply,divide,mod,eos,operand}precedence;
char expr[100];
int stack[100];
int top=-1;
precedence getToken(char *symbol,int *n)
{
	*symbol=expr[(*n)++];
	switch(*symbol)
	{
		case '(': return lparen;
		case ')': return rparen;
		case '+': return plus;
		case '-': return minus;
		case '*': return multiply;
		case '/': return divide;
		case '%': return mod;
		case ' ': return eos;
		case '\0': return eos; 
		default: return operand;
	}
}
void push(int token)
{
	stack[++top]=token;
}
int pop()
{
	return stack[top--];
}
int eval(void)
{
	precedence token;
	char symbol;
	int op1,op2;
	int n=0;
	token=getToken(&symbol,&n);
	while(token!=eos)
	{
		if(token==operand)
		{
			push(symbol-'0');
		}
		else
		{
			op2=pop();
			op1=pop();
			switch(token)
			{
				case lparen: break;
				case rparen: break;
				case plus: push(op1+op2);
							break;
				case minus: push(op1-op2);
							break;
				case multiply: push(op1*op2);
								break;
				case divide: push(op1/op2);
								break;
				case mod: push(op1%op2);
							break;
				case eos: break;
				case operand: break;
			}
		}
		token=getToken(&symbol,&n);
	}
	return pop();
}
int main()
{
	printf("Enter expression: ");
	scanf("%s",expr);
	printf("Result: %d",eval());
}