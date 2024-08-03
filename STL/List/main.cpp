#include <iostream>
#include <list>
#include <vector>
#include <set>
using namespace std;

void displayRaitings(const list<int> &playerRatings){
    for(list<int>::const_iterator it=playerRatings.begin(); it!=playerRatings.end(); it++){ //const ITERATOR
        cout<<"Player Rating: "<<*it<<endl;
    }
}

void insertPlayerIntoOrederedList(int newPlayerRating, list<int> &playerRatings){
    for(list<int>::const_iterator it=playerRatings.begin(); it!=playerRatings.end(); it++){//const ITERATOR
        if(*it>newPlayerRating){
            playerRatings.insert(it,newPlayerRating);
            return;
        }
    }
    playerRatings.push_back(newPlayerRating);

}

int main() {

    list<int> allPlayers = {2,9,6,7,3,1,4,8,3,2,9};
    list<int> beginners; //rating 1-5
    list<int> pros; //rating 6/10


    for(list<int>::iterator it=allPlayers.begin(); it!=allPlayers.end(); it++){
        int rating=*it;
        if(rating>=1 && rating<=5){
            insertPlayerIntoOrederedList(rating,beginners);
        }
        else{
            insertPlayerIntoOrederedList(rating,pros);
        }
    }
    cout<<"Beginners:"<<endl;
    displayRaitings(beginners);
    cout<<endl<<"Pros:"<<endl;
    displayRaitings(pros);

    return 0;
}
