#ifndef UI_H
#define UI_H

#include <SFML/Graphics.hpp>

extern int algorithm, mode, open_window;

class NormalButton {
public:
	sf::Text text;
    sf::RectangleShape button;
    bool clicked;
    NormalButton(std::string str, sf::Vector2f size, int charSize, sf::Color bgColor, sf::Color textColor);

    void setFont(sf::Font &font);
    void setBackColor(sf::Color color);
    void setTextColor(sf::Color color);
    void setPosition(sf::Vector2f pos);
    void drawTo(sf::RenderWindow &window);
    bool handleEvent(const sf::Event &event, sf::RenderWindow &window);

};

class ToggleButton {
public:
	sf::RectangleShape button;
    sf::Text text;
    sf::Texture texture1, texture2;
    sf::Sprite image, image2;
    bool isVisible;
    ToggleButton(std::string str, sf::Vector2f size, int charSize, sf::Color bgColor, sf::Color textColor);

    void setFont(sf::Font &font);
    void setBackColor(sf::Color color);
    void setTextColor(sf::Color color);
    void setPosition(sf::Vector2f pos);
    void drawTo(sf::RenderWindow &window);
    bool handleEvent(const sf::Event &event, sf::RenderWindow &window);
    void setImages(const std::string &imagePath1, const std::string &imagePath2);


    
};

void Graphical_UI();

#endif
