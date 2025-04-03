#include <iostream>
using namespace std;

//check if number is power of 2 
bool isPowerOfTwoLoop(int n) {
    if(n < 1) 
        return false;
    while (n > 1) {
        if(n % 2 != 0) 
            return false;
            n /= 2;
    }
    return true;
}

bool isPowerOfTwo(int n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}

void testIsPowerOfTwo() {
    bool pass = true;
    pass &= isPowerOfTwoLoop(1);
    pass &= isPowerOfTwoLoop(2);
    pass &= isPowerOfTwoLoop(16);
    pass &= !isPowerOfTwoLoop(18);

    pass &= isPowerOfTwo(1);
    pass &= isPowerOfTwo(2);
    pass &= isPowerOfTwo(32);
    pass &= !isPowerOfTwo(33);

    cout << (pass ? "PASS" : "FAIL") << endl;
}

