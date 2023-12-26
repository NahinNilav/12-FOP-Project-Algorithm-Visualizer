#include "Window_Sort.h"
#include "algorithm_viewer.h"
RectangleShape rectangle_array[1001];
int heights[1001];
int maxo;
int width_of_rectangle;
std::string Title;
RenderWindow new_window;
Font font;
Text Sorting_Text, Shuffle_Text,Toggle_Text;
float position_of_rectangle;
int part;
int upper_loop_bound;
bool is_sorted;
bool once_pressed_sort_key;
bool Sort_Key_Pressed;
bool Shuffle_key_pressed;
int it_pos = 0;
int insertion_bound;
int selection_start;
int bubble_upper;
float position_of_iterator;
sf::Time standard_delay;
Color rectange_colour, iterator_colour;
int max_value, min_value;
sf::Sprite background_sprite;
void create_window()
{
    rectange_colour = {0, 0, 0};
    iterator_colour = {255, 0, 0};
    sf::Texture t;
    t.loadFromFile("Background_Image.jpg");
    background_sprite.setTexture(t);
    background_sprite.setScale(screen_width / background_sprite.getLocalBounds().width, screen_height / background_sprite.getLocalBounds().height);
    width_of_rectangle = ((screen_width - (set_size - 1)) / set_size);
    position_of_rectangle = width_of_rectangle+1;
    part = 1;
    upper_loop_bound = 1;
    is_sorted = false;
    once_pressed_sort_key = false;
    Sort_Key_Pressed = false;
    Shuffle_key_pressed = false;
    it_pos = 0;
    insertion_bound = 1;
    selection_start = 0;
    bubble_upper = set_size;
    position_of_iterator = width_of_rectangle / 2;
    standard_delay = sf::seconds(0.5f);
    Title = "Algorithm Visualizer";
    Title += (selector == 2) ? " - Insertion Sort" : (selector == 3) ? " - Selection Sort"
                                                                     : " - Bubble Sort";
    new_window.create(VideoMode(screen_width, screen_height), Title, Style::Default);
    srand(time(0));
    if (selector2 == 2)
    {
        maxo = arr[0];
        for (int i = 0; i < set_size; i++)
        {
            if (maxo < arr[i])
                maxo = arr[i];
        }
        for (int i = 0; i < set_size; i++)
        {
            heights[i] = ((float)arr[i] / maxo) * (screen_height - 200);
        }
    }
    else
    {
        for (int i = 0; i < set_size; i++)
        {
            heights[i] = rand() % (screen_height - 200);
        }
    }
    if (!font.loadFromFile("ARIAL.ttf"))
    {
        printf("Error Loading Font\n");
        return;
    }
    Sorting_Text.setFont(font);
    Sorting_Text.setString("Press S To Start The Sorting\n");
    Sorting_Text.setCharacterSize(20.f);
    Sorting_Text.setFillColor(Color::White);
    Sorting_Text.setPosition(screen_width / 2.4, 25.f);
    Shuffle_Text.setFont(font);
    if (selector2 == 2)
        Shuffle_Text.setString("Press R To Reset The Values\n");
    else
        Shuffle_Text.setString("Press R To Randomize The Values\n");
    Shuffle_Text.setCharacterSize(20.f);
    Shuffle_Text.setFillColor(Color::White);
    if (selector2 == 2)
        Shuffle_Text.setPosition(screen_width / 2.4, 1.f);
    else
        Shuffle_Text.setPosition(screen_width / 2.5, 1.f);
    Toggle_Text.setFont(font);
    Toggle_Text.setCharacterSize(20.f);
    Toggle_Text.setFillColor(Color::White);
    Toggle_Text.setString("Press P To Pause/Restart The Sorting\n");
    Toggle_Text.setPosition(screen_width / 2.6, 50.f);
    start_sort();
}