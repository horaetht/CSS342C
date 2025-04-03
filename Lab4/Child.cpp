#include "Child.h"
using namespace std;

bool Child::operator<(const Child& other) const {
    if(lastName != other.lastName)
        return lastName < other.lastName;
    if(firstName != other.firstName)
        return firstName < other.firstName;
    return age < other.age;
}

bool Child::operator==(const Child& other) const {
    return lastName == other.lastName && firstName == other.firstName && age == other.age;

}

istream& operator>>(istream& is, Child& child) {
    is >> child.firstName >> child.lastName >> child.age;
    return is;
}

ostream& operator<<(ostream& os, const Child& child) {
    os << child.firstName << child.lastName << child.age;
    return os;
}