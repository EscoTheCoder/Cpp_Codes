#include <iostream>
#include <string>
#define STACK_SIZE 100
using namespace std;


//PARADEIGMA TEMPLATE STACK

template <typename T>
class stack{
    public:
        static int ob_cnt;
        stack();
        bool empty();
        bool full();
        bool push(T elem);
        bool pop(T *elem);
    private:
        T array[STACK_SIZE];
        int top;
};


template <typename T>
int stack<T>::ob_cnt=0;

template <typename T>
stack<T>::stack() {
    top=-1;
    ob_cnt++;
}

template <typename T>
bool stack<T>::empty() {
    return top==-1;
}

template <typename T>
bool stack<T>::full() {
    return top==STACK_SIZE-1;
}

template <typename T>
bool stack<T>::push(T elem) {
    if(full()) {
        return false;
    }
    top++;
    array[top]=elem;
    return true;
}

template <typename T>
bool stack<T>::pop(T *elem) {
    if(empty()) {
        return false;
    }
    *elem=array[top];
    top--;
    return true;
}

int main() {

    stack<int> st;
    stack<int> st2;
    stack<string> st3;


    cout<<stack<int>::ob_cnt<<endl;
    cout<<stack<string>::ob_cnt<<endl;

    return 0;
}
