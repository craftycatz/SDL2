SRC_DIR = src
BUILD_DIR = build/debug
CC = clang
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_NAME = play
INCLUDE_PATHS = -Iinclude/SDL2 -Iinclude/SDL2_image
LIBRARY_PATHS = -Llib/SDL2 -Llib/SDL2_image
COMPILER_FLAGS = -std=c99 -Wall -O0 -g
LINKER_FLAGS = -lSDL2
all:
	$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(SRC_FILES) -o $(BUILD_DIR)/$(OBJ_NAME)

run:
	./$(BUILD_DIR)/$(OBJ_NAME)