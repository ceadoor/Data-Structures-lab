#include <stdio.h>
#include <ctype.h>
char Ar[50];
int top = -1;

void push(char item)
{
    top++;
    Ar[top] = item;
}

char pop() //Return the character when operator appears
{
    char item;
    if (top == -1)
        return -1;
    item = Ar[top];
    top--;
    return item;
}

int precedence(char symbol)
{
    if (symbol == '(')
        return 0;
    if (symbol == '+' || symbol == '-')
        return 1;
    if (symbol == '*' || symbol == '/')
        return 2;
}

void main()
{
    int i;
    char str[20];
    char item, s;
    printf("Enter the infix expression :: ");
    scanf("%s", str);
    printf("The postfix expression is :: ");
    for (i = 0; str[i] != '\0'; i++)
    { /*isalnum is a function which returns true value if the argument passed is an alphabet or a number.
                          Else, it returns zero, and the if block is not executed.*/
        s = str[i];
        if (isalnum(s))
            printf("%c", s);
        else if (s == '(')
            push(s);
        else if (s == ')')
        {
            while ((item = pop()) != '(')
                printf("%c", item);
        }
        else
        {
            while (precedence(Ar[top]) >= precedence(s))
                printf("%c", pop());
            push(s);
        }
    }
    while (top != -1)
    {
        printf("%c", pop());
    }
}
