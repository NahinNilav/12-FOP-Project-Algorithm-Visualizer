#include "algorithm_viewer.h"
#include "Window_Sort.h"
#include "insertion_sort.h"
#include "selection_sort.h"
#include "bubble_sort.h"


sf::Color get_colour_by_length(int length,sf::Color background_colour){
    sf::Color colour={0,255,0};
    return colour;
}


void start_sort(){

    if(selector==1){
        start_bubble_sort();
    }
    else if(selector==2){
        start_insertion_sort();
    }
    else if(selector==3){
        start_selection_sort();
    }
    
}