#include <iostream>
#include <stack>
using namespace std;

void print_Stack(stack<int> st){
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}

int main() {

    stack<int> st;

    if(st.empty())
        cout<<"The stack is empty"<<endl;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    cout<<"Stoixeio sthn korufh tis stoivas= "<<st.top()<<endl;

    print_Stack(st);

    st.pop();

    print_Stack(st);



    return 0;
}
