#include "selection_sort.h"
#include "UI.h"
int pos1=-1,pos2=-1;
void selection_sort(int heights[], int upper_loop_bound, int size_of_array)
{
    int curr = heights[upper_loop_bound];
    int index = upper_loop_bound;
    for (int i = upper_loop_bound; i < size_of_array; i++)
    {
        if (heights[i] < curr)
        {
            curr = heights[i];
            index = i;
        }
    }
    if(heights[upper_loop_bound]>heights[index]){
        pos1=upper_loop_bound;
        pos2=index;
    }
    else{
        pos1=-1;
        pos2=-1;
    }
}
void start_selection_sort()
{
    bool toggle=false;
    bool toggle_key_pressed = false;
    sf::Clock toggle_clock;
    sf::Clock clock;
    while (new_window.isOpen())
    {

        Event event;
        while (new_window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                new_window.close();
            }
        }
        Sort_Key_Pressed = Keyboard::isKeyPressed(Keyboard::S);
        toggle_key_pressed = Keyboard::isKeyPressed(Keyboard::P);
        if(toggle_key_pressed&&toggle_clock.getElapsedTime()>seconds(0.4f)&&once_pressed_sort_key){
            if(toggle==true)toggle=false;
            else toggle=true;
            toggle_key_pressed=false;
            toggle_clock.restart();
        }
        if (Sort_Key_Pressed)
        {
            once_pressed_sort_key = true;
            is_sorted = false;
            upper_loop_bound = 1;
        }
        new_window.clear(Color::White);
        new_window.draw(background_sprite);
        new_window.draw(Sorting_Text);
        new_window.draw(Shuffle_Text);
        new_window.draw(Toggle_Text);
        Shuffle_key_pressed = Keyboard::isKeyPressed(Keyboard::R);
        if (Shuffle_key_pressed)
        {
            create_window();
            return;
        }
        if ((part == 1) || (is_sorted))
        {
            for (int i = 0; i < set_size; i++)
            {
                rectangle_array[i].setSize(Vector2f(width_of_rectangle, heights[i]));
                rectangle_array[i].setPosition(position_of_rectangle, screen_height-80.f);
                rectangle_array[i].setRotation(180);
                rectangle_array[i].setFillColor(get_colour_by_length(heights[i],rectange_colour));
                new_window.draw(rectangle_array[i]);
                position_of_rectangle += width_of_rectangle + 1;
            }
            // time_delay++;
            position_of_rectangle = width_of_rectangle+1;
            if (!Sort_Key_Pressed && !once_pressed_sort_key)
            {
                clock.restart();
                goto here;
            }
            if (clock.getElapsedTime() >= standard_delay)
            {
                part = 2;
                clock.restart();
            }
        }
        else if (part == 2 && !is_sorted && once_pressed_sort_key)
        {
            for (int i = 0; i < set_size; i++)
            {
                rectangle_array[i].setSize(Vector2f(width_of_rectangle, heights[i]));
                rectangle_array[i].setPosition(position_of_rectangle, screen_height-80.f);
                rectangle_array[i].setRotation(180);
                if(i==pos1||i==pos2)rectangle_array[i].setFillColor(Color::White);
                else rectangle_array[i].setFillColor(get_colour_by_length(heights[i],rectange_colour));
                new_window.draw(rectangle_array[i]);
                position_of_rectangle += width_of_rectangle + 1;
            }
            position_of_rectangle = width_of_rectangle+1;
            RectangleShape iterator;
            iterator.setSize(Vector2f(width_of_rectangle / 6, heights[it_pos]));
            iterator.setPosition(position_of_iterator, screen_height-80.f);
            iterator.setRotation(180);
            iterator.setFillColor(iterator_colour);
            if(pos1!=-1){
                while(clock.getElapsedTime()<=(3.f*standard_delay)){
                    goto here;
                }
                clock.restart();
                int temp=heights[pos1];
                heights[pos1]=heights[pos2];
                heights[pos2]=temp;
                pos1=-1;
                pos2=-1;
            }
            new_window.draw(iterator);
            if(toggle){
                clock.restart();
                goto here;
            }
            if (clock.getElapsedTime() >= standard_delay)
            {
                clock.restart();
                position_of_iterator += width_of_rectangle + 1;
                it_pos++;
            }
            if (it_pos >= set_size)
            {
                part = 3;
                selection_start++;
                it_pos = selection_start;
                position_of_iterator = 1.f + ((width_of_rectangle + 1.f) * (it_pos + 1) - width_of_rectangle / 2);
            }
        }
        else if (part == 3 && !is_sorted && once_pressed_sort_key)
        {
            bool invertions = false;
            for (int j = 1; j < set_size; j++)
            {
                if (heights[j] < heights[j - 1])
                {
                    invertions = true;
                }
            }
            if (!invertions)
                is_sorted = true;
            selection_sort(heights, upper_loop_bound - 1, set_size);
            part = 1;
            upper_loop_bound++;
            if (upper_loop_bound >= set_size)
            {
                is_sorted = true;
            }
            if (is_sorted)
            {
                selection_start = 0;
                it_pos = 0;
            }
        }
    here:
        new_window.display();
    }
    Graphical_UI();
}