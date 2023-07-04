

#include <SFML/Graphics.hpp>

#ifndef SAPER_MSSFMLCONTROL_H
#define SAPER_MSSFMLCONTROL_H
namespace sf{
    class Event;
}

class MinesweeperBoard;
class MSSFMLView;
class MSSFMLControl {
    MinesweeperBoard & board;
    MSSFMLView & view;
public:
 MSSFMLControl(MinesweeperBoard & b, MSSFMLView & v);
 void Event(sf::Event &event);
};


#endif //SAPER_MSSFMLCONTROL_H
