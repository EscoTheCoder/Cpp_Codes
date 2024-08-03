#include <iostream>
#include <string>
#include <sstream> // For std::istringstream

using namespace std;

int main() {
    string input;  // Temporary string to hold input
    int moms_age;
    int sons_age;

    // Read moms_age
    cout << "Enter mom's age:";
    getline(cin, input);          // Read input as string
    istringstream(input) >> moms_age; // Convert string to integer

    // Read sons_age
    cout << "Enter son's age:";
    getline(cin, input);          // Read input as string
    istringstream(input) >> sons_age; // Convert string to integer

    // Output the ages to confirm correct input
    cout << "Mom's age: " << moms_age << endl;
    cout << "Son's age: " << sons_age << endl;

    try{
        if(sons_age>moms_age)
            throw 15;
    }
//    catch(int exception){
//        if(exception==15)
//            cerr<<"Sons Age can not be Higher than Moms Age"<<endl;
//    }
    //allos tropos gia na grapsoume catch block xwris orisma me (...) gia oles tis periptwseis EXCEPTION
    catch(...){
        cerr<<"Sons Age can not be Higher than Moms Age"<<endl;
    }


    return 0;
}
