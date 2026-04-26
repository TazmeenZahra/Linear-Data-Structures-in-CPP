// implementing stack using array
#include <iostream>
using namespace std;

class Stack 
{
    int arr [10];
    int top;

public:
    Stack () 
    {
        top = -1;
    }

    void push (int value) 
    {
        if (top == 9) 
        {
            cout << "Stack overflow.\n";
            return;
        }
        else
        {
            top++;
            arr [top] = value;
            cout << value << " pushed.\n";
        }
    }

    void pop () 
    {
        if (top == -1) 
        {
            cout << "Stack underflow.\n";
            return;
        }
        else
        {
            top--;
            cout << arr [top] << " popped.\n";
        }
    }

    void display () 
    {
        if (top == -1) 
        {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i --) 
        {
            cout << arr [i] << " ";
        }
        cout << endl;
    }
};

int main () 
{
    Stack s;
    s.push (5);
    s.push (15);
    s.push (25);

    s.display ();

    s.pop ();
    s.display ();

    return 0;
}
