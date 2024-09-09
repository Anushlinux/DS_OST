#include <iostream>
#include <stack>
using namespace std;

class staticStack
{
    int top;
    int maxSize;
    int* stackArray;
public:
    staticStack(int size)
    {
        maxSize = size;
        stackArray = new int[maxSize];
        top = -1;
    };

    bool ifEmpty()
    {
        return top == -1;
    };

    bool ifFull()
    {
        return top == maxSize - 1;
    };

    void push(int k)
    {
        if (ifFull())
        {
            cout << "Cant enter more" << endl;
        }
        else
        {
            stackArray[++top] = k;
            cout << k << "has been pushed";
        };
    };

    void pop()
    {
        if (ifEmpty())
        {
            cout << "CANT delete furter";
        }
        else
        {
            cout << stackArray[top--] << "has been removed";
        };

    };

    int peek()
    {
        if(ifEmpty())
        {
            cout << "lol";
        }
        return stackArray[top];

    }
};

int main()
{
    staticStack stack(5); // Create a stack of size 5

    // Push elements onto the stack
    stack.push(10);
    stack.push(20);
    stack.push(30);

    // Get the top element
    cout << "Top element is: " << stack.peek() << endl;

    // Pop elements from the stack
    stack.pop();
    stack.pop();

    // Check the top element after popping
    cout << "Top element is: " << stack.peek() << endl;

    // Push more elements
    stack.push(40);
    stack.push(50);
    stack.push(60); // Stack should now be full

    // Try to push when stack is full
    stack.push(70); // This should give an error

    return 0;
}