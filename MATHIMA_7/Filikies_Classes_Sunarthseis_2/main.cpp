#include <iostream>
using namespace std;

class node{
public:
    friend class linked_list;
private:
    int data;
    node *next;
};

class linked_list{
public:
    linked_list();
    ~linked_list();
    bool insert_start(int in_data);
    void print();
private:
    node *head;
};

linked_list::linked_list() {
    head=NULL;
}

linked_list::~linked_list(){
}


bool linked_list::insert_start(int in_data) {
    node *newnode;
    newnode = new node;
    if(!newnode){
        cout<<"Error allocating memory";
        return false;
    }
    newnode->data=in_data;

    newnode->next=head;
    head=newnode;
    return true;
}

void linked_list::print() {
    node *current;

    current=head;
    while(current->next!=NULL){
        cout<<current->data<<" ";
        current=current->next;
    }
    cout<<current->data;
}

int main() {

    linked_list l;
    l.insert_start(1);
    l.insert_start(3);
    l.insert_start(2);
    l.insert_start(4);
    l.print();
    


    return 0;
}
