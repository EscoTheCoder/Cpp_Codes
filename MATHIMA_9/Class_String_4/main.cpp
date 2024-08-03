#include <iostream>
#include <string>
using namespace std;

int main() {

    //string str="Nikolas";

    //str.append(" P");

    //str.insert(0,"@");

    //str.push_back('!'); //prosthetei sto telos ton xarathra tou orismatos

    //str.clear();

    //str.erase(0,3); //diagrafh apo to 0 ws prin to 3
    //str.erase(0,3); //diagrafh apo to 0 ws to telos

    //str.pop_back(); //diagrafei ton teleutaio xarakthra

    //str.replace(0,3,"...");

    //cout<<str.substr(0,3)<<endl;

    //cout<<str;


    string s("0123456789");

    cout<<"Initial: "<<s<<endl;

    s.append("abcd");
    s.push_back('.');
    s.insert(3,"ABC");

    cout<<"Insertions: "<<s<<endl;

    s.pop_back();
    s.erase(3,3);

    cout<<"Deletions: "<<s<<endl;

    s.replace(2,4,string("ABCD"),0,4);

    cout<<"Replace: "<<s<<endl;

    s.clear();

    cout<<"Cleared: "<<s<<endl;

    return 0;
}
