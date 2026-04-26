#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
    int ID;
    string Name;
    float GPA;
    Student* next;

    // Constructors
    Student() : ID(0), Name(""), GPA(0.0f), next(nullptr) {}
    Student(int id, const string& name, float gpa) : ID(id), Name(name), GPA(gpa), next(nullptr) {}
};

class StudentList
{
private:
    Student* head;
    Student* tail;

public:
    StudentList() : head(nullptr), tail(nullptr) {}

    // Insert at head
    void InsertAtHead(int id, const string& name, float gpa)
    {
        Student* node = new Student(id, name, gpa);
        node->next = head;
        head = node;
        if (tail == nullptr)
        {
            // list was empty
            tail = node;
        }
    }

    // Insert at tail
    void InsertAtTail(int id, const string& name, float gpa)
    {
        Student* node = new Student(id, name, gpa);
        if (tail != nullptr)
        {
            tail->next = node;
            tail = node;
        }
        else // empty list
        {
            head = tail = node;
        }
    }

    // prev_node must be a pointer to an existing node in the list.
    void InsertAfter(Student* prev_node, int id, const string& name, float gpa)
    {
        if (prev_node == nullptr)
        {
            cout << "The given previous node cannot be NULL.\n";
            return;
        }

        Student* new_node = new Student(id, name, gpa);
        new_node->next = prev_node->next;
        prev_node->next = new_node;

        // If we inserted after the tail, update tail
        if (prev_node == tail)
        {
            tail = new_node;
        }
    }

    // Search for a student by ID and return pointer to the node (nullptr if not found)
    Student* SearchByID(int id) const
    {
        Student* temp = head;
        while (temp != nullptr)
        {
            if (temp->ID == id)
                return temp;
            temp = temp->next;
        }
        return nullptr;
    }

    // Display all students
    void DisplayAll() const
    {
        if (head == nullptr)
        {
            cout << "No student records.\n";
            return;
        }

        cout << "Student Records:\n";
        cout << "----------------\n";
        Student* temp = head;
        while (temp != nullptr)
        {
            cout << "ID: " << temp->ID
                 << " | Name: " << temp->Name
                 << " | GPA: " << temp->GPA << '\n';
            temp = temp->next;
        }
        cout << "----------------\n";
    }

    // Utility: find a node by ID and return pointer (same as SearchByID; included for clarity)
    Student* findNode(int id) const
    {
        return SearchByID(id);
    }

    // Destructor: free nodes
    ~StudentList()
    {
        Student* curr = head;
        while (curr)
        {
            Student* nxt = curr->next;
            delete curr;
            curr = nxt;
        }
    }
};

int main()
{
    StudentList sl;

    // Insert some records at tail
    sl.InsertAtTail(101, "Aisha Khan", 3.6f);
    sl.InsertAtTail(102, "Bilal Ahmed", 3.2f);
    sl.InsertAtTail(103, "Fatima Noor", 3.9f);

    // Insert at head
    sl.InsertAtHead(100, "Zara Ali", 3.8f); // now 100 is head

    cout << "Display current list" << endl;
    sl.DisplayAll();

    // Insert in middle: Insert after student with ID 102
    Student* prev = sl.findNode(102);
    if (prev != nullptr)
    {
        sl.InsertAfter(prev, 105, "Hassan Raza", 3.4f);
    }
    else
    {
        cout << "Previous node with ID 102 not found; cannot insert after it.\n";
    }

    cout << "Display after middle insertion" << endl;
    sl.DisplayAll();

    // Demonstrate search
    int key = 103;
    Student* found = sl.SearchByID(key);
    if (found)
    {
        cout << "Search result -> ID: " << found->ID
             << ", Name: " << found->Name
             << ", GPA: " << found->GPA << '\n';
    }
    else
    {
        cout << "Student with ID " << key << " not found.\n";
    }

    return 0;
}
