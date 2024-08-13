#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


class Student{
public:
    Student(const string &name="name", const string &surname="surname", int id=0, float avg=0);
    const string getName() const;
    const string getSurname() const;
    int getId() const;
    float getAvg() const;
    void print() const;
private:
    string name;
    string surname;
    int id;
    float avg;
};

class Course{
private:
    string c_name;
    vector<Student> students;
public:
    Course();
    Course(const string &cName);
    void add_Students(const Student &s);
    const vector<Student> &getStudents() const;
    void print() const;
    void loadFromFile(string &filename);
};

Student::Student(const string &name, const string &surname, int id, float avg) :
    name(name), surname(surname), id(id),avg(avg) {
}


const string Student::getName() const {
    return name;
}

const string Student::getSurname() const {
    return surname;
}

int Student::getId() const {
    return id;
}

float Student::getAvg() const {
    return avg;
}

void Student::print() const{
    cout<<getName()<<" "<<getSurname()<<" "<<getId()<<" "<<getAvg()<<endl;
}

Course::Course() {
}

Course::Course(const string &cName) :
        c_name(cName){
}

void Course::add_Students(const Student &s) {
    students.push_back(s);
}

const vector<Student> &Course::getStudents() const {
    return students;
}

void Course::print() const {
    for(auto &s : students){
        s.print();
    }
}

void Course::loadFromFile(string &filename) {
    ifstream file(filename ,ios::in);
    if(file.is_open()){
        string line;
        string name, surname;
        int id;
        float avg;
        while(file>>name){
            file>>surname>>id>>avg;
            add_Students(Student(name,surname,id,avg));
        }
        file.close();
    }
}

int main() {


    Course c("C++");
    string file="students.txt";
    c.loadFromFile(file);
    c.print();
    

    return 0;
}
