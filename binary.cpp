#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <bits/stdc++.h>
#include "UI.h"

using namespace sf;
using namespace std;

void create_binary_window(int arraySize, std::vector<int> elements, int targetBinarySearch)
{
    const int windowWidth = VideoMode::getDesktopMode().width;
    const int windowHeight = VideoMode::getDesktopMode().height;
    int barWidth;

    RenderWindow window;
    vector<int> arrayData;
    int maximum = -1;
    int ans_ind;
    sf::Texture texture_binary;
    texture_binary.loadFromFile("Background_Image.jpg");
    sf::Sprite binary_sprite;
    binary_sprite.setTexture(texture_binary);
    binary_sprite.setScale(windowWidth / binary_sprite.getLocalBounds().width, windowHeight / binary_sprite.getLocalBounds().height);
    int n;
    n = arraySize;
    for (int i = 0; i < n; i++)
    {
        arrayData.push_back(elements[i]);
        if (elements[i] > maximum)
            maximum = elements[i];
    }
    barWidth = windowWidth / n;
    sort(arrayData.begin(),arrayData.end());
    int target;
    target = targetBinarySearch;
    int part = 1;
    int found = 0;
    sf::Clock clock;
    int idx = -1;
    int start = 0, end = arrayData.size() - 1;
    window.create(VideoMode(windowWidth, windowHeight), "Algorithm Visualizer - Binary Search");
    bool toggle=1;
    bool toggle_key=0;
    sf::Clock toggle_clock;
    sf::Font font;
    font.loadFromFile("ARIAL.ttf");
    sf::Text toggle_text;
    toggle_text.setFont(font);
    toggle_text.setString("Press P to Start/Pause the Searching");
    toggle_text.setPosition(windowWidth/2.8,1.f);
    toggle_text.setCharacterSize(30.f);
    toggle_text.setFillColor(Color::White);
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
        }
        window.draw(binary_sprite);
        window.draw(toggle_text);
        toggle_key=sf::Keyboard::isKeyPressed(sf::Keyboard::P);
        while(toggle_key&&toggle_clock.getElapsedTime()>sf::seconds(0.4f)){
            toggle=1-toggle;
            toggle_clock.restart();
        }
        if (clock.getElapsedTime() > seconds(2.f))
        {
            part = 2;
            clock.restart();
        }
        if (part == 1||toggle)
        {
            for (size_t i = 0; i < arrayData.size(); ++i)
            {
                float heights = (((float)(windowHeight - 150) / maximum) * (arrayData[i]));
                RectangleShape bar;
                bar.setSize(Vector2f(barWidth, heights));
                bar.setPosition((i + 1) * barWidth + i + 1, windowHeight - 80.f);
                bar.setRotation(180);

                if (i == idx && found == 0)
                {
                    bar.setFillColor(Color::Red);
                }
                else if (i == idx && found == 1)
                    bar.setFillColor(Color::White);
                else if (i == idx && found == 2)
                {
                    bar.setFillColor(Color::Blue);
                }
                else
                {
                    bar.setFillColor(Color::Green);
                }

                window.draw(bar);
            }
        }
        else
        {
            int mid = (start + end) / 2;
            if (start <= end)
                idx = mid;
            if (arrayData[mid] == target)
            {
                ans_ind = mid;
                found = 1;
                part = 1;
                continue;
            }
            if (start > end)
            {
                found = 2;
                part = 1;
                continue;
            }
            if (arrayData[mid] > target)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
            part = 1;
        }
        window.display();
        if (found == 2 || found == 1)
        {
            RenderWindow result;
            result.create(VideoMode(800, 600), "Result Message");
            result.setPosition(sf::Vector2i(sf::VideoMode::getDesktopMode().width * 0.5 - result.getSize().x * 0.5, sf::VideoMode::getDesktopMode().height * 0.5 - result.getSize().y * 0.5));
            sf::Text message;
            sf::Font font;
            font.loadFromFile("ARIAL.ttf");
            message.setFont(font);
            std::string success_message;
            success_message = "Element is found at index ";
            success_message += to_string(ans_ind + 1);
            if (found == 2)
                message.setString("Element not found");
            else
                message.setString(success_message);
            message.setCharacterSize(40.f);
            message.setFillColor(Color::White);
            if (found == 2)
                message.setPosition(200, 250);
            else
                message.setPosition(125, 250);
            while (result.isOpen())
            {
                Event event;
                while (result.pollEvent(event))
                {
                    if (event.type == Event::Closed)
                    {
                        result.close();
                    }
                }
                result.draw(message);
                result.display();
            }
            window.close();
        }
    }
    Graphical_UI();
}