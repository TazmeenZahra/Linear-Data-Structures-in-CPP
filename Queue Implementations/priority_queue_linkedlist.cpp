// priority queue link list
#include <iostream>
using namespace std;

struct Node
{
    int data;
    int priority;
    Node* next;
};

int main()
{
    Node* front = NULL;

    int data[5] = {10, 8, 7, 6, 5};
    int priority[5] = {8, 6, 5, 3, 2};

    // Insert elements
    for(int i = 0; i < 5; i++)
    {
        Node* newNode = new Node();
        newNode->data = data[i];
        newNode->priority = priority[i];
        newNode->next = NULL;

        if(front == NULL || front->priority < newNode->priority)
        {
            newNode->next = front;
            front = newNode;
        }
        else
        {
            Node* temp = front;
            while(temp->next != NULL && temp->next->priority >= newNode->priority)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    // Display priority queue
    cout << "Dynamic Priority Queue:\n";
    Node* temp = front;
    while(temp != NULL)
    {
        cout << "Data = " << temp->data
             << ", Priority = " << temp->priority << endl;
        temp = temp->next;
    }

    return 0;
}
