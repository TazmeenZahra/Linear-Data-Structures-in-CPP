// implementing stack using vector
#include <iostream>
#include <vector>
using namespace std;

class Stack 
{
    vector <int> v;

public:
    void push (int value) 
    {
        v.push_back (value);
        cout << value << " pushed.\n";
    }

    void pop () 
    {
        if (v.empty ()) 
        {
            cout << "Stack is empty.\n";
            return;
        }
        else
        {
            cout << v.back () << " popped.\n";
            v.pop_back ();
        }
    }

    void display () 
    {
        if (v.empty ()) 
        {
            cout << "Stack is empty.\n";
            return;
        }

        cout << "Stack elements: ";
        for (int i = v.size () - 1; i >= 0; i --) 
        {
            cout << v [i] << " ";
        }
        cout << endl;
    }
};

int main () 
{
    Stack s;
    s.push (100);
    s.push (200);
    s.push (300);

    s.display ();

    s.pop ();
    s.display ();

    return 0;
}
