#include<SFML/Graphics.hpp>

#include<vector>

// for board see: https://godbolt.org/z/sWe1sWxTh

/*
TopLeftButton
TopMiddleButton
TopRightButton
MiddleLeftButton
MiddleMiddleButton
MiddleRightButton
BottomLeftButton
BottomMiddleButton
BottomRightButton
*/

int main()
{
    std::vector PositionsTaken{0, 0, 0,
                               0, 0, 0,
                               0, 0, 0};
    sf::RenderWindow window(sf::VideoMode(200, 200), "Snake");

    sf::Texture texture;
    texture.loadFromFile("my_texture.png");

    sf::Sprite TopLeftButton(texture);      TopLeftButton.setPosition(0, 0);
    sf::Sprite TopMiddleButton(texture);    TopMiddleButton.setPosition(69, 0);
    sf::Sprite TopRightButton(texture);     TopRightButton.setPosition(138, 0);
    sf::Sprite MiddleLeftButton(texture);   MiddleLeftButton.setPosition(0, 69);
    sf::Sprite MiddleMiddleButton(texture); MiddleMiddleButton.setPosition(69, 69);
    sf::Sprite MiddleRightButton(texture);  MiddleRightButton.setPosition(138, 69);
    sf::Sprite BottomLeftButton(texture);   BottomLeftButton.setPosition(0, 138);
    sf::Sprite BottomMiddleButton(texture); BottomMiddleButton.setPosition(69, 138);
    sf::Sprite BottomRightButton(texture);  BottomRightButton.setPosition(138, 138);

    sf::Sprite s_background;
    sf::Texture t_background;
    if (!t_background.loadFromFile("background.png")) { /*Handle the error*/ }
    else { s_background.setTexture(t_background); }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::Resized)
            {
                window.setSize(sf::Vector2u(200.f, 200.f));
            }
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                if      (TopLeftButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))      {}
                else if (TopMiddleButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))    {}
                else if (TopRightButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))     {}
                else if (MiddleLeftButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))   {}
                else if (MiddleMiddleButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {}
                else if (MiddleRightButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))  {}
                else if (BottomLeftButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))   {}
                else if (BottomMiddleButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {}
                else if (BottomRightButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))  {}
            }
        }

        window.clear();
        window.draw(s_background);
        window.display();
    }
}