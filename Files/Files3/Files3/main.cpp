#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main() {

	fstream file("test.txt");

    if (file.is_open()) {
        file << "Hello Nikolas" << endl;
        file << "How are you???" << endl;
        file.close();
    }
    else {
        cerr<< "Could not write data" << endl;
    }

    vector<string> lst;

    file.open("test.txt", ios::in);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            cout << line << endl;
            lst.push_back(line);
        }
        for (const auto& i : lst) {
            cout << i << " ";
        }
        file.close();
    }

	return 0;
}