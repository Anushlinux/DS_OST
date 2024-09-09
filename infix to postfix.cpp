#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to return precedence of operators
int precedence(char op)
{
    if (op == '+' || op == '-')
    {
        return 1; // lowest precedence
    }
    if (op == '*' || op == '/')
    {
        return 2; // higher precedence
    }
    return 0;
}

// Function to check if a given character is an operand (a-z, A-Z, or 0-9)
bool isOperand(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

// Function to convert infix to postfix expression
string infixToPostfix(string infix)
{
    stack<char> s;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++)
    {
        char c = infix[i];

        // If the character is an operand, add it to the postfix expression
        if (isOperand(c))
        {
            postfix += c;
        }
        // If the character is '(', push it to the stack
        else if (c == '(')
        {
            s.push(c);
        }
        // If the character is ')', pop from the stack until '(' is found
        else if (c == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // Pop the '(' from the stack
        }
        // If the character is an operator
        else
        {
            while (!s.empty() && precedence(s.top()) >= precedence(c))
            {
                postfix += s.top();
                s.pop();
            }
            s.push(c); // Push the current operator onto the stack
        }
    }

    // Pop all remaining operators from the stack
    while (!s.empty())
    {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main()
{
    string infix;
    cout << "Enter an infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);

    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
