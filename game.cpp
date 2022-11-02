#include <SFML/Graphics.hpp>
#include <vector>
#include <time.h>
#include "game.h"

#include <iostream>

void Game::play()
{
    setStartPosition();

    sf::RenderWindow window(sf::VideoMode(1400, 1200), "Tetris");

    sf::Texture t1;
    t1.loadFromFile("images/background.jpg");
    sf::Sprite background(t1);

    sf::RectangleShape rectangle(sf::Vector2f(47, 47));

    bool left = false, right = false, rotate = false, down = false;
    sf::Clock clock;
    sf::Time delay = sf::seconds(1.0f);


    while (window.isOpen())
    {
        sf::Event event;
        sf::Time time = clock.getElapsedTime();

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed)
               if (event.key.code==sf::Keyboard::Up) rotate = true;
               else if (event.key.code==sf::Keyboard::Down) down = true;
               else if (event.key.code==sf::Keyboard::Right) right = true;
               else if (event.key.code==sf::Keyboard::Left) left = true;
        }
            
        window.draw(background);
        for(size_t i = 0; i < 10; i++)
            {
                for(size_t j = 0; j < 20; j++)
                {
                    rectangle.setPosition(50*i + 500, 50*j);
                    rectangle.setFillColor(game[i][j].getFieldColor());
                    window.draw(rectangle);
                }
            }       

        if(down)
        {
            delay = sf::seconds(0.001f);
        }

        if(right)
        {
            bool flag = true;
            for(size_t i = 0; i < 10; i++)
            {
                for(size_t j = 0; j < 20; j++)
                    {
                        if(game[i][j].getActive())
                        {
                            if(i+1 < sizeOfRow && flag)
                            {
                                game[i][j].setActive(false);
                                game[i+1][j].setActive(true);
                                game[i][j].setFieldColor(sf::Color::Black);
                                game[i+1][j].setFieldColor(game[i][j].getFieldColor());
                                flag = false;
                            }
                        }
                    }
            }
        }
        if(left)
        {
            bool flag = true;
            for(size_t i = 0; i < 10; i++)
            {
                for(size_t j = 0; j < 20; j++)
                    {
                        if(game[i][j].getActive())
                        {
                            if(i-1 < -1 && flag)
                            {
                                game[i][j].setActive(false);
                                game[i-1][j].setActive(true);
                                game[i][j].setFieldColor(sf::Color::Black);
                                game[i-1][j].setFieldColor(game[i][j].getFieldColor());
                                flag = false;
                            }
                        }
                    }
            }
        }

        if(time > delay)
        {
            
            // for(size_t i = 0; i < 10; i++)
            // {
            //     for(size_t j = 0; j < 20; j++)
            //     {
            //         if(game[i][j].getActive())
            //         {
            //             if((game[i][j+1].getFieldStatus()) || j == 19)
            //             {
            //                 game[i][j].setActive(false);
            //                 game[i][j].setFieldStatus(true);
            //                 game[i][j].setFieldColor(game[i][j].getFieldColor());
            //                 checkLine(j);
            //                 setStartPosition();

            //             }
            //             else
            //             {
            //                 game[i][j].setActive(false);
            //                 game[i][j+1].setActive(true);
            //                 game[i][j].setFieldColor(sf::Color::Black);
            //                 game[i][j+1].setFieldColor(game[i][j].getFieldColor());
            //                 checkLine(j);

            //             }
            //         }
                    
            //     }
            // }
            clock.restart();
        }

        delay = sf::seconds(1.0f);
        left = false; right = false; rotate = false; down = false;
        window.display();
    }

};


void Game::setStartPosition()
{
    srand ( time(NULL) );


    int arrayNum[] = {1, 2, 3, 4, 5};
    int RanIndex = rand() % 5;
    int randomize = arrayNum[RanIndex];

    switch (randomize)
    {
    case 1://I
    {
            game[3][0].setActive(true);
            game[4][0].setActive(true);
            game[5][0].setActive(true);
            game[6][0].setActive(true);

            game[3][0].setFieldColor(sf::Color::Red);
            game[4][0].setFieldColor(sf::Color::Red);
            game[5][0].setFieldColor(sf::Color::Red);
            game[6][0].setFieldColor(sf::Color::Red);
        break;
    }
    case 2:// L
        {
            game[4][0].setActive(true);
            game[4][1].setActive(true);
            game[5][1].setActive(true);
            game[6][1].setActive(true);

            game[4][0].setFieldColor(sf::Color::Yellow);
            game[4][1].setFieldColor(sf::Color::Yellow);
            game[5][1].setFieldColor(sf::Color::Yellow);
            game[6][1].setFieldColor(sf::Color::Yellow);
            break;
        }
    case 3://4
        {
            game[4][0].setActive(true);
            game[4][1].setActive(true);
            game[5][1].setActive(true);
            game[5][2].setActive(true);

            game[4][0].setFieldColor(sf::Color::Blue);
            game[4][1].setFieldColor(sf::Color::Blue);
            game[5][1].setFieldColor(sf::Color::Blue);
            game[5][2].setFieldColor(sf::Color::Blue);
            break;
        }
    case 4://O
        {
            game[4][0].setActive(true);
            game[5][0].setActive(true);
            game[4][1].setActive(true);
            game[5][1].setActive(true);

            game[4][0].setFieldColor(sf::Color::Green);
            game[5][0].setFieldColor(sf::Color::Green);
            game[4][1].setFieldColor(sf::Color::Green);
            game[5][1].setFieldColor(sf::Color::Green);
            break;
        }
    case 5://T
        {
            game[3][0].setActive(true);
            game[4][0].setActive(true);
            game[5][0].setActive(true);
            game[4][1].setActive(true);

            game[3][0].setFieldColor(sf::Color::White);
            game[4][0].setFieldColor(sf::Color::White);
            game[5][0].setFieldColor(sf::Color::White);
            game[4][1].setFieldColor(sf::Color::White);
            break;
        }

    
    default:
        break;
    }
    


}

void  Game::checkLine(int a)
{
    signed int j = 0;
    do
    {
        if(j == sizeOfRow)
        {
            removeLines(a);
        }
        j++;
    }while(game[j][a].getFieldStatus());


}

void Game::removeLines(int a)
{
    int j = 0;
    while(j < sizeOfRow)
    {
        game[j][a].setFieldStatus(false);
        game[j][a].setActive(false);
        game[j][a].setFieldColor(sf::Color::Black);
        j++;
    }

    fieldStatusDownAfterRemove(a-1);
}

void Game::fieldStatusDownAfterRemove(int a)
{
    for(int i = 0; i < sizeOfRow; i++)
    {
        for(int j = a; j >= 0; j--)
        {
            if(game[i][j].getFieldStatus())
            {
                game[i][j].setFieldStatus(false);
                game[i][j+1].setFieldStatus(true);
                game[i][j].setFieldColor(sf::Color::Black);
                game[i][j+1].setFieldColor(sf::Color::Red);
            }
        }
    }
}


