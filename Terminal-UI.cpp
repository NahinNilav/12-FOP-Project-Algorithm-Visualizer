#include "Window_Sort.h"
#include "Terminal-UI.h"
#include "binary.h"

#include <bits/stdc++.h>
int selector;
int set_size;
int selector2;
int arr[1001];
int screen_height;
int screen_width;
int target;
void PrintTerminalUI(int value1,int value2,int arraySize,std::vector<int>elements,int targetBinarySearch)
{
    screen_width = VideoMode::getDesktopMode().width;
    screen_height = VideoMode::getDesktopMode().height;
    selector=value1;
    if (selector == 4)
    {
        create_binary_window(arraySize,elements,targetBinarySearch);
        return;
    }
    selector2=value2;
    if (selector2 == 2)
    {
        set_size=arraySize;
        for(int i=0;i<arraySize;i++){
            arr[i]=elements[i];
        }
    }
    else
    {
        set_size = screen_width / 65;
    }
    create_window();
}