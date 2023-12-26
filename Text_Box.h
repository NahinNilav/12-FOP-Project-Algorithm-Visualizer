#include "Terminal-UI.h"
#include "UI.h"
#include <bits/stdc++.h>

void displayInputWindowSorting(sf::RenderWindow &window, sf::Font &font, int &arraySize, std::vector<int> &elements){

    int inputting2 = true;

    sf::Text prompt("Enter array size(Maximum 1000):", font, 20);
    prompt.setPosition(50, 70);
    prompt.setFillColor(sf::Color::White);

    sf::Text inputText("", font, 20);
    inputText.setPosition(50, 100);
    inputText.setFillColor(sf::Color::Green);

    bool inputting = true;
    while (inputting && inputting2){

        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                inputting2 = false;
                window.close();
            }

            else if (event.type == sf::Event::TextEntered){

                if (event.text.unicode >= 32 && event.text.unicode <= 126){
                    char character = static_cast<char>(event.text.unicode);
                    if (event.text.unicode == 32){
                        character = '_';
                    }
                    inputText.setString(inputText.getString() + character);
                }
                else if (event.text.unicode == 8 && inputText.getString().getSize() > 0){
                    inputText.setString(inputText.getString().substring(0, inputText.getString().getSize() - 1));
                }
                else if (event.text.unicode == 13){
                    arraySize = std::stoi(inputText.getString().toAnsiString());
                    inputting = false;
                }
            }
        }

        window.clear();
        window.draw(prompt);
        window.draw(inputText);
        window.display();
    }

    if (inputting2 == false)
        return;

    // Get elements
    elements.clear();
    elements.reserve(arraySize);

    std::string new_string = "Enter ";
    new_string += std::to_string(arraySize);
    new_string += " elements of the array (space-separated unsigned integers less than 10000)";
    prompt.setString(new_string);
    prompt.setPosition(50, 150);

    inputText.setPosition(50, 180);
    inputText.setString("");

    inputting = true;
    while (inputting && inputting2){

        sf::Event event;
        while (window.pollEvent(event)){

            if (event.type == sf::Event::Closed){
                inputting2 = false;
                window.close();
            }
            else if (event.type == sf::Event::TextEntered){
                if (event.text.unicode == 8){
                    // Backspace key
                    if (!inputText.getString().isEmpty()){
                        // Remove the last character
                        inputText.setString(inputText.getString().substring(0, inputText.getString().getSize() - 1));
                    }
                }
                else if ((event.text.unicode >= 48 && event.text.unicode <= 57) || event.text.unicode == 32){
                    char character = static_cast<char>(event.text.unicode);
                    if (event.text.unicode == 32)
                        character = '_';

                    inputText.setString(inputText.getString() + character);
                }
                else if (event.text.unicode == 13){
                    std::string temp = inputText.getString().toAnsiString();
                    std::replace(temp.begin(), temp.end(), '_', ' ');

                    std::istringstream iss(temp);
                    int element;
                    while (iss >> element){
                        elements.push_back(element);
                    }
                    inputting = false;
                }
            }
        }

        if (inputting2 == false)
            return;

        window.clear();
        window.draw(prompt);
        window.draw(inputText);
        window.display();
    }
}


