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

auto f_to_u(const sf::Vector2f& vec_one)
{
    return sf::Vector2u(vec_one.x, vec_one.y);
}

bool checkWin(const std::vector<int>& PositionsTaken) {
    // Check rows
    for (int i = 0; i < 9; i += 3) {
        if (PositionsTaken[i] != 0 && PositionsTaken[i] == PositionsTaken[i + 1] && PositionsTaken[i + 1] == PositionsTaken[i + 2]) {
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (PositionsTaken[i] != 0 && PositionsTaken[i] == PositionsTaken[i + 3] && PositionsTaken[i + 3] == PositionsTaken[i + 6]) {
            return true;
        }
    }

    // Check diagonals
    if (PositionsTaken[0] != 0 && PositionsTaken[0] == PositionsTaken[4] && PositionsTaken[4] == PositionsTaken[8]) {
        return true;
    }
    if (PositionsTaken[2] != 0 && PositionsTaken[2] == PositionsTaken[4] && PositionsTaken[4] == PositionsTaken[6]) {
        return true;
    }

    // Check stalemate
    for (int i = 0; i < 9; i++) {
        if (PositionsTaken[i] == 0) {
            return false;
        }
    }

    return true;
}

int main()
{
    // 0 is nothing
    // 1 is naughts
    // 2 is crosses
    std::vector<std::pair<sf::Vector2u, int>> PositionsTaken
    {
        std::pair<sf::Vector2u, int>{sf::Vector2u{0, 0},     0},
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

    bool has_won = false;

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
            if (event.mouseButton.button == sf::Mouse::Left && !has_won)
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
                        if (WhoseGo) { WhoseGo = false; }
                        else { WhoseGo = true; }
                        PositionsTaken[0].first = f_to_u(TopLeftButton.getPosition());;
                    }
                }
                else if (TopMiddleButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    int current_number = 1; if (PositionsTaken[current_number].second == 0) {
                        if (WhoseGo) { PositionsTaken[current_number].second = 1; }
                        else { PositionsTaken[current_number].second = 2; } if (WhoseGo) { WhoseGo = false; }
                        else { WhoseGo = true; }
                    }
                    PositionsTaken[1].first = f_to_u(TopMiddleButton.getPosition());
                }
                else if (TopRightButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    int current_number = 2; if (PositionsTaken[current_number].second == 0) {
                        if (WhoseGo) { PositionsTaken[current_number].second = 1; }
                        else { PositionsTaken[current_number].second = 2; } if (WhoseGo) { WhoseGo = false; }
                        else { WhoseGo = true; }
                    }
                    PositionsTaken[2].first = f_to_u(TopRightButton.getPosition());
                }
                else if (MiddleLeftButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    int current_number = 3; if (PositionsTaken[current_number].second == 0) {
                        if (WhoseGo) { PositionsTaken[current_number].second = 1; }
                        else { PositionsTaken[current_number].second = 2; } if (WhoseGo) { WhoseGo = false; }
                        else { WhoseGo = true; }
                    }
                    PositionsTaken[3].first = f_to_u(MiddleLeftButton.getPosition());
                }
                else if (MiddleMiddleButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    int current_number = 4; if (PositionsTaken[current_number].second == 0) {
                        if (WhoseGo) { PositionsTaken[current_number].second = 1; }
                        else { PositionsTaken[current_number].second = 2; } if (WhoseGo) { WhoseGo = false; }
                        else { WhoseGo = true; }
                    }
                    PositionsTaken[4].first = f_to_u(MiddleMiddleButton.getPosition());
                }
                else if (MiddleRightButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    int current_number = 5; if (PositionsTaken[current_number].second == 0) {
                        if (WhoseGo) { PositionsTaken[current_number].second = 1; }
                        else { PositionsTaken[current_number].second = 2; } if (WhoseGo) { WhoseGo = false; }
                        else { WhoseGo = true; }
                    }
                    PositionsTaken[5].first = f_to_u(MiddleRightButton.getPosition());
                }
                else if (BottomLeftButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    int current_number = 6; if (PositionsTaken[current_number].second == 0) {
                        if (WhoseGo) { PositionsTaken[current_number].second = 1; }
                        else { PositionsTaken[current_number].second = 2; } if (WhoseGo) { WhoseGo = false; }
                        else { WhoseGo = true; }
                    }
                    PositionsTaken[6].first = f_to_u(BottomLeftButton.getPosition());
                }
                else if (BottomMiddleButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    int current_number = 7; if (PositionsTaken[current_number].second == 0) {
                        if (WhoseGo) { PositionsTaken[current_number].second = 1; }
                        else { PositionsTaken[current_number].second = 2; } if (WhoseGo) { WhoseGo = false; }
                        else { WhoseGo = true; }
                    }
                    PositionsTaken[7].first = f_to_u(BottomMiddleButton.getPosition());
                }
                else if (BottomRightButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    int current_number = 8; if (PositionsTaken[current_number].second == 0) {
                        if (WhoseGo) { PositionsTaken[current_number].second = 1; }
                        else { PositionsTaken[current_number].second = 2; } if (WhoseGo) { WhoseGo = false; }
                        else { WhoseGo = true; }
                    }  
                    PositionsTaken[8].first = f_to_u(BottomRightButton.getPosition());
                }
            }
        }

        // ---------------------------------------------------------------------------------------------------------------
        // This is where we check if anyone has won.
        std::vector<int> player_positions{};
        player_positions.reserve(9);
        for (const auto& x : PositionsTaken)
        {
            player_positions.push_back(x.second);
        }
        has_won = checkWin(player_positions);
        // ---------------------------------------------------------------------------------------------------------------

        window.clear();
        window.draw(s_background);
        for (auto& x : PositionsTaken)
        {
            if (x.second == 0) {/**/ }
            else
            {
                if (x.second == 1)
                {
                    sf::Sprite naught_two;
                    naught_two.setTexture(t_naught);
                    naught_two.setPosition(x.first.x, x.first.y);
                    window.draw(naught_two);
                    //std::cout << "cross\n";
                }
                if (x.second == 2)
                {
                    sf::Sprite cross_two;
                    cross_two.setTexture(t_cross);
                    cross_two.setPosition(x.first.x, x.first.y);
                    window.draw(cross_two);
                    //std::cout << "naught\n";
                }
            }
        }
        window.display();
    }
}