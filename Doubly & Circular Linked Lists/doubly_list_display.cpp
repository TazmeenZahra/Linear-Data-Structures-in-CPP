#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev;

    Node(int value, Node *nextNode = 0, Node *prevNode = 0) {
        data = value;
        next = nextNode;
        prev = prevNode;
    }
};

class DoublyList {
public:
    Node *head, *tail;

    DoublyList() {
        head = tail = 0;
    }

    void InsertAtTail(int value) {
        if (tail != 0) {
            tail->next = new Node(value, 0, tail);
            tail = tail->next;
        } else {
            head = tail = new Node(value);
        }
    }

    void displayForward() {
        Node *temp = head;
        while (temp != 0) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void displayBackward() {
        Node *temp = tail;
        while (temp != 0) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyList list;

    // Insert 7 numbers at last
    for (int i = 1; i <= 7; i++) {
        list.InsertAtTail(i);
    }

    cout << "Forward: ";
    list.displayForward();

    cout << "Backward: ";
    list.displayBackward();

    return 0;
}
