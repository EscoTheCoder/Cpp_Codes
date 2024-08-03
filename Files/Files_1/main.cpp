#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    fstream file;
    file.open("test.txt", ios::out);

    if(file.is_open()){
        file << "Hello Nikolas" << endl;
        file << "How are you??" << endl;
        file.close();
    }

    vector<string> lst;

    file.open("test.txt", ios::in);
    if(file.is_open()){
        string line;
        while(getline(file,line)){
            cout<<line<<endl;
            lst.push_back(line);
        }
        for(const auto& i:lst){
            cout<<i<<" ";
        }
        file.close();
    }


    return 0;
}
