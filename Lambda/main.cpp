#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int singleNumber(vector<int>& nums) {
    unordered_map<int,int> map;

    for(auto &i : nums){
        map[i]++;
    }

    for(auto &i : map){
        if(i.second==1){
            return i.first;
        }
    }
    return -1;
}

void print(vector<string>& s){
    for(int i=0; i<s.size(); i++){
        cout<<s[i]<<" ";
    }
    cout<<endl;
}

void reverseString(vector<string>& s) {
    vector<string> copy;
    for(int i=s.size()-1; i>=0; i--){
        copy.push_back(s[i]);
    }
    print(copy);
}

int main(){

    string s="Nikolas";

    string s_copy;

    for(int i=s.size()-1; i>=0; i--){
        s_copy.push_back(s[i]);
    }
    cout<<s_copy;

    return 0;
}