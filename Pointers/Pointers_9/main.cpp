#include <iostream>
using namespace std;


int main() {

    unsigned howMany;
    cin >> howMany;
    int* storage = new int[howMany];

    for(unsigned i = 0; i < howMany; i++) {
        cin >> storage[i];
    }
    for(unsigned i = 0; i < howMany; i++) {
        cout << i << ": " << storage[i] << endl;
    }
    delete[] storage;
}
