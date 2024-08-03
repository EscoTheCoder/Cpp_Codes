#include <iostream>
using namespace std;

class Student{
public:
    string name;
    int age;
    double gpa;

    Student(string name, int age, double gpa){
        this->name=name;
        this->age=age;
        this->gpa=gpa;
    }
    ~Student(){
        cout<<"I will be waiting...!";
    }

};


int main() {

    Student student1("Nikolas",18,3.2);
    cout<<student1.name<<endl<<student1.age<<endl<<student1.gpa;
    cout<<endl<<endl;


    Student student2("Kostas",20,1.5);
    cout<<student2.name<<endl<<student2.age<<endl<<student2.gpa;
    cout<<endl<<endl;


    Student student3("Mike",23,0.5);
    cout<<student3.name<<endl<<student3.age<<endl<<student3.gpa;
    cout<<endl<<endl;



    return 0;
}
