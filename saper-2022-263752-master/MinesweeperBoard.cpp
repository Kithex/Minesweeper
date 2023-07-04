#include <iostream>
#include <vector>
#include "MinesweeperBoard.h"
#include <cstdlib>
#include <ctime>
#include "MSSFMLView.h"
using namespace std;

MinesweeperBoard::MinesweeperBoard(int width, int height, GameMode mode) {

   this-> width = width;
   this-> height = height;
   first_move=true;
   srand(time(NULL));
    for (int wiersz = 0; wiersz < height; wiersz++) {
        for (int kolumna = 0; kolumna < width; kolumna++) {
            board[wiersz][kolumna].hasMine = false;
            board[wiersz][kolumna].hasFlag = false;
            board[wiersz][kolumna].isRevealed = false;
        }
    }


    switch (mode) {
    case DEBUG: {
        
for (int wiersz = 0; wiersz < height; wiersz++) {
            for (int kolumna = 0; kolumna < width; kolumna++) {
                if (wiersz == kolumna or wiersz == 0 or (kolumna == 0 and wiersz % 2 == 0))
                    board[wiersz][kolumna].hasMine = true;

            }
        }

    }
             break;
    case EASY: {
        int how_many_mines = width * height * 0.1;
        fillBoardWithMines(how_many_mines);
    }
             break;
    case NORMAL: {
        int how_many_mines = width * height * 0.2;
      fillBoardWithMines(how_many_mines);
    }
               break;
    case HARD: {
        int how_many_mines = width * height * 0.3;
       fillBoardWithMines(how_many_mines);
    }
             break;


    }
}

