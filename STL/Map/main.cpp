#include <iostream>
#include <string>
#include <map>
#include <list>
#include <unordered_map>
using namespace std;

int main() {

//    map<string,int> myDictionary;
//
//    myDictionary.insert(pair<string,int>("Nikolas",18));
//    myDictionary.insert(pair<string,int>("Akhs",20));
//    myDictionary.insert(pair<string,int>("Babis",20));
//    myDictionary.insert(pair<string,int>("Kostas",18));
//
//    for(auto pair:myDictionary) //pair = zeugos
//        cout<<pair.first<<" - "<<pair.second<<endl;
//
//
//    cout<<endl;
//    unordered_map<string,int> myUnorderedDictionary;
//
//    myUnorderedDictionary.insert(pair<string,int>("Nikolas",18));
//    myUnorderedDictionary.insert(pair<string,int>("Akhs",20));
//    myUnorderedDictionary.insert(pair<string,int>("Babis",20));
//    myUnorderedDictionary.insert(pair<string,int>("Kostas",18));
//
//
//    myUnorderedDictionary["Nikolas"]=19;
//    myUnorderedDictionary.erase("Nikolas");
//    cout<<"Size="<<myUnorderedDictionary.size()<<endl;
//
//    for(auto pair:myUnorderedDictionary)
//        cout<<pair.first<<" - "<<pair.second<<endl;
//
//    myDictionary.clear();
//    myUnorderedDictionary.clear();



    map<string,list<string>> pokemon;
    list<string> pikachuAttacks = {"mpounia","klotsia","sfaliara"};
    list<string> gaussAttacks = {"fapa","nixia","mpoufla"};
    list<string> bernoulichuAttacks = {"xlepa","maxairia","pistolia"};

    pokemon.insert(pair<string,list<string>>("pikachu",pikachuAttacks));
    pokemon.insert(pair<string,list<string>>("gauss",gaussAttacks));
    pokemon.insert(pair<string,list<string>>("bernouli",bernoulichuAttacks));

    for(auto pair : pokemon){
        cout<<pair.first<<": ";
        for(auto attack : pair.second){
            cout << attack<<" ";
        }
        cout<<endl;
    }

    return 0;
}
