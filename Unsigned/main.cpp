#include <iostream>
#include "Buffer_2D.h"

using namespace std;


class QuadNode
{
public:
    QuadNode *children[4] = { 0, 0, 0, 0 };
    float *val = nullptr; // Αρχικοποίηση του val με nullptr
};

void fillQuadTree(QuadNode &root, float value) {
    bool isLeaf = true; // Υποθέτουμε αρχικά ότι ο κόμβος είναι φύλλο
    for (int i = 0; i < 4; i++) {
        if (root.children[i] != nullptr) {
            isLeaf = false; // Αν βρούμε παιδί που δεν είναι nullptr, δεν είναι φύλλο
            fillQuadTree(*root.children[i], value); // Αναδρομικά καλούμε τη συνάρτηση για το παιδί
        }
    }
    if (isLeaf) {
        root.val = new float(value); // Αν ο κόμβος είναι φύλλο, του αναθέτουμε την τιμή
    }
}

int main(){
    QuadNode root, a, b, e;
    QuadNode* c = new QuadNode();
    QuadNode* d = new QuadNode();

    root.children[0] = &a;
    root.children[1] = &b;
    root.children[2] = c;
    root.children[3] = d;

    b.children[1] = &e;

    // Κλήση της συνάρτησης fillQuadTree με τιμή 5.0
    fillQuadTree(root, 5.0f);

    // Έλεγχος αποτελεσμάτων
    if (root.val != nullptr) std::cout << "Root val: " << *(root.val) << std::endl;
    if (a.val != nullptr) std::cout << "A val: " << *(a.val) << std::endl;
    if (b.val != nullptr) std::cout << "B val: " << *(b.val) << std::endl;
    if (c->val != nullptr) std::cout << "C val: " << *(c->val) << std::endl;
    if (d->val != nullptr) std::cout << "D val: " << *(d->val) << std::endl;
    if (e.val != nullptr) std::cout << "E val: " << *(e.val) << std::endl;

    // Διαγραφή της δυναμικής μνήμης
    delete c;
    delete d;

    return 0;
}

