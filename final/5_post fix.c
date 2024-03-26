#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX 50
int stack[MAX];
char post[MAX];
int top = -1;

/* Function Prototypes */
void pushstack(int tmp);
void calculator(char c);

void main() {
    int i;
    printf("Insert a postfix notation :: ");
    scanf("%s", post);
    for (i = 0; post[i] != '\0'; i++) {
        if (post[i] >= '0' && post[i] <= '9') {
            pushstack(i);
        }
        else if (post[i] == '+' || post[i] == '-' || post[i] == '*' || post[i] == '/' || post[i] == '^') {
            calculator(post[i]);
        }
    }
    printf("\n\nResult :: %d", stack[top]);
}

void pushstack(int tmp) {
    top++;
    stack[top] = (int)(post[tmp] - '0');
}

void calculator(char c) {
    int a, b, ans;
    a = stack[top];
    top--;
    b = stack[top];
    top--;
    switch (c) {
        case '+':
            ans = b + a;
            break;
        case '-':
            ans = b - a;
            break;
        case '*':
            ans = b * a;
            break;
        case '/':
            ans = b / a;
            break;
        case '^':
            ans = pow(b, a);
            break;
        default:
            ans = 0;
    }
    top++;
    stack[top] = ans;
}
