#include <iostream>
using namespace std;

void test();

class Fraction {
public:
    int numerator;
    int denominator;

    Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {}

    string to_string() const {
        return std::to_string(numerator) + "/" + std::to_string(denominator);
    }
};

// Function to calculate GCD (Greatest Common Divisor)
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Reduce the fraction
Fraction reduce(Fraction input) {
    int divisor = gcd(input.numerator, input.denominator);
    return Fraction(input.numerator / divisor, input.denominator / divisor);
}

// int main() {
//     Fraction num1(2, 4);
//     cout << reduce(num1).to_string() << endl;

//     test(); 
// }

void testReduceFraction() {
    Fraction input(2, 4);
    Fraction expected_output(1, 2);
    Fraction actual_output = reduce(input);


    //compare expected vs actual
    if (expected_output.denominator == actual_output.denominator &&
        expected_output.numerator == actual_output.numerator) {
        cout << "PASS!" << endl;
    } else {
        cout << "FAIL" << endl;
    }
}



