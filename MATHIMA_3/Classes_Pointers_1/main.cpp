#include <iostream>
using namespace std;

class dummy{
public:
    int x;
    int y;
    double k;
};

int main() {

    dummy obj;
    obj.x=3; obj.y=5; obj.k=10;
    cout<<sizeof obj<<endl;
    return 0;
}
