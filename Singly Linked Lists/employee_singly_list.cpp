#include <iostream>
using namespace std;

class Employee
{
public:
    int ID;
    string name;
    float salary;
    Employee *next;

    Employee(int id, string n, float s, Employee *add = nullptr)
    {
        ID = id;
        name = n;
        salary = s;
        next = add;
    }
};

class SinglyList
{
public:
    Employee *head, *tail;

    SinglyList()
    {
        head = tail = nullptr;
    }

    void insertAtHead(int i, string n, float s)
    {
        if (head == nullptr)
            head = tail = new Employee(i, n, s, nullptr);
        else
            head = new Employee(i, n, s, head);
    }

    void insertAtLast(int i, string n, float s)
    {
        if (tail == nullptr)
            head = tail = new Employee(i, n, s, nullptr);
        else
        {
            tail->next = new Employee(i, n, s, nullptr);
            tail = tail->next;
        }
    }

    void displayList()
    {
        if (head == nullptr)
        {
            cout << "\nList Empty!\n";
            return;
        }

        cout << "\n------ Employee List ------\n";
        Employee *temp = head;
        while (temp != nullptr)
        {
            cout << "ID: " << temp->ID
                 << " | Name: " << temp->name
                 << " | Salary: " << temp->salary << endl;
            temp = temp->next;
        }
        cout << "----------------------------\n";
    }

    void DeleteAtHead()
    {
        if (head == nullptr)
        {
            cout << "\nList already empty.\n";
            return;
        }

        Employee *temp = head;
        int value = temp->ID;

        if (head == tail)
            head = tail = nullptr;
        else
            head = head->next;

        delete temp;
        cout << "Employee with ID " << value << " deleted from head.\n";
    }

    void DeleteLast()
    {
        if (head == nullptr)
        {
            cout << "\nList already empty.\n";
            return;
        }

        int value = tail->ID;

        if (head == tail)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            Employee *temp = head;
            while (temp->next != tail)
                temp = temp->next;

            delete tail;
            tail = temp;
            tail->next = nullptr;
        }

        cout << "Employee with ID " << value << " deleted from end.\n";
    }

    void DeleteMid(int value)
    {
        if (head == nullptr)
        {
            cout << "\nList empty.\n";
            return;
        }

        if (head->ID == value)
        {
            DeleteAtHead();
            return;
        }

        Employee *prev = head;
        Employee *curr = head->next;

        while (curr != nullptr && curr->ID != value)
        {
            prev = curr;
            curr = curr->next;
        }

        if (curr == nullptr)
        {
            cout << "Employee ID not found.\n";
            return;
        }

        prev->next = curr->next;
        if (curr == tail)
            tail = prev;

        delete curr;
        cout << "Employee with ID " << value << " deleted.\n";
    }
};

int main()
{
    SinglyList list;
    int choice, id;
    string name;
    float salary;

    do
    {
        cout << "\n====== Employee Linked List Menu ======\n";
        cout << "1. Insert at Head\n";
        cout << "2. Insert at Tail\n";
        cout << "3. Delete from Head\n";
        cout << "4. Delete from Tail\n";
        cout << "5. Delete by ID\n";
        cout << "6. Display List\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter ID Name Salary: ";
            cin >> id >> name >> salary;
            list.insertAtHead(id, name, salary);
            break;

        case 2:
            cout << "Enter ID Name Salary: ";
            cin >> id >> name >> salary;
            list.insertAtLast(id, name, salary);
            break;

        case 3:
            list.DeleteAtHead();
            break;

        case 4:
            list.DeleteLast();
            break;

        case 5:
            cout << "Enter ID to delete: ";
            cin >> id;
            list.DeleteMid(id);
            break;

        case 6:
            list.displayList();
            break;

        case 0:
            cout << "\nProgram terminated.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}
