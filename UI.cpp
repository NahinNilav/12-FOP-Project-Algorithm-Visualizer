#include "Text_Box.h"
#include "UI.h"
int algorithm, mode;
// bubble 1, insertion 2, selection 3
// mode 1 default, mode 2 custom,


NormalButton::NormalButton(std::string str, sf::Vector2f size, int charSize, sf::Color bgColor, sf::Color textColor){

    text.setString(str);
    text.setFillColor(textColor);
    text.setCharacterSize(charSize);

    button.setSize(size);
    button.setFillColor(bgColor);
    clicked = false;
}

void NormalButton::setFont(sf::Font &font){
    text.setFont(font);
}

void NormalButton::setBackColor(sf::Color color){
    button.setFillColor(color);
}

void NormalButton::setTextColor(sf::Color color){
    text.setFillColor(color);
}

void NormalButton::setPosition(sf::Vector2f pos){

    button.setPosition(pos);

    float xPos = (pos.x + button.getLocalBounds().width / 2) - (text.getLocalBounds().width / 2);
    float yPos = (pos.y + button.getLocalBounds().height / 2) - (text.getLocalBounds().height / 2);
    text.setPosition(xPos, yPos);

}

void NormalButton::drawTo(sf::RenderWindow &window){
    window.draw(button);
    window.draw(text);
}

bool NormalButton::handleEvent(const sf::Event &event, sf::RenderWindow &window){

    if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left){
        sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

        if (button.getGlobalBounds().contains(mousePos))
            return true;
    }
    return false;
}




ToggleButton::ToggleButton(std::string str, sf::Vector2f size, int charSize, sf::Color bgColor, sf::Color textColor)
    : button(size), isVisible(false){

    button.setFillColor(bgColor);

    text.setString(str);
    text.setFillColor(textColor);
    text.setCharacterSize(charSize);
}

void ToggleButton::setFont(sf::Font &font){
    text.setFont(font);
}

void ToggleButton::setBackColor(sf::Color color){
    button.setFillColor(color);
}

void ToggleButton::setTextColor(sf::Color color){
    text.setFillColor(color);
}

void ToggleButton::setPosition(sf::Vector2f pos){

    button.setPosition(pos);
    image.setPosition(pos.x + 10, pos.y + button.getSize().y);
    image2.setPosition(pos.x + 10, pos.y + button.getSize().y + 30);
    text.setPosition(pos.x + (button.getSize().x - text.getLocalBounds().width) / 2,
                        pos.y + (button.getSize().y - text.getLocalBounds().height) / 2);
}

void ToggleButton::drawTo(sf::RenderWindow &window){

    window.draw(button);
    window.draw(text);
    if (isVisible){
        window.draw(image);
        window.draw(image2);
    }
}

bool ToggleButton::handleEvent(const sf::Event &event, sf::RenderWindow &window){

    if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left){

        sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

        if (button.getGlobalBounds().contains(mousePos)){
            isVisible = !isVisible;
            return true;
        }

        else if (isVisible){
            sf::FloatRect imageBounds1(image.getPosition().x, image.getPosition().y,
                                        image.getLocalBounds().width, image.getLocalBounds().height);
            if (imageBounds1.contains(mousePos)){
                mode = 1;
                return true;
            }
            sf::FloatRect imageBounds2(image2.getPosition().x, image2.getPosition().y,
                                        image2.getLocalBounds().width, image2.getLocalBounds().height);
            if (imageBounds2.contains(mousePos)){
                mode = 2;
                return true;
            }
        }
    }
    return false;
}

void ToggleButton::setImages(const std::string &imagePath1, const std::string &imagePath2){

    if (texture1.loadFromFile(imagePath1) && texture2.loadFromFile(imagePath2)){
        image.setTexture(texture1);
        image2.setTexture(texture2);
    }
    else
        std::cerr << "Failed to load images." << std::endl;
}


int open_window=0;


void Graphical_UI(){

    mode=-1;
    sf::RenderWindow window(sf::VideoMode(800, 600), "Algorithm Visualizer");
    window.setPosition(sf::Vector2i(sf::VideoMode::getDesktopMode().width * 0.5 - window.getSize().x * 0.5, sf::VideoMode::getDesktopMode().height * 0.5 - window.getSize().y * 0.5));
    
    sf::Font font;
    if (!font.loadFromFile("ClashGrotesk-Bold.otf"))
        return;

    ToggleButton button1("Bubble Sort", sf::Vector2f(150, 50), 17, sf::Color::Green, sf::Color::Black);
    ToggleButton button2("Insertion Sort", sf::Vector2f(150, 50), 17, sf::Color::Green, sf::Color::Black);
    ToggleButton button3("Selection Sort", sf::Vector2f(150, 50), 17, sf::Color::Green, sf::Color::Black);
    NormalButton button4("Binary Search", sf::Vector2f(150, 50), 17, sf::Color::Green, sf::Color::Black);

    button1.setFont(font);
    button2.setFont(font);
    button3.setFont(font);
    button4.setFont(font);

    button1.setPosition(sf::Vector2f(125, 250));
    button2.setPosition(sf::Vector2f(325, 250));
    button3.setPosition(sf::Vector2f(525, 250));
    button4.setPosition(sf::Vector2f(325, 400));

    button1.setImages("Frame 1.png", "Frame 2.png");
    button2.setImages("Frame 1.png", "Frame 2.png");
    button3.setImages("Frame 1.png", "Frame 2.png");

    while (window.isOpen()&&!open_window){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();

            else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left){
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

                if (button1.handleEvent(event, window)){
                    algorithm = 1;
                    if (mode != -1){
                        window.close();
                        show_box(algorithm, mode);
                        mode = -1;
                    }
                }
                else if (button2.handleEvent(event, window)){
                    algorithm = 2;
                    if (mode != -1){
                        window.close();
                        show_box(algorithm, mode);
                        mode = -1;
                    }
                }
                else if (button3.handleEvent(event, window)){
                    algorithm = 3;
                    if (mode != -1){
                        window.close();
                        show_box(algorithm, mode);
                        mode = -1;
                    }
                }
                else if (button4.handleEvent(event, window)){
                    window.close();
                    algorithm = 4;
                    show_box(algorithm, mode);
                }
            }
        }

        sf::Texture backgroundTexture;
        if (backgroundTexture.loadFromFile("background3.png")){
            sf::Sprite background(backgroundTexture);
            window.draw(background);
        }

        sf::Text heading("Algorithm Visualizer", font, 50);
        heading.setFillColor(sf::Color::White);
        heading.setPosition(165, 50);
        
        window.draw(heading);
        button1.drawTo(window);
        button2.drawTo(window);
        button3.drawTo(window);
        button4.drawTo(window);
        window.display();
    }
}
