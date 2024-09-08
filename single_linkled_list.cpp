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

    return;
}

void insertEnd(Node*& head, int newData)
{
    Node* newNode = new Node();
    newNode-> data = newData;

    newNode-> next = nullptr;

    if (head == nullptr)
    {
        head = newNode;

        cout << "Inserted " << newData << " at the beginning" << endl;

        return;
    }

    Node* temp = head;

    while(temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp-> next = newNode;

    cout << "Inserted " << newData << " at the beginning" << endl;
}

void deleteNode(Node*& head, int key)
{
    Node* temp = head;
    Node* prev = nullptr;

    while(temp != nullptr && temp->data == key)
    {
        head = temp->next;
        delete temp;

        cout << "deleted" << key << "from the list" << endl;

        return;
    }

    if (temp != nullptr && temp->data != key)
    {
        prev = temp;
        temp = temp->next;

    }

    if (temp == nullptr)
    {
        cout << "the" << key << "was not found lmao" << endl;
        return;
    }

    prev->next = temp->next;
    delete temp;

    cout << "deleted" << key << endl;


}

void displayList(Node*& head)
{
    Node* temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    Node *head = nullptr;

    insertBegin(head, 10); // Insert 10 at the beginning
    insertBegin(head, 5);  // Insert 5 at the beginning
    insertEnd(head, 20);   // Insert 20 at the end
    insertEnd(head, 15);   // Insert 15 at the end

    cout << "Linked List: ";
    displayList(head); // Display the linked list

    deleteNode(head, 20); // Delete node with value 20

    cout << "After Deletion: ";
    displayList(head); // Display the linked list after deletion

    return 0;
}
