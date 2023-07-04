#pragma once

#ifndef MSTextController_H
#define MSTextController_H

#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"

class MSTextController
{
	MinesweeperBoard & board;
	MSBoardTextView& view;
	
public:
	MSTextController(MinesweeperBoard&, MSBoardTextView&);
	void play();


};



























#endif