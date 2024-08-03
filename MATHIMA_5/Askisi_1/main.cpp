#include <iostream>
using namespace std;
#define N 3


//paixnidi tic tac toe
class tictactoe{
public:
    tictactoe();
    void next_player(){
        if(player=='X'){
            player='O';
        }
        else{
            player='X';
        }
    }
    char get_player() const{
        return player;
    }

    bool play(int x,int y){
        if(array[x][y]=='-'){
            array[x][y]=player;
            return true;
        }
        else{
            return false;
        }
    }
    char check_winner(){
        //elegxos grammwn
        for(int i=0; i<N; i++){
            if(array[i][0]==array[i][1] && array[i][1]==array[i][2]){
                return array[i][0];
            }
        }
        //elegxos stoiles
        for(int j=0; j<N; j++){
            if(array[0][j]==array[1][j] && array[1][j]==array[2][j]){
                return array[0][j];
            }
        }
        //elegxos diagwnioi
        if(array[0][0]==array[1][1] && array[1][1]==array[2][2]){
            return array[0][0];
        }
        if(array[0][2]==array[1][1] && array[1][1]==array[2][0]){
            return array[0][2];
        }
        return '-';
    }
    void print(){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cout<<array[i][j];
            }
            cout<<endl;
        }
    }
private:
    char array[N][N];
    char player;

};



int main() {

    tictactoe t;
    int x,y,step=0;

    while(true) {
        cout<<"PLASIO:"<<endl;
        t.print();
        cout<<"paizei o: "<<t.get_player()<<endl;

        cout<<endl<<"DWSE X SINTETAGMENH:";
        cin>>x;

        cout<<"DWSE Y SINTETAGMENH:";
        cin>>y;

        if(!t.play(x,y)){
            cout<<"Lathos Kinish";
            continue;
        }
        else{
            step++;
        }

        char winner=t.check_winner();
        if(winner!='-'){
            cout<<endl;
            t.print();
            cout<<endl;
            cout<<"O nikhths einai o \""<<winner<<"\"";
            break;
        }
        else if(step==9){
            cout<<"Isopalia";
        }

        t.next_player();
    }

    return 0;
}
