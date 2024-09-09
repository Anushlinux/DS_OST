#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

string palindromeChecker(string str)
{
    stack<char> s;

    for (int i = 0; i < str.length(); i++)
    {
        s.push(str[i]);
    }

    string reversed = "";

    while (!s.empty())
    {
        reversed += s.top();
        s.pop();
    }
    return reversed;
}

int main()
{
    string str;

    cout << "Enter the string ";
    getline(cin , str);

    string reverseStr = palindromeChecker(str);

    if (str == reverseStr)
    {
        cout << "The string is an a palindrome" << endl;
    }
    else
    {
        cout << "Its not" << endl;
    }

    return 0;

}