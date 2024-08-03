#include <iostream>
#define N 5
using namespace std;


int linear_search(int *pinakas,int n, int number){
    for(int i=0; i<n; i++){
        if(pinakas[i]==number){
            return i;
        }
    }
    return -1;


}

int main() {

    int pinakas[N]={1,6,2,7,9,};
    int number;
    cout<<"Dwse arithmo gia anzhthsh:";
    cin>>number;
    int k= linear_search(pinakas,N,number);
    if(k==-1){
        cout<<"o arithmos den vrethike"<<endl;
    }
    else{
        cout<<"o` arithmos "<<pinakas[k]<<" vrisketai sthn thesh "<<k<<endl;
    }

    return 0;
}
