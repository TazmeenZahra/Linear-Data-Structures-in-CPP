// employees and salaries
#include <iostream>
#include <string>
using namespace std;

const int SIZE = 10;
const int DAYS = 5;

class Employee
{
public:
    string name;
    int priority;
    float salary;
    float work_hours[DAYS];
    float weekly_hours;
};

// Insert employee according to priority (Higher priority first)
void insertPriority(Employee pq[], Employee emp, int &count)
{
    int i = count - 1;

    while (i >= 0 && pq[i].priority < emp.priority)
    {
        pq[i + 1] = pq[i];
        i--;
    }

    pq[i + 1] = emp;
    count++;
}

int main()
{
    Employee pq[SIZE];
    int count = 0;

    float totalSalaryBefore = 0;
    float totalSalaryAfter = 0;

    // Adding 10 employees
    for (int i = 0; i < SIZE; i++)
    {
        Employee emp;
        emp.name = "Employee_" + to_string(i + 1);
        emp.priority = (i % 5) + 1;     // priorities 1 to 5
        emp.salary = 30000 + i * 2000;   // simple salary values

        // Daily work hours
        for (int d = 0; d < DAYS; d++)
        {
            emp.work_hours[d] = 8 + (i % 3); // 8, 9, or 10 hours
        }

        insertPriority(pq, emp, count);
    }

    // Processing employees
    cout << "\nEmployees working more than 40 hours per week:\n\n";

    for (int i = 0; i < SIZE; i++)
    {
        Employee &emp = pq[i];

        totalSalaryBefore += emp.salary;

        // Increase salary according to priority
        emp.salary += (emp.salary * emp.priority) / 100;
        totalSalaryAfter += emp.salary;

        // Calculate weekly hours
        emp.weekly_hours = 0;
        for (int d = 0; d < DAYS; d++)
        {
            emp.weekly_hours += emp.work_hours[d];
        }

        // Reduce daily hours if weekly > 40
        if (emp.weekly_hours > 40)
        {
            for (int d = 0; d < DAYS; d++)
            {
                emp.work_hours[d] = emp.work_hours[d] * 0.9;
            }

            // Recalculate weekly hours
            emp.weekly_hours = 0;
            for (int d = 0; d < DAYS; d++)
            {
                emp.weekly_hours += emp.work_hours[d];
            }

            // Display employee details
            cout << "Name: " << emp.name << endl;
            cout << "Priority: " << emp.priority << endl;
            cout << "Updated Salary: " << emp.salary << endl;
            cout << "Weekly Hours: " << emp.weekly_hours << endl;
            cout << "----------------------------\n";
        }
    }

    // Salary summary
    cout << "\nTotal Salary Before Increase: " << totalSalaryBefore << endl;
    cout << "Total Salary After Increase: " << totalSalaryAfter << endl;

    return 0;
}
