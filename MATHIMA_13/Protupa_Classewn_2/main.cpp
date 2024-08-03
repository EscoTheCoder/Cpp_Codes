#include <iostream>
#include <string>
using namespace std;


//PARADEIGMA TEMPLATE STACK

template <typename T,int STACK_SIZE>
class stack{
    public:
        stack();
        bool empty();
        bool full();
        bool push(T elem);
        bool pop(T *elem);
    private:
        T array[STACK_SIZE];
        int top;
};

template <typename T,int STACK_SIZE>
stack<T,STACK_SIZE>::stack() {
    top=-1;
}

template <typename T,int STACK_SIZE>
bool stack<T,STACK_SIZE>::empty() {
    return top==-1;
}

template <typename T,int STACK_SIZE>
bool stack<T,STACK_SIZE>::full() {
    return top==STACK_SIZE-1;
}

template <typename T,int STACK_SIZE>
bool stack<T,STACK_SIZE>::push(T elem) {
    if(full()) {
        return false;
    }
    top++;
    array[top]=elem;
    return true;
}

template <typename T,int STACK_SIZE>
bool stack<T,STACK_SIZE>::pop(T *elem) {
    if(empty()) {
        return false;
    }
    *elem=array[top];
    top--;
    return true;
}

int main() {

    //integer stack
    stack<int,100> st;
    int temp;


    st.push(2);
    st.push(5);

    st.pop(&temp);
    cout<<temp<<" ";
    st.pop(&temp);
    cout<<temp<<" ";

    cout<<endl;
    //string stack
    stack<string,100> st2;
    string temp2;

    st2.push("Hello");
    st2.push("World");

    st2.pop(&temp2);
    cout<<temp2<<" ";
    st2.pop(&temp2);
    cout<<temp2<<" ";


    return 0;
}
