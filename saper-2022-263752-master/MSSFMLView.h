#include <iostream>
#include "MinesweeperBoard.h"

#include <SFML/Graphics.hpp>

#ifndef SAPER_MSSFMLVIEW_H
#define SAPER_MSSFMLVIEW_H


class MSSFMLView
{
    MinesweeperBoard & board;



public:
    explicit MSSFMLView(MinesweeperBoard & b);

    void draw (sf::RenderWindow & win);
};
#endif //SAPER_MSSFMLVIEW_H
