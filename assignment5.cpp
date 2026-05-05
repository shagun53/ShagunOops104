//q1
#include <iostream>
using namespace std;

class Base {
public:
    void display() {
        cout << "Base class function\n";
    }
};

class Derived : public Base {
public:
    void show() {
        cout << "Derived class function\n";
    }
};

int main() {
    Base obj1;
    Derived obj2;
    obj1.display();
    obj2.display();
    obj2.show();
    return 0;
}
//q2
#include <iostream>
using namespace std;

class Base {
protected:
    int value;
public:
    Base() {
        value = 10;
    }
};

class Derived : public Base {
public:
    void display() {
        cout << "Value: " << value << endl;
    }
};

int main() {
    Derived obj;
    obj.display();
    return 0;
}
//q3
#include <iostream>
using namespace std;

class Base {
public:
    int x;
};

class PublicDerived : public Base { };
class ProtectedDerived : protected Base { };
class PrivateDerived : private Base { };

int main() {
    PublicDerived obj1;
    obj1.x = 5;
    cout << obj1.x << endl;
    return 0;
}
//q4
#include <iostream>
using namespace std;

class A {
public:
    void show() { cout << "Inheritance Example\n"; }
};

class B : public A { };
class C : public A { };
class D : public B { };
class E { };

class F : public A, public E { };

int main() {
    B obj1;
    C obj2;
    D obj3;
    F obj4;
    obj1.show();
    obj2.show();
    obj3.show();
    obj4.show();
    return 0;
}
//q5
#include <iostream>
using namespace std;

class Base {
public:
    Base() { cout << "Base Constructor\n"; }
    ~Base() { cout << "Base Destructor\n"; }
};

class Derived : public Base {
public:
    Derived() { cout << "Derived Constructor\n"; }
    ~Derived() { cout << "Derived Destructor\n"; }
};

int main() {
    Derived obj;
    return 0;
}
//q6
#include <iostream>
using namespace std;

class Book {
protected:
    string title;
    string author;
    double price;
public:
    Book(string t, string a, double p) {
        title = t;
        author = a;
        price = p;
    }
    void displayBook() {
        cout << title << " " << author << " " << price << endl;
    }
};

class Textbook : public Book {
    string subject;
public:
    Textbook(string t, string a, double p, string s)
        : Book(t, a, p) {
        subject = s;
    }
    void displayTextbook() {
        displayBook();
        cout << subject << endl;
    }
};

int main() {
    Textbook obj("Maths", "John", 500, "Algebra");
    obj.displayTextbook();
    return 0;
}
//q7
#include <iostream>
using namespace std;

class Speedometer {
protected:
    int speed;
public:
    Speedometer(int s) { speed = s; }
};

class FuelGauge {
protected:
    int fuel;
public:
    FuelGauge(int f) { fuel = f; }
};

class Thermometer {
protected:
    int temperature;
public:
    Thermometer(int t) { temperature = t; }
};

class CarDashboard : public Speedometer, public FuelGauge, public Thermometer {
public:
    CarDashboard(int s, int f, int t)
        : Speedometer(s), FuelGauge(f), Thermometer(t) {}
    void display() {
        cout << "Speed: " << speed << endl;
        cout << "Fuel: " << fuel << endl;
        cout << "Temperature: " << temperature << endl;
    }
};

int main() {
    CarDashboard car(80, 50, 35);
    car.display();
    return 0;
}
//q8
#include <iostream>
using namespace std;

class LibraryUser {
protected:
    string name;
    int id;
public:
    LibraryUser(string n, int i) {
        name = n;
        id = i;
    }
};

class Student : public LibraryUser {
    string grade;
public:
    Student(string n, int i, string g)
        : LibraryUser(n, i) {
        grade = g;
    }
    void display() {
        cout << name << " " << id << " " << grade << endl;
    }
};

class Teacher : public LibraryUser {
    string department;
public:
    Teacher(string n, int i, string d)
        : LibraryUser(n, i) {
        department = d;
    }
    void display() {
        cout << name << " " << id << " " << department << endl;
    }
};

int main() {
    Student s("Rahul", 1, "A");
    Teacher t("Dr.Sharma", 2, "Physics");
    s.display();
    t.display();
    return 0;
}
//q9
#include <iostream>
using namespace std;

class Vehicle {
protected:
    string make;
    string model;
    int year;
public:
    Vehicle(string mk, string md, int y) {
        make = mk;
        model = md;
        year = y;
    }
};

class Truck : public Vehicle {
protected:
    int load_capacity;
public:
    Truck(string mk, string md, int y, int lc)
        : Vehicle(mk, md, y) {
        load_capacity = lc;
    }
};

class RefrigeratedTruck : public Truck {
    int temperature_control;
public:
    RefrigeratedTruck(string mk, string md, int y, int lc, int tc)
        : Truck(mk, md, y, lc) {
        temperature_control = tc;
    }
    void display() {
        cout << make << " " << model << " " << year << " "
             << load_capacity << " " << temperature_control << endl;
    }
};

int main() {
    RefrigeratedTruck obj("Tata", "X1", 2024, 1000, -5);
    obj.display();
    return 0;
}
//q10
#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    string address;

public:
    void setPerson(string n, string a) {
        name = n;
        address = a;
    }

    void showPerson() {
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
    }
};

class Staff : virtual public Person {
protected:
    int employee_id;
    string department;

public:
    void setStaff(int id, string dept) {
        employee_id = id;
        department = dept;
    }

    void showStaff() {
        cout << "Employee ID: " << employee_id << endl;
        cout << "Department: " << department << endl;
    }
};

class Student : virtual public Person {
protected:
    int student_id;
    char grade;

public:
    void setStudent(int id, char g) {
        student_id = id;
        grade = g;
    }

    void showStudent() {
        cout << "Student ID: " << student_id << endl;
        cout << "Grade: " << grade << endl;
    }
};

class TeachingAssistant : public Staff, public Student {
public:
    void display() {
        showPerson();
        showStaff();
        showStudent();
    }
};

int main() {
    TeachingAssistant ta;

    ta.setPerson("Divjyot", "Punjab");
    ta.setStaff(101, "CSE");
    ta.setStudent(202, 'A');

    ta.display();

    return 0;
}
