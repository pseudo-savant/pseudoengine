OBJS = main.cpp

CC = g++

COMPILER_FLAGS = -w 

ENG_LIB_PATH = C:/Libraries

LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2

OBJ_NAME = lolo

asbd:
	$(CC) $(OBJS) -I$(ENG_LIB_PATH)/include/SDL2 -L$(ENG_LIB_PATH)/lib  $(LINKER_FLAGS) -o $(OBJ_NAME)