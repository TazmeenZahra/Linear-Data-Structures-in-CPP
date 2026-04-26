//static queue array
#include <iostream>
using namespace std;

const int SIZE = 5;

int main()
{
    int queue[SIZE];
    int front = 0;
    int rear = -1;

    // Inserting elements into queue
    int data[5] = {7, 8, 5, 10, 6};

    for(int i = 0; i < SIZE; i++)
    {
        rear++;
        queue[rear] = data[i];
    }

    // Displaying queue
    cout << "Static Queue Elements: ";
    for(int i = front; i <= rear; i++)
    {
        cout << queue[i] << " ";
    }

    return 0;
}
