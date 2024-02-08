#include <iostream>
#include <string.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int data)
    {
        val = data;
        next = NULL;
    }
};

void insertAtHead(Node *&head, int val)
{
    Node *new_node = new Node(val);
    new_node->next = head;
    head = new_node;
}

void insertAtEnd(Node *&head, int val)
{
    Node *new_node = new Node(val);
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}

void insertAtPos(Node *&head, int pos, int val)
{
    if (pos == 0)
    {
        insertAtHead(head, val);
    }
    else
    {
        Node *new_node = new Node(val);
        Node *temp = head;
        int current_pos = 0;
        while (current_pos != pos - 1)
        {
            temp = temp->next;
            current_pos++;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

void updateAtPos(Node *&head, int pos, int val)
{
    Node *temp = head;
    int current_pos = 0;
    while (current_pos != pos)
    {
        temp = temp->next;
        current_pos++;
    }
    temp->val = val;
}

void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    Node *head = NULL;
    int x;
    while (1)
    {

        cout << "1. Insert at beginning" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Display the Link List" << endl;
        cout << "4. Insert at any position" << endl;
        cout << "5. update at any position" << endl;
        cout << "6. delete at any position" << endl;

        cout << "9. Exit" << endl;
        cout << "Enter the choice: ";
        cin >> x;

        if (x == 1)
        {
            int a;
            cout << "Enter the value: ";
            cin >> a;
            insertAtHead(head, a);
        }
        else if (x == 2)
        {
            int a;
            cout << "Enter the value: ";
            cin >> a;
            insertAtEnd(head, a);
        }
        else if (x == 3)
        {
            display(head);
        }
        else if (x == 4)
        {
            int a, b;
            cout << "Enter the position: ";
            cin >> a;
            cout << "Enter the value: ";
            cin >> b;
            insertAtPos(head, a, b);
        }
        else if (x == 5)
        {
            int pos, val;
            cout << "Enter the position: ";
            cin >> pos;
            cout << "Enter the value: ";
            cin >> val;
            updateAtPos(head, pos, val);
        }
        else if (x==6)
        {

        }
        
        else if (x == 9)
        {
            break;
        }
        else
        {
            cout << "Error" << endl;
        }
    }

    return 0;
}

