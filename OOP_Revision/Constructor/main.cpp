#include<iostream>
#include<string>
using namespace std;

class Student
{
    int id;
    int age;
    string name;
    string department;
    string city;
    
    public:
    // Compiler provides us with default non parametrized and copy constructor if we don't provide any constructor in our class.
    // If we declare any constructor in our class, then compiler will not provide us with default non parametrized and copy constructor.
    // default copy constructor makes a shallow copy of the object, which means it copies the values of the member variables from one object to another.
    int *rating;

    Student() // Non parametrized constructor
    {
        this->id = 0;
        this->age = 0;
        this->name = "demo_student";
        this->department = "demo_department";
        this->city = "demo_city";
        this->rating = new int(0);
    }

    Student(int id, int age, string name, string department, string city, int rating_value) // Parametrized constructor
    {
        this->id = id;
        this->age = age;
        this->name = name;
        this->department = department;
        this->city = city;
        this->rating = new int(rating_value);
    }

    Student(const Student & original_student) // Copy constructor
    {
        this->id = original_student.id;
        this->age = original_student.age;
        this->name = original_student.name;
        this->department = original_student.department;
        this->city = original_student.city;
        this->rating = new int(*(original_student.rating)); // Deep copy of the rating pointer
    }

    // Compiler provides us with default destructor if we don't provide any destructor in our class.
    // Default destructor does not free the dynamically allocated memory, which can lead to memory leaks.
    ~Student() // Destructor
    {
        delete rating; // Free the dynamically allocated memory for rating
    }

    // Constuructor and Destructor are special member functions that are automatically called when an object is created and destroyed(goes out of scope), respectively. They are used to initialize and clean up resources associated with an object.
};

int main()
{
    Student student1; // Non parametrized constructor will be called
    Student student2(1, 22, "Zuhair Hasan Raza", "Computer Science", "Cambridge", 5); // Parametrized constructor will be called
    Student student3(student2); // Copy constructor will be called

    *(student3.rating) = 3;
    cout << "Student 2 rating: " << *(student2.rating) << endl;

    return 0;
}