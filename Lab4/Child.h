#ifndef CHILD_H
#define CHILD_H

#include <iostream>
#include <string>
using namespace std;

class Child {
private:
    string firstName;
    string lastName;
    int age;

public:
    Child() : firstName(""), lastName(""), age(0) {}
    Child(const string& fn, const string& ln, int a) : firstName(fn), lastName(ln), age(a) {}

    bool operator<(const Child& other) const;
    bool operator==(const Child& other) const;
    bool operator!=(const Child& other) const {
        return !(*this == other);
    }

    friend istream& operator>>(istream& is, Child& child);
    friend ostream& operator<<(ostream& os, const Child& child);

};
#endif