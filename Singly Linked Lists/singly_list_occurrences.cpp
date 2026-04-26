#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node (int value, Node* add = nullptr)
    {
        data = value;
        next = add;
    }
};

class SinglyList
{
    public:
    Node* head, * tail;
    SinglyList ()
    {
        head = tail = nullptr;
    }

    void InsertAtHead (int value)
    {
        if (head == 0) // list is empty, add one node
        {
            head = new Node (value, head);
            tail = head;
        }
        else
        {
            Node *temp;
            temp = head;
            head = new Node (value, nullptr);
            head->next = temp;
        }
    }

    void InsertAtTail (int value)
    {
        if (tail == 0) // list empty
        {
            head = tail = new Node(value, nullptr);
        }
        else 
        {
            tail->next = new Node(value, nullptr);
            tail = tail->next;
        }
    }

    void display ()
    {
        Node *temp = head;
        if (head == 0)
        {
            cout << "List Empty. Create Nodes First." << endl;
        }
        else
        {
            cout << "-----List-----" << endl;
            while (temp != 0)
            {
                cout << temp->data << " | " << temp->next << endl;
                temp = temp->next;
            }
            cout << "--------------" << endl;
        }
    }

    void occurences ()
    {
        Node *temp = head;
        if (head = 0)
        {
            cout << "List Empty." << endl;
        }

        int searchKey; int counter = 0;
        cout << "Enter the data you want to find occurences in list: ";
        cin >> searchKey;

        while (temp != 0)
        {
            if (temp->data == searchKey)
            {
                counter++;
            }
            temp = temp->next;
        }

        if (counter > 0)
        {
            cout << searchKey << " is present in data " << counter << " times." << endl;
        }
        else
        {
            cout << searchKey << " is not present in the list." << endl;
        }
    }
};

int main ()
{
    SinglyList list;
    list.display ();
    list.InsertAtHead (20);
    list.InsertAtHead (10);
    list.InsertAtTail (10);
    list.InsertAtTail (20);
    list.display ();

    list.occurences (); // check for value present
    list.occurences (); // check for value not present

    return 0;
}
