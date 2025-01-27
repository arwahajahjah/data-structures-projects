#include<iostream> 
using namespace std;

class postfix_project
{
private:
    char stack[25];
    int top = -1;
    int stack_int[25];
    int top_int = -1;

public:
    void push(char item);
    char pop();
    int precedence(char symbol);
    int isOperator(char symbol);
    void convert(char infix[], char postfix[]);
    void push_int(int item);
    int pop_int();
    int evaluate(char* postfix);
};

void postfix_project::push(char item) {
    stack[++top] = item;
}

char postfix_project::pop() {
    return stack[top--];
}

//returns precedence of operators
int postfix_project::precedence(char symbol) {

    switch (symbol) {
    case '+':
    case '-':
        return 2;
        break;
    case '*':
    case '/':
        return 3;
        break;
    case '^':
        return 4;
        break;
    case '(':
    case ')':
    case '#':
        return 1;
        break;
    }
}

//check whether the symbol is operator?
int postfix_project::isOperator(char symbol) {

    switch (symbol) {
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
    case '(':
    case ')':
        return 1;
        break;
    default:
        return 0;
    }
}
























//converts infix expression to postfix
void postfix_project::convert(char infix[], char postfix[])
{
    int i, symbol, j = 0;
    stack[++top] = '#';
    int k = 0;
    while (infix[k] != '\0') k++;
    int length = k;
    for (i = 0; i < length; i++)
    {
        symbol = infix[i];
        if (isOperator(symbol) == 0)
        {
            postfix[j] = symbol;
            j++;
        }
        else
        {
            if (symbol == '(')
            {
                push(symbol);
            }
            else
            {
                if (symbol == ')')
                {
                    while (stack[top] != '(')
                    {
                        postfix[j] = pop();
                        j++;
                    }
                    pop();   //pop out (. 
                }
                else
                {
                    if (precedence(symbol) > precedence(stack[top]))
                    {
                        push(symbol);
                    }
                    else
                    {
                        while (precedence(symbol) <= precedence(stack[top]))
                        {
                            postfix[j] = pop();
                            j++;
                        }
                        push(symbol);
                    }
                }
            }
        }// end else
    }// end for	

    while (stack[top] != '#')
    {
        postfix[j] = pop();
        j++;
    } // end while
} // end function

void postfix_project::push_int(int item) {
    stack_int[++top_int] = item;
}

int postfix_project::pop_int() {
    return stack_int[top_int--];
}

//evaluates postfix expression
int postfix_project::evaluate(char postfix[])
{
    char ch;
    int i = 0, operand1, operand2;
    while ((ch = postfix[i++]) != '\0')
    {
        if (isdigit(ch))
        {
            push_int(ch - '0');  // Push the operand 
        }
        else
        {
            //Operator,pop two  operands 
            operand2 = pop_int();
            operand1 = pop_int();

            switch (ch) {
            case '+': push_int(operand1 + operand2);
                break;
            case '-': push_int(operand1 - operand2);
                break;
            case '*': push_int(operand1 * operand2);
                break;
            case '/': push_int(operand1 / operand2);
                break;
            }
        }
    }

    return stack_int[top_int];
}


main()
{
    postfix_project pfx;
    char infix[25] = "(3*2)+(6+4)*2", postfix[25];
    pfx.convert(infix, postfix);
    cout << "Infix expression is:" << infix << endl;
    cout << "Postfix expression is:" << postfix << endl;
    cout << "Evaluated expression is:" << pfx.evaluate(postfix);
}
