#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int value, Node *nextNode = 0) {
        data = value;
        next = nextNode;
    }
};

class CircularList {
public:
    Node *head, *tail;

    CircularList() {
        head = tail = 0;
    }

    // INSERT AT FRONT
    void insertAtFront(int value) {
        Node *newNode = new Node(value);
        if (head == 0) {
            head = tail = newNode;
            tail->next = head;
        } else {
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
    }

    // INSERT AT END
    void insertAtEnd(int value) {
        Node *newNode = new Node(value);
        if (head == 0) {
            head = tail = newNode;
            tail->next = head;
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }

    // INSERT IN MIDDLE (AFTER A VALUE)
    void insertInMid(int prevValue, int value) {
        if (head == 0) {
            cout << "List is empty\n";
            return;
        }

        Node *temp = head;
        do {
            if (temp->data == prevValue) {
                Node *newNode = new Node(value, temp->next);
                temp->next = newNode;
                if (temp == tail)
                    tail = newNode;
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Value not found for insertion\n";
    }

    // DELETE AT FRONT
    void deleteAtFront() {
        if (head == 0) {
            cout << "List is empty\n";
            return;
        }

        if (head == tail) {
            delete head;
            head = tail = 0;
        } else {
            Node *temp = head;
            head = head->next;
            tail->next = head;
            delete temp;
        }
    }

    // DELETE AT END
    void deleteAtEnd() {
        if (head == 0) {
            cout << "List is empty\n";
            return;
        }

        if (head == tail) {
            delete head;
            head = tail = 0;
        } else {
            Node *temp = head;
            while (temp->next != tail)
                temp = temp->next;

            temp->next = head;
            delete tail;
            tail = temp;
        }
    }

    // DELETE IN MIDDLE (BY VALUE)
    void deleteInMid(int value) {
        if (head == 0) {
            cout << "List is empty\n";
            return;
        }

        if (head->data == value) {
            deleteAtFront();
            return;
        }

        Node *temp = head;
        Node *prev = 0;

        do {
            prev = temp;
            temp = temp->next;

            if (temp->data == value) {
                prev->next = temp->next;
                if (temp == tail)
                    tail = prev;
                delete temp;
                return;
            }
        } while (temp != head);

        cout << "Value not found for deletion\n";
    }

    // SEARCH
    void search(int value) {
        if (head == 0) {
            cout << "List is empty\n";
            return;
        }

        Node *temp = head;
        int pos = 1;
        do {
            if (temp->data == value) {
                cout << "Value found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        } while (temp != head);

        cout << "Value not found\n";
    }

    // DISPLAY LIST
    void displayList() {
        if (head == 0) {
            cout << "List is empty\n";
            return;
        }

        Node *temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    CircularList list;

    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);
    list.insertAtEnd(5);

    cout << "Original List: ";
    list.displayList();

    list.insertAtFront(10);
    list.insertAtEnd(20);
    list.insertInMid(3, 15);

    cout << "After Insertions: ";
    list.displayList();

    list.deleteAtFront();
    list.deleteInMid(15);
    list.deleteAtEnd();

    cout << "After Deletions: ";
    list.displayList();

    list.search(4);
    list.search(100);

    return 0;
}
