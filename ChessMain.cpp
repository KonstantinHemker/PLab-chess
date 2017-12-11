#include <iostream>

using namespace std;

#include "ChessBoard.h"

int main() {

    cout << "===========================" << endl;
    cout << "Testing the Chess Engine" << endl;
    cout << "===========================" << endl;
    cout << endl;

    ChessBoard cb;
    cout << endl;

    /*OWN TESTS */
    //Seg Fault check
    /*
    cb.submitMove("A2", "A0");
    cout << endl;

    cb.submitMove("B1", "C3");
    cout << endl;

    //Check Bishops Move Invalid
    cb.submitMove("F1", "F3");
    cout << endl;

    //Check Bishops Move valid - not anymore
    cb.submitMove("F1", "H3");
    cout << endl;

    //Check Rook route invalidx
    cb.submitMove("A1", "A5");
    cout << endl;

    //Black Movement
    cb.submitMove("C8", "A6");
    cout << endl;

    //Check King's move invalid
    cb.submitMove("E1", "E2");
    cout << endl;

    //Check King's move valid
    cb.submitMove("E1", "F1");
    cout << endl;

    //Check Black's Rook Invali
    cb.submitMove("A8", "C6");
    cout << endl;

    //Check Black's Rook valid
    cb.submitMove("A8", "A5");
    cout << endl;

    //Check White's Knight invalid
    cb.submitMove("B1", "B3");
    cout << endl;

    //Check White's Knight invalid
    cb.submitMove("B1", "C3");
    cout << endl;

    //Check Black's Queen invalid`
    cb.submitMove("D8", "F4");
    cout << endl;

    //Check Black's Queen valid;
    cb.submitMove("D8", "D4");
    cout << endl;

    //Check White's pawn invalid
    cb.submitMove("D2", "E3");
    cout << endl;

    //Check White's pawn valid
    cb.submitMove("D2", "D3");
    cout << endl;
    */
    /*  PRE WRITTEN TESTS */
    cb.submitMove("D7", "D6");
    cout << endl;

    cb.submitMove("D4", "H6");
    cout << endl;

    cb.submitMove("D2", "D4");
    cout << endl;

    cb.submitMove("F8", "B4");
    cout << endl;

    cout << "===========================" << endl;
    cout << "Alekhine vs. Vasic (1931)" << endl;
    cout << "===========================" << endl;
    cout << endl;

    cb.resetBoard();
    cout << endl;

    cb.submitMove("E2", "E4");
    cb.submitMove("E7", "E6");
    cout << endl;

    cb.submitMove("D2", "D4");
    cb.submitMove("D7", "D5");
    cout << endl;

    cb.submitMove("B1", "C3");
    cb.submitMove("F8", "B4");
    cout << endl;

    cb.submitMove("F1", "D3");
    cb.submitMove("B4", "C3");
    cout << endl;

    cb.submitMove("B2", "C3");
    cb.submitMove("H7", "H6");
    cout << endl;

    cb.submitMove("C1", "A3");
    cb.submitMove("B8", "D7");
    cout << endl;

    cb.submitMove("D1", "E2");
    cb.submitMove("D5", "E4");
    cout << endl;

    cb.submitMove("D3", "E4");
    cb.submitMove("G8", "F6");
    cout << endl;

    cb.submitMove("E4", "D3");
    cb.submitMove("B7", "B6");
    cout << endl;

    cb.submitMove("E2", "E6");
    cb.submitMove("F7", "E6");
    cout << endl;

    cb.submitMove("D3", "G6");
    cout << endl;


    return 0;
}
