SFML_INCLUDE_PATH := "C:\SFML-2.6.0\include"
SFML_LINKAGE_PATH := "C:\SFML-2.6.0\lib"

SRCS := src/main.cpp src/File/File_Reader.cpp src/Game/Game.cpp src/Game/Menu/Menu.cpp
OBJS := $(SRCS:.cpp=.o)

CC := g++
CFLAGS := -c -I$(SFML_INCLUDE_PATH) -DSFML_STATIC

LDFLAGS := -L$(SFML_LINKAGE_PATH) -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lsfml-audio -lopengl32 -lfreetype -lwinmm -lgdi32 -mwindows

TARGET := GAME

$(TARGET): $(OBJS)
	$(CC) $(SRCS) $(CFLAGS) && $(CC) $(OBJS) -o $(TARGET) $(LDFLAGS) 

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	powershell -File clean.ps1

.PHONY: clean