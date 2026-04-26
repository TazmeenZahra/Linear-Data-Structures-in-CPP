// dynamic queue link list
#include <iostream>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node* next;
};

int main()
{
    Node* front = NULL;
    Node* rear = NULL;

    int data[5] = {7, 8, 5, 10, 6};

    // Inserting elements into queue
    for(int i = 0; i < 5; i++)
    {
        Node* newNode = new Node();
        newNode->data = data[i];
        newNode->next = NULL;

        if(front == NULL)
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Displaying queue
    cout << "Dynamic Queue Elements: ";
    Node* temp = front;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}
