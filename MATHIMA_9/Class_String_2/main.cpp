#include <iostream>
#include <string>
using namespace std;

int main() {

//    string str1="xx" , str2="yy";
//    cout<<str1+str2<<endl;
//
//    str1=str2;
//
//    cout<<str1<<" "<<str2;
//
//    cout<<endl<<"Dwse nea timh gia str1:";
//    getline(cin,str1);
//
//    cout<<str1<<endl;
//    str1+=str2;
//    str1+="kappa";
//
//    cout<<endl<<str1;

    string s1("abcd");
    string s2;

    s2=s1+s1+s1;
    cout<<s2<<endl;

    s2[3]='D';

    cout<<s2<<endl;
    cout<<s1<<endl;

    //ta kefalaia einai prin ta mikra
    if(s1>s2)
        cout<<s1;
    else
        cout<<s2;

    return 0;
}
