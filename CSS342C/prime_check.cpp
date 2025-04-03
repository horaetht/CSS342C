#include <iostream> 
using namespace std;

//check if a number is prime
bool isPrime(int n) {
    if(n < 2)
        return false;
    for (int i = 2; i * i <= n; i++) {
        if(n % i == 0) 
            return false;
    }
    return true;
}

void testIsPrime() { //testing function is it prime
    bool pass = true;
    pass &= !isPrime(1);
    pass &= isPrime(2);
    pass &= isPrime(3);
    pass &= !isPrime(4);
    pass &= isPrime(13);
    pass &= !isPrime(15);

    cout << (pass ? "PASS" : "FAIL") << endl;

}