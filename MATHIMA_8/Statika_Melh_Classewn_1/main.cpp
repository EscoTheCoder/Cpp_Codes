#include <iostream>
#include <cstdlib>
using namespace std;
#define N 5

class orc{
public:
    static int allive_orcs;
    orc();
    ~orc();
private:
    int h;
};

int orc::allive_orcs=0;

orc::orc() {
    allive_orcs++;
}

orc::~orc() {
    allive_orcs--;
}

int main(){
    srand(time(0));

    orc *arr[N]; //pinakas deiktwn
    int pos;

    for(int i=0; i<N; i++){
        arr[i]=NULL;
    }

    for(int i=0; i<100; i++){
        pos=rand()%N; //dialegei arithmo apo to 0-4

        if(arr[pos]==NULL){
            arr[pos]=new orc; //kaleite o constructor
            if(!arr[pos]) {
                exit(0);
            }
        }
        else{
            delete arr[pos];
            arr[pos]=NULL;
        }

        if(i%10==0){ // ana 10 vhmata na mas kanei mia ektupwsh 10-20-30-40-...100
            cout<<"Step "<<i<<": Alive orcs= "<<orc::allive_orcs<<endl;
        }
    }
    return 0;
}


