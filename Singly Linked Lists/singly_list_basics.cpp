#include <iostream>
#include <vector>   // using vector to act like an array
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constructors
    Node() : data(0), next(nullptr) {}
    Node(int val) : data(val), next(nullptr) {}
    Node(int val, Node* nxt) : data(val), next(nxt) {}
};

class SinglyList
{
private:
    Node *head;
    Node *tail;

public:
    SinglyList() : head(nullptr), tail(nullptr) {}

    // Insert at head
    void InsertAtHead(int value)
    {
        Node* newNode = new Node(value, head);
        head = newNode;
        if (tail == nullptr) // first node
            tail = head;
    }

    // Insert at tail
    void InsertAtTail(int value)
    {
        Node* newNode = new Node(value);
        if (tail != nullptr)
        {
            tail->next = newNode;
            tail = newNode;
        }
        else // list was empty
        {
            head = tail = newNode;
        }
    }

    // Task 1: display list in reverse using an array (vector used as dynamic array)
    void displayReverseUsingArray() const
    {
        if (head == nullptr)
        {
            cout << "List Empty\n";
            return;
        }

        // Collect node data into a vector (acts like an array)
        vector<int> arr;
        Node* temp = head;
        while (temp != nullptr)
        {
            arr.push_back(temp->data);
            temp = temp->next;
        }

        // Print in reverse
        cout << "List in reverse (using array): ";
        for (int i = static_cast<int>(arr.size()) - 1; i >= 0; --i)
        {
            cout << arr[i];
            if (i > 0) cout << " -> ";
        }
        cout << "\n";
    }

    // Task 2: search node by value and return the complete node pointer
    Node* searchNode(int value) const
    {
        Node* temp = head;
        while (temp != nullptr)
        {
            if (temp->data == value)
                return temp; // return pointer to the found node
            temp = temp->next;
        }
        return nullptr; // not found
    }

    // helper: display list forward (for demonstration)
    void displayForward() const
    {
        if (head == nullptr)
        {
            cout << "List Empty\n";
            return;
        }
        Node* temp = head;
        cout << "List forward: ";
        while (temp)
        {
            cout << temp->data;
            if (temp->next) cout << " -> ";
            temp = temp->next;
        }
        cout << "\n";
    }

    // destructor to free nodes
    ~SinglyList()
    {
        Node* curr = head;
        while (curr)
        {
            Node* nxt = curr->next;
            delete curr;
            curr = nxt;
        }
    }
};

int main()
{
    SinglyList list;

    // populate list
    list.InsertAtTail(10);
    list.InsertAtTail(20);
    list.InsertAtTail(30);
    list.InsertAtHead(5);   // list: 5 -> 10 -> 20 -> 30

    // show forward
    list.displayForward();

    // Task 1 demonstration: display in reverse using an array
    list.displayReverseUsingArray();

    // Task 2: search node by value and return the node
    int key;
    cout << "Enter the Key you want to search: "; cin >> key;
    Node* found = list.searchNode(key);
    if (found != nullptr)
    {
        cout << "Node found: data = " << found->data << "\n";
        if (found->next)
            cout << "Next node data = " << found->next->data << "\n";
        else
            cout << "This node is the tail (next = nullptr)\n";
    }
    else
    {
        cout << "Value " << key << " not found in list.\n";
    }

    return 0;
}
