#include <iostream>
#include "MSBoardTextView.h"
#include "MinesweeperBoard.h"


using namespace std;
MSBoardTextView::MSBoardTextView(MinesweeperBoard& board):board(board)
{
}
void MSBoardTextView::display() {

    for (int wiersz = 0; wiersz < board.getBoardHeight(); wiersz++) {
        cout << endl;
        for (int kolumna = 0; kolumna < board.getBoardWidth(); kolumna++) {
            cout << "[" << board.getFieldInfo(wiersz, kolumna) << "]";

        }
    }
   std::cout << endl;
}