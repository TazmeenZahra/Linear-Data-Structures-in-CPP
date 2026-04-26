// implementing stack using singly linked list
#include <iostream>
using namespace std;

class Stack 
{
    struct Node 
    {
        int data;
        Node* next;
    };

    Node* top;   // pointer to the top node

public:
    Stack () 
    {
        top = NULL;
    }

    void push (int value) 
    {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        cout << value << " pushed.\n";
    }

    void pop () 
    {
        if (top == NULL) 
        {
            cout << "Stack is empty.\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        cout << temp->data << " popped.\n";
        delete temp;
    }

    void display () 
    {
        if (top == NULL) 
        {
            cout << "Stack is empty.\n";
            return;
        }
        Node* temp = top;
        cout << "Stack elements: ";
        while (temp != NULL) 
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main () 
{
    Stack s;
    s.push (10);
    s.push (20);
    s.push (30);

    s.display ();

    s.pop ();
    s.display ();

    return 0;
}
