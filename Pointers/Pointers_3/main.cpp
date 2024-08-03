#include <iostream>
using namespace std;

int main() {

//    int numbers[]={2,4,3,7,5};
//    cout<<&numbers[0]<<endl;
//    cout<<numbers<<endl;
//    cout<<numbers[2]<<" "<<*(numbers+2);

    int numbers[5];

    for(int i=0; i<5; i++) {
        cout << "Number:";
        cin >> numbers[i];
    }

    for(int i=0; i<5; i++)
        cout <<*(numbers+i)<<" ";

    return 0;
}
