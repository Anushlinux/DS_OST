#include <iostream>
#include <stack>
#include <string>
using namespace std;

string reverseString(string str, int& count)
{
    stack<char> s;
    count = 0;

    for(int i = 0; i < str.length(); i++)
    {
        s.push(str[i]);
        count++;
    }

    string reversed = "";

    while(!s.empty())
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

    int count;

    string reverseStr = reverseString(str, count);

    cout << "The reversed string is " << reverseStr << endl;
    cout << "Num of elements is " << count << endl;

    return 0;

}

