#include <iostream>
#include <string>
#define WAIT cin.get();
#define print(x) cout<<x<<endl;
#define FOR(N,M) for(int N=0; N<M; N++)


using namespace std;

int main() {

    string name="Nikolas";
    print(name);

    int array[5];
    int i=0,k=5;

    FOR(i,k){
        array[i]=i;
    }

    FOR(i,k) {
        cout << array[i]<<" ";
    }

    //cin.get();
    WAIT

    return 0;
}
