#include <iostream>
#include <string>
using namespace std;

int main() {

    string s("Initial string");
    cout<<s<<endl;

    cout<<"Give a new string:";
    getline(cin,s);
    cout<<s;

    //getline(cin,name,'#'); //diavazei mexri na vrei #

    return 0;
}
