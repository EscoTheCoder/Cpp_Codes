#include <iostream>
#include <cstring>
using namespace std;

class STRING{
private:
    int length;
    char *str;	
public:
    STRING(){
        length=0;
        str=new char [1];
        str[0]='\0';
    }
    STRING(int length){
        this->length=0;
        str = NULL;
    }
    STRING(char *in_str){

        length= strlen(in_str);

        str = new char [length+1]; // vazoume [length+1] gia to '\0'
        if(!str){
            cout<<"Error allocating memory!";
        }
        strcpy(str,in_str);
    }
    STRING(const STRING &obj){

        length=obj.get_length();

        str=new char [length+1]; // vazoume [length+1] gia to '\0'
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
        str = new char [length+1]; // vazoume [length+1] gia to '\0'
        if(!str){
            cout<<"Error allocating memory";
        }
        strcpy(str,right.str);
        return *this;
    }

    char &operator[] (int i) const{
        if(i>=0 && i<length){
            return str[i];
        }
        else{
            cout<<"Index out of bounds";
        }
    }

    bool operator< (STRING &right){
        if(strcmp(str,right.str)<0){ //strcmp(a,b)<0 ean a<b paei kai alfavitika gia strings
            return true;
        }
        return false;
    }

    bool operator> (STRING &right){
        if(strcmp(str,right.str)>0){ //strcmp(a,b)>0 ean a>b paei kai alfavitika gia strings
            return true;
        }
        return false;
    }

    bool operator== (STRING &right){
        if(strcmp(str,right.str)==0){ //strcmp(a,b)=0 ean a=b paei kai alfavitika gia strings
            return true;
        }
        return false;
    }
};


int main() {

    char s[80]="This is a String";
    STRING s1(s);
    STRING s2;

    s2=s1;
    //s2[1]='a';

    s1.print();
    cout<<endl;
    s2.print();

    if(s1==s2){
        cout<<endl<<"True";
    }
    else{
        cout<<endl<<"false";
    }

    return 0;
}