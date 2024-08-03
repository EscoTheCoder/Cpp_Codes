#include <iostream>
#include <string>
using namespace std;

class movie{
public:
    movie();
    movie(string name, double score, int weeks);
    virtual double score();
protected:
    string name;
    double score_imdb; //imdb site tainiwn
    int weeks;
};

class thriller : virtual public movie{
public:
    thriller(double fear_factor);
    thriller(string name, double score, int weeks, double fear_factor);
    virtual double score();

protected:
    double fear_factor; //(0-10)
};

class comedy : virtual public movie{
public:
    comedy(double fun_factor);
    comedy(string name, double score, int weeks, double fun_factor);
    virtual double score();
protected:
    double fun_factor; //(0-10)
};

class comedy_thriller : public comedy, public thriller{
public:
    comedy_thriller(string name, double score_imdb, int weeks, double fun_factor, double fear_factor);
    virtual double score();
};


movie::movie(){
}

movie::movie(string name, double score_imdb, int weeks) :
        name(name), score_imdb(score_imdb), weeks(weeks) {
}

double movie::score() {
    return score_imdb/(0.5 * weeks);
}

thriller::thriller(double fear_factor){
    this->fear_factor=fear_factor;
}

thriller::thriller(string name, double score, int weeks, double fear_factor) :
    movie(name, score, weeks){
    this->fear_factor=fear_factor;
}

double thriller::score() {
    return fear_factor * movie::score();
}

comedy::comedy(double fun_factor){
    this->fun_factor=fun_factor;
}

comedy::comedy(string name, double score, int weeks, double fun_factor) :
    movie(name, score, weeks){
    this->fun_factor=fun_factor;
}


double comedy::score() {
    return fun_factor * movie::score();
}


comedy_thriller::comedy_thriller(string name, double score_imdb, int weeks, double fun_factor, double fear_factor) :
    movie(name,score_imdb,weeks),
    comedy(fun_factor),
    thriller(fear_factor) {
}

double comedy_thriller::score() {
    return ((fun_factor+fear_factor)/2) * movie::score();
}

int main() {

    thriller thriller1("IT",6.8,10,8.0);
    thriller thriller2("US",6.9,30,7.0);
    thriller thriller3("Silence of the Lambs",8.6,1540,9.0);
    comedy comedy1("Jexi",6.6,4,3.0);
    comedy_thriller comedy_thriller1("Addams Family", 5.9, 5, 4.0, 3.0);
    comedy_thriller comedy_thriller2("Shaun of the Dead",7.9,825,9.0,4.0);

    cout<<thriller1.score()<<endl;
    cout<<thriller2.score()<<endl;
    cout<<thriller3.score()<<endl;
    cout<<comedy1.score()<<endl;
    cout << comedy_thriller1.score()<<endl;
    cout << comedy_thriller2.score()<<endl;


    return 0;
}
