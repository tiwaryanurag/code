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

void delAtHead(Node *&head)
{
    Node *temp = head;
    head = head->next;
    free(temp);
}

void delAtEnd(Node *&head)
{
    Node *second_last = head;
    while (second_last->next->next != NULL)
    {
        second_last = second_last->next;
    }
    Node *temp = second_last->next; // node to be deleted at the end
    second_last->next = NULL;
    free(temp);
}

void delAtPos(Node *&head, int pos)
{
    Node *prev = head;
    int curremt_pos = 0;
    while (curremt_pos != pos - 1)
    {
        prev = prev->next;
        curremt_pos++;
    }
    Node *temp = prev->next; // node to be deleted
    prev->next = prev->next->next;
    free(temp);
}

void delAltElement(Node *&head)
{
    Node *curr_node = head;
    while (curr_node != NULL && curr_node->next != NULL)
    {
        Node *temp = curr_node->next;
        curr_node->next = curr_node->next->next;
        free(temp);
        curr_node = curr_node->next;
    }
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
        cout << "6. delete at head" << endl;
        cout << "7. delete at tail" << endl;
        cout << "8. delete at any position: " << endl;
        cout << "9. delete alternate position element: " << endl;

        
        cout << "0. Exit" << endl;
        cout << "Enter the choice:- ";
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
        else if (x == 6)
        {
            delAtHead(head);
        }
        else if (x == 7)
        {
            delAtEnd(head);
        }
        else if (x == 8)
        {
            int pos;
            cout << "Enter the position: ";
            cin >> pos;
            delAtPos(head, pos);
        }
        else if (x == 9)
        {
            delAltElement(head);
        }

        else if (x == 0)
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
