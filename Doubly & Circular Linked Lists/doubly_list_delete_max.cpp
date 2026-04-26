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

    void insertAtHead(int value) {
        head = new Node(value, head);
        if (tail == 0)
            tail = head;
        else
            head->next->prev = head;
    }

    void InsertAtTail(int value) {
        if (tail != 0) {
            tail->next = new Node(value, 0, tail);
            tail = tail->next;
        } else {
            head = tail = new Node(value);
        }
    }

    // FUNCTION TO FIND MAXIMUM VALUE
    int Maxvalue() {
        if (head == 0) {
            cout << "List is empty\n";
            return -1;
        }

        Node *temp = head;
        int maxVal = temp->data;

        while (temp != 0) {
            if (temp->data > maxVal)
                maxVal = temp->data;
            temp = temp->next;
        }
        return maxVal;
    }

    // FUNCTION TO DELETE NODE WITH MAX VALUE
    void DeleteNode() {
        int maxVal = Maxvalue();
        if (maxVal == -1)
            return;

        Node *temp = head;

        while (temp != 0 && temp->data != maxVal)
            temp = temp->next;

        if (temp == 0)
            return;

        if (head == tail && temp == head) {
            delete head;
            head = tail = 0;
        }
        else if (temp == head) {
            head = head->next;
            head->prev = 0;
            delete temp;
        }
        else if (temp == tail) {
            tail = tail->prev;
            tail->next = 0;
            delete temp;
        }
        else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        }

        cout << "Deleted max value: " << maxVal << endl;
    }

    void display() {
        Node *temp = head;
        while (temp != 0) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyList list;

    list.InsertAtTail(10);
    list.InsertAtTail(25);
    list.InsertAtTail(15);
    list.InsertAtTail(40);
    list.InsertAtTail(5);

    cout << "Original List: ";
    list.display();

    cout << "Maximum Value: " << list.Maxvalue() << endl;

    list.DeleteNode();

    cout << "List after deleting max: ";
    list.display();

    return 0;
}
