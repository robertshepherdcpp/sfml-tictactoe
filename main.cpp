#include<SFML/Graphics.hpp>

#include<vector>
#include<iostream>

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
    // 0 is nothing
    // 1 is naughts
    // 2 is crosses
    std::vector<std::pair<sf::Vector2u, int>> PositionsTaken
    {
        std::pair<sf::Vector2u, int>{sf::Vector2u{0, 9},     0},
        std::pair<sf::Vector2u, int>{sf::Vector2u{69, 0},    0},
        std::pair<sf::Vector2u, int>{sf::Vector2u{138, 0},   0},
        std::pair<sf::Vector2u, int>{sf::Vector2u{0, 69},    0},
        std::pair<sf::Vector2u, int>{sf::Vector2u{69, 69},   0},
        std::pair<sf::Vector2u, int>{sf::Vector2u{138, 69},  0},
        std::pair<sf::Vector2u, int>{sf::Vector2u{0, 138},   0},
        std::pair<sf::Vector2u, int>{sf::Vector2u{69, 138},  0},
        std::pair<sf::Vector2u, int>{sf::Vector2u{138, 138}, 0}
    };
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

    sf::Texture t_naught;
    t_naught.loadFromFile("naught.png");
    sf::Texture t_cross;
    t_cross.loadFromFile("cross.png");

    sf::Sprite naught;
    naught.setTexture(t_naught);
    sf::Sprite cross;
    cross.setTexture(t_cross);

    bool WhoseGo = false; // false is naughts, true is crosses

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
                if (TopLeftButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) 
                { 
                    if (PositionsTaken[0].second == 0) 
                    { 
                        if (WhoseGo) 
                        { 
                            PositionsTaken[0].second = 1; 
                        } 
                        else 
                        {
                            PositionsTaken[0].second = 2; 
                        } 
                        if (WhoseGo) { WhoseGo = false; } else { WhoseGo = true; }
                    } 
                }
                else if (TopMiddleButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))    { int current_number = 1; if (PositionsTaken[current_number].second == 0) { if (WhoseGo) { PositionsTaken[0].second = 1; } else { PositionsTaken[current_number].second = 2; } if (WhoseGo) { WhoseGo = false; }
                else { WhoseGo = true; }
                } }
                else if (TopRightButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))     { int current_number = 1; if (PositionsTaken[current_number].second == 0) { if (WhoseGo) { PositionsTaken[0].second = 1; } else { PositionsTaken[current_number].second = 2; } if (WhoseGo) { WhoseGo = false; }
                else { WhoseGo = true; }
                } }
                else if (MiddleLeftButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))   { int current_number = 1; if (PositionsTaken[current_number].second == 0) { if (WhoseGo) { PositionsTaken[0].second = 1; } else { PositionsTaken[current_number].second = 2; } if (WhoseGo) { WhoseGo = false; }
                else { WhoseGo = true; }
                } }
                else if (MiddleMiddleButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) { int current_number = 1; if (PositionsTaken[current_number].second == 0) { if (WhoseGo) { PositionsTaken[0].second = 1; } else { PositionsTaken[current_number].second = 2; } if (WhoseGo) { WhoseGo = false; }
                else { WhoseGo = true; }
                } }
                else if (MiddleRightButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))  { int current_number = 1; if (PositionsTaken[current_number].second == 0) { if (WhoseGo) { PositionsTaken[0].second = 1; } else { PositionsTaken[current_number].second = 2; } if (WhoseGo) { WhoseGo = false; }
                else { WhoseGo = true; }
                } }
                else if (BottomLeftButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))   { int current_number = 1; if (PositionsTaken[current_number].second == 0) { if (WhoseGo) { PositionsTaken[0].second = 1; } else { PositionsTaken[current_number].second = 2; } if (WhoseGo) { WhoseGo = false; }
                else { WhoseGo = true; }
                } }
                else if (BottomMiddleButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) { int current_number = 1; if (PositionsTaken[current_number].second == 0) { if (WhoseGo) { PositionsTaken[0].second = 1; } else { PositionsTaken[current_number].second = 2; } if (WhoseGo) { WhoseGo = false; }
                else { WhoseGo = true; }
                } }
                else if (BottomRightButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))  { int current_number = 1; if (PositionsTaken[current_number].second == 0) { if (WhoseGo) { PositionsTaken[0].second = 1; } else { PositionsTaken[current_number].second = 2; } if (WhoseGo) { WhoseGo = false; }
                else { WhoseGo = true; }
                } }
            }
        }

        window.clear();
        window.draw(s_background);
        for (const auto& x : PositionsTaken)
        {
            if (x.second == 0) {/**/ }
            else
            {
                if (x.second == 1)
                {
                    naught.setPosition(x.first.x, x.first.y);
                    window.draw(naught);
                }
                if (x.second == 2)
                {
                    cross.setPosition(x.first.x, x.first.y);
                    window.draw(naught);
                }
            }
        }
        window.display();
    }
}