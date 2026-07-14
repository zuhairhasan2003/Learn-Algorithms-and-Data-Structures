#include<iostream>
#include<string>
using namespace std;

class Teacher
{
    private:
    int id;
    string name;
    double salary;
    string department;

    public:
    Teacher(int id, string name, double salary, string department)
    {
        this->id = id;
        this->name = name;
        this->salary = salary;
        this->department = department;
    }

    void PrintInfo()
    {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
        cout << "Department: " << department << endl;
    }
};

int main()
{
    Teacher teacher1(1, "Zuhair", 100000, "CS");

    teacher1.PrintInfo();

    return 0;
}