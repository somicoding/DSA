#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 100
int stack[MAX];
int top = -1;
void push(int value)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}


int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}


int evaluatePostfix(char expression[])
{
    int i;
    int ch;                
    int operand1, operand2, result;

    for (i = 0; i < strlen(expression); i++)
    {
        ch = expression[i];   
        if (ch == ' ')
            continue;
        if (isdigit(ch))
        {
            push(ch - '0');   
        }
        else
        {
            operand2 = pop();   
            operand1 = pop();   

            switch (ch)
            {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/':
                    if (operand2 == 0)
                    {
                        printf("Error: Division by zero\n");
                        return 0;
                    }
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Invalid operator: %c\n", ch);
                    return 0;
            }
            push(result);
        }
    }
    return pop();  
}

int main()
{
    char expression[MAX];
    int result;

    printf("Enter a postfix expression: ");
    scanf("%[^\n]", expression);

    result = evaluatePostfix(expression);

    printf("Result = %d\n", result);

    return 0;
}