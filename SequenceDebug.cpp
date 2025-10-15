/**
 * SequenceDebug.cpp
 * Project 3
 * CS 3100
 *
 * In this file, you will write your tests as you implement Sequence. If you are using CLion, you need to select
 * SequenceDebug from the drop-down menu next to the Build (hammer icon) if it is on SequenceTestHarness
 */

#include "Sequence.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Your project is ready to go!" << endl;
    // Test default constructor and operator[]
    Sequence s1(3);
    s1[0] = "function";
    s1[1] = "parameter";
    s1[2] = "pointer";
    cout << s1 << endl;

    // Test push_back
    s1.push_back("const");
    cout << s1 << endl;

    // Test pop_back
    s1.pop_back();
    cout << s1 << endl;

    // Test insert
    s1.insert(1, "constructor");
    cout << s1 << endl;

    // Test front and back
    cout << s1.front() << endl;
    cout << s1.back() << endl;

    // Test empty and size
    cout << s1.empty() << endl;
    cout << s1.size() << endl;

    // Test clear
    s1.clear();
    cout << s1 << endl;

    // Test erase
    Sequence s2;
    s2.push_back("a");
    s2.push_back("b");
    s2.push_back("c");
    s2.push_back("d");
    s2.erase(1, 2);
    cout << s2 << endl;

    // Test assignment operator
    Sequence s3;
    s3 = s2;
    cout << s3 << endl;

    // Test copy constructor
    Sequence s4(s2);
    cout << s4 << endl;

    return 0;
}
