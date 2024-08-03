class Person{
private:
    string name;
    int age;
public:
    Person(string name, int age) :
        name(name), age(age) {
    }
    void display(){
        cout<<"I am "<<name<<" and i am "<<age<<" years old."<<endl;
    }
};