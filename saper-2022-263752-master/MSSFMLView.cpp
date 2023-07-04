
#include "MinesweeperBoard.h"
#include <SFML/Graphics.hpp>
#include "MSSFMLView.h"
#include <string>



MSSFMLView::MSSFMLView(MinesweeperBoard & b) : board(b)
{
}

void MSSFMLView::draw(sf::RenderWindow & win)
{
    sf::RectangleShape field (sf::Vector2f(20,20));
    sf::Color color_outline(0,0,0);
    sf::Color color_Unopened(96,96,96);
    sf::Color color_Opened(192,192,192);
    sf::Color color_1(51,153,253);
    sf::Color color_2(255,0,0);
    sf::Text text;
    sf::Font font;
    int size;
    size=20;

    font.loadFromFile("../Helvetica.ttf");
    text.setFont(font);
    text.setStyle(sf::Text::Regular);
    text.setCharacterSize(15);


    text.setFillColor(color_1);
    field.setOutlineThickness(2);
    field.setOutlineColor(color_outline);

    for(int row = 0; row <  board.getBoardWidth(); row++)
   {
        for(int col=0; col < board.getBoardHeight(); col++) {
            int rx, cy;
            rx = size * col;
            cy = size * row;
            field.setPosition(rx, cy);
            field.setFillColor(color_Unopened);
            text.setPosition(5 + rx, cy);
            win.draw(field);

            //zakryte
            if (board.getFieldInfo(row, col) == '_') {
                field.setFillColor(color_Unopened);

                win.draw(field);
            }
            // otwarte
            if (board.getFieldInfo(row, col) == ' ') {
                field.setFillColor(color_Opened);
                field.setPosition(rx, cy);
                win.draw(field);
            }
            //flaga
            if (board.getFieldInfo(row, col) == 'F') {
                text.setString("F");
                text.setPosition(5 + rx, cy);
                field.setFillColor(color_Unopened);
                win.draw(field);
                win.draw(text);
            }
            //mina
            if (board.getFieldInfo(row, col) == 'x') {
                field.setFillColor(color_2);
                win.draw(field);
            }
            //kolo miny
            if (board.getFieldInfo(row,col) == '1')
            {
                field.setFillColor(color_Opened);
                win.draw(field);
                text.setString('1');
                win.draw(text);

            }

            else if (board.getFieldInfo(row,col) == '2')
            {
                field.setFillColor(color_Opened);
                win.draw(field);

                text.setString((std::to_string(board.countMines(row,col))));
                win.draw(text);
            }
            else if (board.getFieldInfo(row,col) == '3')
            {
                field.setFillColor(color_Opened);
                win.draw(field);

                text.setString((std::to_string(board.countMines(row,col))));

                win.draw(text);
            }
            else if (board.getFieldInfo(row,col) == '4')
            {
                field.setFillColor(color_Opened);
                win.draw(field);

                text.setString((std::to_string(board.countMines(row,col))));

                win.draw(text);
            }
            else if (board.getFieldInfo(row,col) == '5')
            {
                field.setFillColor(color_Opened);
                win.draw(field);
                text.setString((std::to_string(board.countMines(row,col))));

                win.draw(text);
            }

            else if (board.getFieldInfo(row,col) == '6')
            {
                field.setFillColor(color_Opened);
                win.draw(field);
                text.setString((std::to_string(board.countMines(row,col))));

                win.draw(text);
            }
            else if (board.getFieldInfo(row,col) == '7')
            {
                field.setFillColor(color_Opened);
                win.draw(field);
                text.setString((std::to_string(board.countMines(row,col))));

                win.draw(text);
            }
            else if (board.getFieldInfo(row,col) == '8')
            {
                field.setFillColor(color_Opened);
                win.draw(field);
                text.setString((std::to_string(board.countMines(row,col))));

                win.draw(text);
            }
            if(board.getGameState()==FINISHED_LOSS) {
                text.setCharacterSize(board.getBoardWidth()*3.5);
                text.setString("YOU LOSE");
                text.setOutlineColor(sf::Color(0,0,0));
                text.setOutlineThickness(1);
                text.setPosition(board.getBoardWidth(),board.getBoardHeight());
                text.setFillColor(color_2);
                field.setFillColor(sf::Color(255,255,255,128));
                win.draw(field);
                win.draw(text);
            }
            if(board.getGameState()==FINISHED_WIN) {
                text.setCharacterSize(board.getBoardWidth()*3);
                text.setString("YOU WIN");
                text.setOutlineColor(sf::Color(255,255,255,128));
                sf::Color color_3(207,181,59);
                text.setFillColor(color_3);
                text.setOutlineThickness(1);
                text.setPosition(size,size);
                text.setFillColor(color_1);
                win.draw(field);
                win.draw(text);
            }


        }
   }
}


