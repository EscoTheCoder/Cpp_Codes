#include <iostream>
#include <string>
#include <ctime>
using namespace std;
#define N 5

int main() {

    srand(time(0));

    string words[N]={"chair","table","phone","chips","chocolate"};
    string bad_guesses;
    string right_guesses;
    int MAX;

    string random_word = words[rand()%5];

    string game(random_word.length(),'-');

    cout<<"Plithos lathos apanthsewn:";
    cin>>MAX;
    int wrong_guesses=0;

    while(true){
        cout<<game<<endl;
        char letter;
        cout<<endl<<"Dwse gramma:";
        cin>>letter;
        if(right_guesses.find(letter)!=right_guesses.npos){
            cout<<"Exeis epeilejei to sugekrimeno gramma ( "<<letter<<" )"<<endl;
            continue;
        }
        else if(bad_guesses.find(letter)!=bad_guesses.npos){
            cout<<"Exeis epeilejei to sugekrimeno gramma ( "<<letter<<" )"<<endl;
            continue;
        }

        if(random_word.find(letter)!=random_word.npos){
            int pos;
            cout<<"SWSTH EPILOGH"<<endl;
            right_guesses+=letter;

            pos=random_word.find(letter);

            while(pos<random_word.npos){
                game[pos]=letter;
                pos=random_word.find(letter,pos+1); // na elegjei an uparxei jana to idio gramma
            }

            if(game.find('-')==game.npos){
                cout<<"VRHKES THN LEJH NHKHSES SUGXARHTHRIA!!!!!!"<<endl;
                cout<<"H LEJH HTAN= "<<game;
                exit(0);
            }
        }
        else{
            cout<<"TO GRAMMA DEN UPARXEI"<<endl;
            bad_guesses.push_back(letter);
            wrong_guesses++;
            cout<<"Apomenoun "<<MAX-wrong_guesses<<" Prospatheies"<<endl;

            if(wrong_guesses==MAX){
                cout<<"JEPERASES TO ORIO DUNATWN PROSPATHEIWN"<<endl;
                cout<<"H LEJH HTAN= "<<random_word;
                exit(0);
            }
        }
    }



    return 0;
}
