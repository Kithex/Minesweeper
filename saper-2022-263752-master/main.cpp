#include <iostream>
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include <SFML/Graphics.hpp>
#include "MSSFMLView.h"
#include "MSSFMLControl.h"

using namespace std;
int main() {

MinesweeperBoard board(15, 15, GameMode::EASY);
MSBoardTextView widok(board);
MSSFMLView view (board);
//MSTextController play(board, widok);
//play.play();
MSSFMLControl control(board,view);
int pom=0;

int screen_width = board.getBoardWidth()*20;
int screen_height = board.getBoardHeight()*20;
    sf::RenderWindow window(sf::VideoMode(screen_width, screen_height), "Saper");
    window.setVerticalSyncEnabled(true);
    while (window.isOpen())
    {
        pom++;
        if(pom%100==0){
            board.debug_display();
        }
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        control.Event(event);
        window.clear();
        view.draw(window);
        window.display();
    }
    return 0;
}

//cout << board.getBoardHeight();

//view.display();



