#include <iostream>
#include <queue>
using namespace std;

void print_Stack(queue<int> st){
    while(!st.empty()){
        cout<<st.front()<<" ";
        st.pop();
    }
    cout<<endl;
}

int main() {

    queue<int> q;

    if(q.empty()) {
        cout << "The stack is empty" << endl;
    }
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout<<"First Element= "<<q.front()<<endl;
    cout<<"Last Element= "<<q.back()<<endl;

    print_Stack(q);

    q.pop();

    print_Stack(q);



    return 0;
}
