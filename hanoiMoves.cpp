#include <iostream>
#include <fstream>
#include <cmath>
#include <chrono>
using namespace std;

void hanoiMoves(int n, string from, string to, string extra) {
    if (n == 1) {
        cout << "Move disk 1 from " << from << " to " << to << endl;
        return;
    }
    hanoiMoves(n - 1, from, extra, to);

    cout << "Move disks " << n << " from" << from << " to " << to << endl;

    hanoiMoves(n - 1, extra, to, from);

}

int hanoiMovesPrint(int n, string from, string to, string extra) {
    if(n == 1) {
        return 1;
    }

    int moves = hanoiMovesPrint(n - 1, from, extra, to);

    moves +=1;

    moves += hanoiMovesPrint(n - 1, extra, to, from);

    return moves;
    
}

void hanoiMovesTracking () {
    ofstream outFile("hanoi_result.csv");

    for(int n = 1; n <= 15; n++ ){
        auto start = chrono::high_resolution_clock::now();
        
        int moves = hanoiMovesPrint(n, "A", "C", "B");
        
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::microseconds>(end - start).count();
        
        outFile << n << "," << moves << "," << elapsed << "\n";
        
        cout << "n=" << n << ": " << moves << " moves, " << elapsed << " microseconds" << endl;
    }

    outFile.close();
}

int main() {
    cout << "hanoiMoves for n=3:\n";
    hanoiMoves(3, "A", "C", "B");
    
    cout << "\nTracking number of moves and time for n=1 to n=15:\n";
    hanoiMovesTracking();

    cout << "\nFormula for the number of moves: 2^n - 1\n";
    for (int n = 1; n <= 15; n++) {
        cout << "For n=" << n << ", moves = " << pow(2, n) - 1 << endl;
    }

    return 0;
}
    


