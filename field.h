#include <SFML/Graphics.hpp>

class Field
{
    sf::Color color;
    bool status, isActive;

    public:
    Field();
    ~Field();

    void setFieldColor(sf::Color);
    void setFieldStatus(bool);
    void setActive(bool);

    sf::Color getFieldColor();
    bool getFieldStatus();
    bool getActive();
};