void MinesweeperBoard::fillBoardWithMines(int how_many_mines) {
    while (true) {
        int mine_row = rand() % height;
        int mine_col = rand() % width;
        if (!board[mine_row][mine_col].hasMine) {


            board[mine_row][mine_col].hasMine = true;
            how_many_mines--;
        }

        if (how_many_mines == 0)
            break;
    }
}
void MinesweeperBoard::debug_display() const {

    for (int wiersz = 0; wiersz < height; wiersz++) {
            std::cout << std::endl;
            for (int kolumna = 0; kolumna < width; kolumna++) {
                std::cout << "[";
                if (board[wiersz][kolumna].hasMine) {
                    std::cout << "M";
                }
                else {
                    std::cout << ".";
                }
                if (board[wiersz][kolumna].hasFlag) {
                    std::cout << "f";


                }
                else {
                    std::cout << ".";
                }
                if (board[wiersz][kolumna].isRevealed) {
                    std::cout << "o";

                }
                else {
                    std::cout << ".";
                }
                std::cout << "]";
            }
    }
}

   
int MinesweeperBoard::getBoardWidth() const {                                                                                                                            
    return width;
}
int MinesweeperBoard::getBoardHeight() const {
    return height;
}

 int MinesweeperBoard::getMineCount() const {
    int mine_counter = 0;
    for (int wiersz = 0; wiersz < height; wiersz++) {
    for (int kolumna = 0; kolumna < width; kolumna++) {
   
        if (board[wiersz][kolumna].hasMine)
            mine_counter++;
    }


}
    return mine_counter;
}
bool MinesweeperBoard::In_board(int field_row, int field_col) const {
    if (field_row >= height or field_col >= width)
        return false;
    if(field_row < 0 or field_col < 0)
        return false;
    else return true;
}
 int MinesweeperBoard::countMines(int field_row, int field_col) const {
     int mine_counter = 0;

     if (!In_board(field_row, field_col)) return -1;
     if (!board[field_row][field_col].isRevealed) return -1;


     for (int row = (-1); row < 2; row++)
     {
         for (int Kolumna = (-1); Kolumna < 2; Kolumna++)
         {
             if ((field_row + row) < 0 or (field_col + Kolumna) < 0) continue;
             if ((field_row + row) > height or (field_col + Kolumna) > width) continue;
             if (board[field_row + row][field_col + Kolumna].hasMine) mine_counter++;
         }
     }
     if (board[field_row][field_col].hasMine) mine_counter--;
     return mine_counter;
 }




 bool MinesweeperBoard::hasFlag(int field_row, int field_col) const
 {
    return board[field_row][field_col].hasFlag;
 }
 void MinesweeperBoard::toggleFlag(int field_row, int field_col) {
  if(In_board(field_row,field_col)) {
      if (hasFlag(field_row, field_col))
      {
          board[field_row][field_col].hasFlag = 0;
      }
      else
      {
          board[field_row][field_col].hasFlag = 1;
      }
  }
 }
 void MinesweeperBoard::Mine(){
    int x=rand() % width;
    int y=rand() % height;
    if (board[y][x].hasMine!=1)
    {
        board[y][x].hasMine=1;
    }
    else
    {
        Mine();
    }
}
 void MinesweeperBoard::revealField(int field_row, int field_col) {
     if (In_board(field_row, field_col)==0 || board[field_row][field_col].isRevealed==1)
     {
         return;
     }


     if (isRevealed(field_row, field_col)==0 && hasMine(field_row, field_col)==0) {

         board[field_row][field_col].isRevealed = true;
         first_move = false;
         if (countMines(field_row, field_col) == 0) {

             revealField(field_row - 1, field_col - 1);

             revealField(field_row, field_col - 1);

             revealField(field_row - 1, field_col);

             revealField(field_row, field_col);

             revealField(field_row, field_col + 1);

             revealField(field_row + 1, field_col);

             revealField(field_row + 1, field_col + 1);
         }
     }
     if (isRevealed(field_row, field_col)==0 && hasMine(field_row, field_col))
     {
         if (first_move==true) {
             board[field_row][field_col].isRevealed = true;
             board[field_row][field_col].hasMine = false;
             int pom=std::rand()%3;

             if(In_board(field_row+pom,field_col+pom)==true)
             {
                 board[field_row+pom][field_col+pom].hasMine;
             }
             first_move=false;
             getGameState();

         }
         else
             {
             board[field_row][field_col].isRevealed = true;

             getGameState();
             }


     }
 }


        
     

 bool MinesweeperBoard::isRevealed(int field_row, int field_col) const {
     return board[field_row][field_col].isRevealed;
 }
 GameState MinesweeperBoard::getGameState() const {
     for (int wiersz = 0; wiersz < height; wiersz++) {
         for (int kolumna = 0; kolumna < width; kolumna++) {
             if (board[wiersz][kolumna].isRevealed && board[wiersz][kolumna].hasMine) {
                 return FINISHED_LOSS;
             }

         }
     }
     int mines = 0;
     for (int wiersz = 0; wiersz < height; wiersz++)
     {
         for (int kolumna = 0; kolumna < width; kolumna++)
         {
             if (!board[wiersz][kolumna].isRevealed)
                 mines++;
         }
     }
     if (mines == getMineCount())
         return FINISHED_WIN;
     
     if (mines != getMineCount())
         return RUNNING;
 }
bool MinesweeperBoard::hasMine(int field_row, int field_col) const
{
    return board[field_row][field_col].hasMine;
}
 char MinesweeperBoard::getFieldInfo(int field_row, int field_col) const {
     if (!In_board(field_row, field_col))
         return '#';
     if (!board[field_row][field_col].isRevealed && board[field_row][field_col].hasFlag)
         return 'F';
     if (!board[field_row][field_col].isRevealed && !board[field_row][field_col].hasFlag)
         return '_';
     if (board[field_row][field_col].isRevealed && board[field_row][field_col].hasMine)
         return 'x';
     if (board[field_row][field_col].isRevealed && countMines(field_row, field_col) == 0)
         return ' ';
     if (board[field_row][field_col].isRevealed && countMines(field_row, field_col) != 0) {
         switch (countMines(field_row,field_col))
         {
             case 1: return '1'; break;
             case 2: return '2'; break;
             case 3: return '3'; break;
             case 4: return '4'; break;
             case 5: return '5'; break;
             case 6: return '6'; break;
             case 7: return '7'; break;
             case 8: return '8'; break;



         }
     }

 }
