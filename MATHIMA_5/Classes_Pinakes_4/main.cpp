#include <iostream>
using namespace std;

//class diamerisma
class flat{
public:
    flat(){
        people=0;
        cout<<"Constructing flat..."<<endl;
    }
    ~flat(){
        cout<<"Destructing flat..."<<endl;
    }
    void set_people(int in_people){
        people=in_people;
    }
    int get_people() const{
        return people;
    }
private:
    int people;
};

//class orofos pou periexei 2 diamerismata
class storey{
public:
    storey(){
        cout<<"Constructing storey..."<<endl;
    }
    ~storey(){
        cout<<"Destructing storey..."<<endl;
    }
    void set_people(int in_flat, int in_people){
        flats[in_flat].set_people(in_people);
    }
    int get_people() const{
        return flats[0].get_people() + flats[1].get_people();
    }
private:
    flat flats[2];
};

//class polukatoikia pou periexei 2 orofous
class building{
public:
    building(){
        cout<<"Constructing building..."<<endl;
    }
    ~building(){
        cout<<"Destructing building..."<<endl;
    }
    void set_people(int in_storey, int in_flat,int in_people){
        storeys[in_storey].set_people(in_flat,in_people);
    }
    int get_people() const{
        return storeys[0].get_people() + storeys[1].get_people();;
    }
    storey storeys[2];
};




int main() {

    building b;
    b.set_people(0,0,3);
    b.set_people(0,1,2);
    b.set_people(1,0,2);
    b.set_people(1,1,1);

    cout<<endl;
    cout<<"People in building: "<<b.get_people();
    cout<<endl<<endl;

    return 0;
}
