#include <iostream>
#include <stack>
#include <string>
using namespace std;

class undoredoManager
{
private:
    stack<string> undostack;
    stack<string> redostack;


public:
    void performAction(const string& action)
    {
        undostack.push(action);

        //clear the redo
        while(!redostack.empty())
        {
            redostack.pop();
        };

        cout << "WE did " << action << endl;
    };

    void undo()
    {
        if (undostack.empty())
        {
            cout << "Nothing to undo " << endl;
        }
        else
        {
            string action = undostack.top();
            undostack.pop();
            redostack.push(action);

            cout << "undone" << action << endl;
        };


    };

    void redo()
    {
        if (redostack.empty())
        {
            cout << "Nothing to redo" << endl;
        }
        else  
        {
            string action = redostack.top();
            redostack.pop();
            undostack.push(action);

            cout << "redid " << action << endl;
        };
    };

};

int main()
{
    undoredoManager manage;

    manage.performAction("action 1");
    manage.performAction("action 2");
    manage.performAction("action 3");

    manage.undo();

    manage.performAction("Action 4");

    manage.redo();

    return 0;
}