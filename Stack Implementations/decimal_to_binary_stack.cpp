// convert decimal number into binary using stack
#include <iostream>
using namespace std;

class Stack 
{
    int arr [100];
    int top;

public:
    Stack () 
    {
        top = -1;
    }

    void push (int value) 
    {
        arr [++top] = value;
    }

    int pop () 
    {
        return arr [top--];
    }

    bool isEmpty () 
    {
        return top == -1;
    }
};

int main () 
{
    Stack s;
    int decimal;

    cout << "Enter a decimal number: ";
    cin >> decimal;

    int num = decimal;  // store original number

    // Edge case: if number is 0
    if (num == 0) 
    {
        cout << "Binary: 0" << endl;
        return 0;
    }

    // Step 1: Push remainders into stack
    while (num > 0) 
    {
        int remainder = num % 2;
        s.push (remainder);
        num = num / 2;
    }

    // Step 2: Pop from stack to print in reverse order
    cout << "Binary: ";
    while (!s.isEmpty ()) 
    {
        cout << s.pop ();
    }
    cout << endl;
    return 0;
}
