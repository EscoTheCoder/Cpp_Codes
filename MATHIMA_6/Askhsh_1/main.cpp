#include <iostream>
#include <cstring>
using namespace std;

class STRING{
private:
    int length;
    char *str;
public:
    STRING(){

    }
    STRING(int length){
        this->length=0;
        str = NULL;
    }
    STRING(char *in_str){
        length= strlen(in_str);
        str = new char [length];
        if(!str){
            cout<<"Error allocating memory!";
        }
        strcpy(str,in_str);
    }
    STRING(const STRING &obj){
        length=obj.get_length();
        str=new char [length];
        if(!str){
            cout<<"Error allocating memory!";
        }
        strcpy(str,obj.get_str());
    }
    ~STRING(){
        delete [] str;
    }
    int get_length() const {
        return length;
    }
    char *get_str() const{
        return str;
    }
    void print(){
        cout<<str;
    }
    void set_str(char *in_str){
        if(str!=NULL){
            delete [] str;
        }

        length= strlen(in_str);

        str=new char [length];
        if(!str){
            cout<<"Error allocating memory!";
        }
        strcpy(str,in_str);
    }

    STRING &operator= (STRING &right){
        if(this==&right){
            return *this;
        }
        length=right.length;
        delete [] str;
        str = new char [length];
        if(!str){
            cout<<"Error allocating memory";
        }
        strcpy(str,right.str);
        return *this;
    }
};


int main() {

    char s[80]="This is a String";
    STRING s1(s);
    STRING s2;

    s2=s1;

    s1.print();
    cout<<endl;
    s2.print();

    return 0;
}