#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    int id;
    double salary;

    static int employeeCount;

public:
    static string companyName;

    // Constructor initializer list
    Employee(string n, int i, double s) : name(n), id(i), salary(s) {
        employeeCount++;
    }

    // Copy constructor 
    Employee(const Employee& emp) : name(emp.name), id(emp.id), salary(emp.salary) {
        employeeCount++;
    }

    // Display employee details
    void displayEmployee() const {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Salary: " << salary << endl;
    }

    // Static function to display total employees
    static void displayEmployeeCount() {
        cout << "Total Employees: " << employeeCount << endl;
    }

    // Modify employee data
    void modifyEmployee(string n, int i, double s) {
        name = n;
        id = i;
        salary = s;
    }

    // Passing object as argument 
    static void displayEmployeeData(const Employee& emp) {
        emp.displayEmployee();
    }

    // Returning an object 
    static Employee createEmployee(string n, int i, double s) {
        return Employee(n, i, s);
    }
};

// Static member definitions
string Employee::companyName = "TechSolutions";
int Employee::employeeCount = 0;

int main() {
    cout << "Company Name: " << Employee::companyName << endl;

    // Create employee objects
    Employee emp1("sumaira", 101, 250000);
    Employee emp2 = emp1;   // Copy constructor

    cout << "Employee 1 Data:" << endl;
    emp1.displayEmployee();

    cout << "Employee 2 Data (Copied from Employee 1):" << endl;
    emp2.displayEmployee();

    // Modify employee 1 data
    emp1.modifyEmployee("abrar", 102, 10000);

    cout << "Modified Employee 1 Data:" << endl;
    emp1.displayEmployee();

    cout << "Employee 2 Data (After modifying Employee 1):" << endl;
    emp2.displayEmployee();

    // Dynamic memory allocation
    Employee* emp3 = new Employee("ahmad", 103, 750000);
    cout << "Employee 3 Data :" << endl;
    emp3->displayEmployee();
    delete emp3;

    // Passing object as function argument 
    cout << "Passing Employee Object to Function:" << endl;
    Employee::displayEmployeeData(emp1);

    // Returning an object from a function 
    Employee emp4 = Employee::createEmployee("Asma", 112, 950000);
    cout << "Employee 4 Data :" << endl;
    emp4.displayEmployee();

    Employee::displayEmployeeCount();

    return 0;
}

