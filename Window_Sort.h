#include "Terminal-UI.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <bits/stdc++.h>

using namespace sf;
extern RenderWindow new_window;
extern RectangleShape rectangle_array[1001];
extern int heights[1001];
extern int width_of_rectangle;
extern int maxo;
extern std::string Title;
extern Font font;
extern Text Sorting_Text,Shuffle_Text,Toggle_Text;
extern float position_of_rectangle;
extern int part;
extern int upper_loop_bound;
extern bool is_sorted;
extern bool once_pressed_sort_key;
extern bool Sort_Key_Pressed;
extern bool Shuffle_key_pressed;
extern int it_pos;
extern float position_of_iterator;
extern int insertion_bound;
extern int selection_start;
extern int bubble_upper;
extern sf::Time standard_delay;
extern Color rectange_colour,iterator_colour;
extern sf::Sprite background_sprite;
void create_window();