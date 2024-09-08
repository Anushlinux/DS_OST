#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertBegin(Node*& head, int newData)
{
    Node* newNode = new Node();

    newNode -> data = newData;

    newNode -> next = head;

    head = newNode;

    cout << "insterted" << newData << "at the begining" << endl;
}

