#include <iostream>
#include <vector>
#include <string>
using namespace std;


void bubbleSort(vector<int> &v){
    int N = v.size();
    for(int i=0; i<N-1; i++){
        for(int j=N-1; j>i; j--) {
            if(v[j]<v[j-1]){
                int temp=v[j];
                v[j]=v[j-1];
                v[j-1]=temp;
                cout << "Ti kaneis re mlka";
            }
        }
    }
}



void swap2(int *x, int *y){
    int k=*x;
    *x=*y;
    *y=k;
}

void printVector(vector<int> &lista){
    for(int i=0; i<lista.size(); i++){
        cout<<lista[i]<<" ";
    }
}

int main() {
//    int x,y;
//    cout<<"Dwse x , y:";
//    cin>>x>>y;
//    cout<<x<<" "<<y<<endl;
//    swap2(&x,&y);
//    cout<<x<<" "<<y;

    vector<int> lista={1,2,3,4};

    printVector(lista);
    lista.erase(lista.begin());

    cout<<endl;
    printVector(lista);

    for(int i=0; i<lista.size(); i++){
        cout<<"Ti kaneis re mlka";
    }
    
    int x=5;
    int *ptr=&x;
    cout<<x<<" "<<*ptr;




    return 0;
}
