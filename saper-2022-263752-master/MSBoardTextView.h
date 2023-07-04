
#ifndef MINESBOARDTX_H__
#define MINESBOARDTX_H__

#include <iostream>

class MinesweeperBoard;

class MSBoardTextView
{
	MinesweeperBoard& board;
public:
	MSBoardTextView(MinesweeperBoard&);
	void display();
};































#endif