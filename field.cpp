#include "field.h"

Field::Field()
{
    color = sf::Color::Black;
    status = false;
    isActive = false;
}

Field::~Field()
{

}

void Field::setFieldColor(sf::Color color)
{
    this->color = color;
}

void Field::setFieldStatus(bool status)
{
    this->status = status;
}

void Field::setActive(bool isActive)
{
    this->isActive = isActive;
}

bool Field::getFieldStatus()
{
    return status;
}
bool Field::getActive()
{
    return isActive;
}

sf::Color Field::getFieldColor()
{
    return color;
}