#include <iostream>
#include "MSBoardTextView.h"
#include "MinesweeperBoard.h"
#include "MSTextController.h"

using namespace std;
MSTextController::MSTextController(MinesweeperBoard& board, MSBoardTextView& view) :board(board), view(view)
{

}	
void MSTextController::play()
{
	int wiersz, kolumna;
	string move;

	while (board.getGameState() == RUNNING)
	{
		view.display();
		cout << "Co chcesz zrobic: "<< "by nalozyc/usunac flage (f)"<<" "<<"by odkryc pole (o)" << endl;
		cin >> move;

		cout << "Podaj rzad: " << endl;
		cin >> wiersz;
		cout << "Podaj kolumne: " << endl;
		cin >> kolumna;
		if (move == "f")
		{
			board.toggleFlag(wiersz, kolumna);
		}
		if (move == "o")
		{
			board.revealField(wiersz, kolumna);

		}

	}
	if (board.getGameState()== FINISHED_LOSS)
    {
        cout << "YOU LOSE";
    }
    if (board.getGameState() == FINISHED_WIN)
    {
        cout << "YOU WIN";
    }
}