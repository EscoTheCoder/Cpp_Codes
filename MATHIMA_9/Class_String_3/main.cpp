#include <iostream>
#include <string>
using namespace std;

int main() {

//    string str="xxxx";
//    cout<<str.length()<<" "<<str.size();
//
//    cout<<endl<<str.capacity(); //plithos twn bytes
//
//    str.shrink_to_fit(); //meiwnei thn xwritikothta sto pragmatiko megethos ths sumvoloseiras
//
//    str.resize(5); //thetw osos thelw to length ths sumvoloseiras

    string s1;
    string s2("Medium");
    string s3("A rather large one");

    cout<<"Capacity s1: "<<s1.capacity()<<endl;
    cout<<"Length s1: "<<s1.length()<<endl<<endl;

    cout<<"Capacity s2: "<<s2.capacity()<<endl;
    cout<<"Length s2: "<<s2.length()<<endl<<endl;

    cout<<"Capacity s3: "<<s3.capacity()<<endl;
    cout<<"Length s3: "<<s3.length()<<endl<<endl;

    s3+=(s1+s2);

    cout<<"Capacity s3: "<<s3.capacity()<<endl;
    cout<<"Length s3: "<<s3.length()<<endl<<endl;

    s3.resize(10);

    cout<<"Capacity s3: "<<s3.capacity()<<endl;
    cout<<"Length s3: "<<s3.length()<<endl<<endl;

    s3.shrink_to_fit();

    cout<<"Capacity s3: "<<s3.capacity()<<endl;
    cout<<"Length s3: "<<s3.length()<<endl;


    return 0;
}
