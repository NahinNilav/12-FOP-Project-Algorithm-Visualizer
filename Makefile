#OBJS specifies which files to compile as part of the project
OBJS = main.cpp Terminal-UI.cpp Window_Sort.cpp algorithm_viewer.cpp bubble_sort.cpp insertion_sort.cpp selection_sort.cpp binary.cpp UI.cpp

#CC specifies which compiler we're using
CC = g++

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -w

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = main_app

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)