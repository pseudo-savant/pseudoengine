OBJS = main.cpp
ENG_LIB_PATH = C:/Libraries
OBJ_NAME = lolo

asbd:
	g++ $(OBJS) -I$(ENG_LIB_PATH)/include/SDL2 -L$(ENG_LIB_PATH)/lib -lmingw32 -lSDL2main -lSDL2 -o $(OBJ_NAME)