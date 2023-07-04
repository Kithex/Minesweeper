#pragma once
#ifndef MINESBOARD_H__
#define MINESBOARD_H__

struct Field {
	bool hasMine;
	bool hasFlag;
	bool isRevealed;
};

enum GameMode { DEBUG, EASY, NORMAL, HARD };
enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };

class MinesweeperBoard
{
	// this is just a hint; you are free to implement PRIVATE section in any way you want
	Field board[100][100];
	int width;
	int height;
	void fillBoardWithMines(int how_many_mines);

    bool In_board(int field_row, int field_col) const;
    bool first_move;
	void Mine();

public:

	
	MinesweeperBoard(int width, int height, GameMode mode);
	void debug_display() const;

	int getBoardWidth() const;
	int getBoardHeight() const;
	int getMineCount() const;

	
	int countMines(int field_row, int field_col) const;


	bool hasFlag(int field_row, int field_col) const;

	// if the field at (row,col) was not revealed - change flag status for this field 
	// Do nothing if any of the following is true
	// - field was already revealed
	// - either row or col is outside board
	// - game is already finished
	void toggleFlag(int field_row, int field_col);

	bool hasMine(int field_row, int field_col) const;
	void revealField(int field_row, int field_col);

	
	bool isRevealed(int field_row, int field_col) const;

	// return current game state:
	// - FINISHED_LOSS - if the player revealed field with mine
	// - FINISHED_WIN  - if the player won the game (all unrevealed fields have mines)
	// - RUNNING       - if the game is not yet finished 
	GameState getGameState() const;

	
	char getFieldInfo(int field_row, int field_col) const;
};

#endif