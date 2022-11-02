#include <SFML/Graphics.hpp>
#include <vector>
#include "field.h"

class Game
{
    int row, column;
    Field game[10][20];
    signed int sizeOfColumn = 20, sizeOfRow = 10;
    public:
    Game(){};
    ~Game(){};
    void play();
    void getFigure();
    void setStartPosition();
    void checkLine(int );
    void removeLines(int );
    void fieldStatusDownAfterRemove(int );
    int drawFigure();
};