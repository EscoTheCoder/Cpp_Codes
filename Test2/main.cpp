#include <iostream>
using namespace std;

class Movie{
public:
    Movie();
    Movie(const string &name, double scoreImdb, int premiera);
    virtual double score();
protected:
    string name;
    double score_imdb;
    int premiera; //prin poses evdomades ekane prepeiera
};

class Thriller : virtual public Movie{
public:
    Thriller(const string &name, double scoreImdb, int premiera,int fearFactor);
    Thriller(int fearFactor);
    double score() override;
protected:
    int fear_factor; //(0-10)
};

class Comedy : virtual public Movie{
public:
    Comedy(const string &name, double scoreImdb, int premiera,int funFactor);
    Comedy(int funFactor);
    double score() override;
protected:
    int fun_factor; //(0-10)

};

class Comedy_Thriller : public Thriller,Comedy{
public:
    Comedy_Thriller(const string &name, double scoreImdb, int premiera, int fearFactor, int funFactor);
    double score() override;
};



Movie::Movie() {
}

Movie::Movie(const string &name, double scoreImdb, int premiera) :
        name(name), score_imdb(scoreImdb),premiera(premiera) {
}

double Movie::score() {
    return score_imdb/(0.5*premiera);
}

Thriller::Thriller(const std::string &name, double scoreImdb, int premiera, int fearFactor) :
        Movie(name,scoreImdb,premiera),fear_factor(fearFactor){
}

Thriller::Thriller(int fearFactor) :
        Movie(name, score_imdb,premiera),fear_factor(fearFactor) {
}

double Thriller::score() {
    return fear_factor * Movie::score();
}

Comedy::Comedy(const std::string &name, double scoreImdb, int premiera, int funFactor) :
        Movie(name,scoreImdb,premiera),fun_factor(funFactor){
}

Comedy::Comedy(int funFactor) :
        Movie(name, score_imdb, premiera),fun_factor(funFactor) {
}

double Comedy::score() {
    return fun_factor * Movie::score();
}

Comedy_Thriller::Comedy_Thriller(const string &name, double score_imdb, int premiera, int fearFactor, int funFactor) :
        Movie(name, score_imdb, premiera),Thriller(fearFactor),Comedy(funFactor) {
}

double Comedy_Thriller::score() {
    return ((fun_factor+fear_factor)/2)*Movie::score();
}


int main(){

    Thriller thriller1("IT",6.8,10,8);
    Thriller thriller2("US",6.9,30,7);
    Thriller thriller3("Silence Of The Lambs",8.6,1540,9);
    Comedy comedy1("E of Lamps",8.6,1540,9);
    Comedy_Thriller comedy_thriller1("IT",6.8,10,8,8);

    cout<<thriller1.score()<<endl;
    cout<<thriller2.score()<<endl;
    cout<<thriller3.score()<<endl;
    cout<<comedy1.score()<<endl;
    cout<<comedy_thriller1.score()<<endl;


    return 0;
}