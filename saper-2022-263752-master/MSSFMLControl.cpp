//
// Created by OMEGAPEPE on 23.04.2022.
//
#include <iostream>
#include "MinesweeperBoard.h"
#include "MSSFMLControl.h"
#include <SFML/Graphics.hpp>
MSSFMLControl::MSSFMLControl(MinesweeperBoard & b, MSSFMLView & v) : board (b) , view (v)
{
}
void MSSFMLControl::Event(sf::Event &event) {
    if(event.type == sf::Event::MouseButtonReleased){
    int mouse_row = (event.mouseButton.y)/20;
    int mouse_col = (event.mouseButton.x)/20;

       if(event.mouseButton.button== sf::Mouse::Right) {

           board.toggleFlag(mouse_row, mouse_col);

       }

    if (event.mouseButton.button == sf::Mouse::Left)
    {
        board.revealField(mouse_row,mouse_col);

    }
    }
}
