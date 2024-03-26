#include <stdio.h>
#include <ctype.h>

#define size 50 /*size of stack*/
char s[size];
int top = -1;

void push(char elem)
{
    s[++top] = elem;
}

char pop()
{
    return (s[top--]);
}

int pr(char elem)
{
    switch (elem)
    {
    case '#':
        return 0;

    case '(':
        return 1;
    case '+':

    case '-':
        return 2;
    case '*':

    case '/':

    case '%':
        return 3;
    case '^':
        return 4;
    }
}

int main()
{
    char infix[50], pofx[50], ch, ele;
    int i = 0, k = 0;
    printf("\n\nEnter the Infix Expression: ");
    scanf("%s", infix);
    push('#');
    while ((ch = infix[i++]) != '\0')
    {
        if (ch == '(')
        {
            push(ch);
        }
        else if (isalnum(ch))
        {
            pofx[k++] = ch;
        }
        else if (ch == ')')
        {
            while (s[top] != '(')
            {
                pofx[k++] = pop();
            }
            ele = pop();
        }
        else
        {
            while (pr(s[top]) >= pr(ch))
            {
                pofx[k++] = pop();
            }
            push(ch);
        }
    }
    while (s[top] != '#')
    {
        pofx[k++] = pop();
    }
    pofx[k] = '\0';
    printf("\nGiven infix expression: %s\nPostfix Expression: %s\n", infix, pofx);
    return 0;
}