void displayInputWindowSearching(sf::RenderWindow &window, sf::Font &font, int &arraySize, std::vector<int> &elements, int &targetBinarySearch){

    int inputting2 = true;
    // Get size
    sf::Text prompt("Enter array size(Maximum 1000):", font, 20);
    prompt.setPosition(50, 70);
    prompt.setFillColor(sf::Color::White);

    sf::Text inputText("", font, 20);
    inputText.setPosition(50, 100);
    inputText.setFillColor(sf::Color::Green);

    bool inputting = true;
    while (inputting && inputting2){

        sf::Event event;
        while (window.pollEvent(event)){

            if (event.type == sf::Event::Closed){
                inputting2 = false;
                window.close();
            }

            else if (event.type == sf::Event::TextEntered){
                if (event.text.unicode >= 32 && event.text.unicode <= 126){
                    char character = static_cast<char>(event.text.unicode);
                    if (event.text.unicode == 32)
                        character = '_';

                    inputText.setString(inputText.getString() + character);
                }
                else if (event.text.unicode == 8 && inputText.getString().getSize() > 0){
                    inputText.setString(inputText.getString().substring(0, inputText.getString().getSize() - 1));
                }
                else if (event.text.unicode == 13){
                    arraySize = std::stoi(inputText.getString().toAnsiString());
                    inputting = false;
                }
            }
        }

        window.clear();
        window.draw(prompt);
        window.draw(inputText);
        window.display();

    }

    if (inputting2 == false)
        return;

    elements.clear();
    elements.reserve(arraySize);

    std::string new_string = "Enter ";
    new_string += std::to_string(arraySize);
    new_string += " elements of the array (space-separated unsigned integers less than 10000)";
    prompt.setString(new_string);
    prompt.setPosition(50, 150);

    inputText.setPosition(50, 180);
    inputText.setString("");

    inputting = true;
    while (inputting && inputting2){

        sf::Event event;
        while (window.pollEvent(event)){

            if (event.type == sf::Event::Closed){
                inputting2 = false;
                window.close();
            }

            else if (event.type == sf::Event::TextEntered){
                if (event.text.unicode == 8){
                    if (!inputText.getString().isEmpty()){
                        inputText.setString(inputText.getString().substring(0, inputText.getString().getSize() - 1));
                    }
                }
                else if ((event.text.unicode >= 48 && event.text.unicode <= 57) || event.text.unicode == 32){
                    char character = static_cast<char>(event.text.unicode);
                    if (event.text.unicode == 32)
                        character = '_';

                    inputText.setString(inputText.getString() + character);
                }
                else if (event.text.unicode == 13){
                    std::string temp = inputText.getString().toAnsiString();
                    std::replace(temp.begin(), temp.end(), '_', ' ');

                    std::istringstream iss(temp);
                    int element;
                    while (iss >> element)
                    {
                        elements.push_back(element);
                    }
                    inputting = false;
                }
            }
        }

        window.clear();
        window.draw(prompt);
        window.draw(inputText);
        window.display();
    }

    if (inputting2 == false)
        return;

    sf::Text targetPrompt("Enter target element for Binary Search:", font, 20);
    targetPrompt.setPosition(50, 280);
    targetPrompt.setFillColor(sf::Color::White);
    inputText.setPosition(50, 310);
    inputText.setString("");

    inputting = true;
    while (inputting && inputting2){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                inputting2 = false;
                window.close();
            }

            else if (event.type == sf::Event::TextEntered){
                if (event.text.unicode == 8){
                    if (!inputText.getString().isEmpty()){
                        inputText.setString(inputText.getString().substring(0, inputText.getString().getSize() - 1));
                    }
                }

                else if ((event.text.unicode >= 48 && event.text.unicode <= 57) || event.text.unicode == 32){
                    char character = static_cast<char>(event.text.unicode);
                    if (event.text.unicode == 32)
                        character = '_';

                    inputText.setString(inputText.getString() + character);
                }
                else if (event.text.unicode == 13){
                    int targetElement = std::stoi(inputText.getString().toAnsiString());
                    targetBinarySearch = targetElement;
                    inputting = false;
                }
            }
        }

        window.clear();
        window.draw(targetPrompt);
        window.draw(inputText);
        window.display();
    }

    if (inputting2 == false)
        return;
}


void show_box(int algorithm, int mode){

    int arraySize = -1;
    std::vector<int> elements;
    int targetBinarySearch = -1;
    if (algorithm != 4 && mode == 1){
        PrintTerminalUI(algorithm, mode, arraySize, elements, targetBinarySearch);
        return;
    }

    sf::RenderWindow window(sf::VideoMode(1000,500), "Input Window");
    window.setPosition(sf::Vector2i(sf::VideoMode::getDesktopMode().width * 0.5 - window.getSize().x * 0.5, sf::VideoMode::getDesktopMode().height * 0.5 - window.getSize().y * 0.5));
    sf::Font font;
    if (!font.loadFromFile("ClashGrotesk-Bold.otf")){
        std::cerr << "Error loading font!" << std::endl;
        return;
    }

    if (algorithm == 4)
        displayInputWindowSearching(window, font, arraySize, elements, targetBinarySearch);

    else
        displayInputWindowSorting(window, font, arraySize, elements);
    if (arraySize == -1 || elements.size() < arraySize){
        Graphical_UI();
        return;
    }
    
    window.close();
    PrintTerminalUI(algorithm, mode, arraySize, elements, targetBinarySearch);
}
