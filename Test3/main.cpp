#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    // fstream file;
    // file.open("test.txt", ios::out);

    // if(file.is_open()){
    //     file << "Hello Nikolas" << endl;
    //     file << "How are you?" << endl;
    //     file.close();
    // }

    // vector<string> lst;

    // file.open("test.txt", ios::in);
    // if(file.is_open()){
    //     string line;
    //     while(getline(file,line)){
    //         cout<<line<<endl;
    //         lst.push_back(line);
    //     }
    //     for(const auto& i:lst){
    //         cout<<i<<" ";
    //     }
    //     file.close();
    // }


    int **arr = new int* [5];

    if(!arr){
        cout<<"error allocating memory";
    }
    for(int i=0; i<5; i++){
        arr[i] = new int[3];
        if(!arr[i]){
            cout<<"Error allocating memory";
        }
    }

    for(int i=0; i<5; i++){
        for(int j=0; j<3; j++){
            arr[i][j]=i*j;
        } 
    }

    for(int i=0; i<5; i++){
        for(int j=0; j<3; j++){
            cout<<arr[i][j];
        }
        cout<<endl;
    }

    return 0;
}
