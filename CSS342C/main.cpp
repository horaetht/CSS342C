#include <iostream>
using namespace std;

extern void testIsPrime();
extern void testIsPowerOfTwo();
extern void testReduceFraction();

int main() {
    testIsPrime();
    testIsPowerOfTwo();
    testReduceFraction();
    return 0;
}