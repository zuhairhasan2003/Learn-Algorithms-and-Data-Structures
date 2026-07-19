#include<iostream>
#include<string>
using namespace std;

/*
 BASE MEMBER ACCESS | Inherited via public | Inherited via protected | Inherited via private
 -------------------|----------------------|-------------------------|----------
  public            |  public              |  protected              |  private  
  protected         |  protected           |  protected              |  private  
  private           | ❌ Inaccessible      | ❌ Inaccessible         | ❌ Inaccessible
*/ 

class Person{

    protected:
    int age;
    string name;

    public:
    Person(int age, string name){
        this->age = age;
        this->name = name;
    }
};

class Student : public Person{
    
    double marks;
    int student_id;
    string dept;

    public:
    // Whenever a object is created of child class, parents constructor is called first.
    Student(string name, int age, int student_id, string dept) : Person(age, name)
    {
        this->student_id = student_id;
        this-> dept = dept;
        this->marks = 0;
    }

    void PrintStudentInfo()
    {
        cout << "name : " << name << endl;
        cout << "age : " << age << endl;
        cout << "id : " << student_id << endl;
        cout << "department : " << dept << endl;
        cout << "marks : " << marks << endl;
    }
};

int main()
{
    Student s1("Zuhair", 22, 101, "CS");
    s1.PrintStudentInfo();
    return 0;
}