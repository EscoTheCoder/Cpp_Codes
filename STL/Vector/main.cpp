#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector<int> numbers;

    for(int i=1; i<=10; i++){
        numbers.push_back(i);
    }

    numbers.insert(numbers.begin()+5,88);
    numbers.erase(numbers.begin()+5);
    numbers.pop_back();
    numbers.

    for(auto i:numbers)
        cout<<i<<" ";

//    for(auto it=numbers.begin(); it!=numbers.end(); it++){
//        cout<<*it<<endl; //value of the element
//        //cout<<&it<<endl; //address of the iterator
//        //cout<<&(*it)<<endl<<endl; //address of the element
//    }
//
//    for(auto it=numbers.cbegin(); it!=numbers.cend(); it++){ //constant begin - end ->(cbegin,cend)
//        //*it=20;//den allazei gt einai constant to begin,end
//    }

    //KAPOIES SUMANTIKES SUNARTHSEIS TWN VECTORS
//    cout<<numbers.size()<<endl;
//    cout<<numbers.max_size()<<endl;
//    cout<<numbers.capacity()<<endl;
//    numbers.resize(5);
//    cout<<numbers.size()<<endl;
//    if(numbers.empty())
//        cout<<"Is empty"<<endl;
//    else
//        cout<<"Is not empty"<<endl;
//    cout<<numbers[0]<<endl;
//    cout<<numbers.at(0)<<endl;
//    cout<<numbers.front()<<endl;
//    cout<<numbers.back()<<endl;
//    numbers.clear();
//    cout<<numbers.size()<<endl;


    return 0;
}
