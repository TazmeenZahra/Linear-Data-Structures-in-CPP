// static priroty queue array
#include <iostream>
using namespace std;

const int SIZE = 5;

struct PriorityQueue
{
    int data;
    int priority;
};

int main()
{
    PriorityQueue pq[SIZE];

    // Given data and priorities
    int data[5] = {10, 8, 7, 6, 5};
    int priority[5] = {8, 6, 5, 3, 2};

    int count = 0;

    // Insert elements according to priority
    for(int i = 0; i < SIZE; i++)
    {
        int j = count - 1;

        while(j >= 0 && pq[j].priority < priority[i])
        {
            pq[j + 1] = pq[j];
            j--;
        }

        pq[j + 1].data = data[i];
        pq[j + 1].priority = priority[i];
        count++;
    }

    // Display priority queue
    cout << "Static Priority Queue:\n";
    for(int i = 0; i < SIZE; i++)
    {
        cout << "Data = " << pq[i].data
             << ", Priority = " << pq[i].priority << endl;
    }

    return 0;
}
