BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src
INCLUDE_DIR = include

EXEC = $(BIN_DIR)/tp3.out
LINK = tp3.out

CC = g++
CFLAGS = -Wall -I$(INCLUDE_DIR)

SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCES))

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CC) $^ -pg -g -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -pg -g -c $< -o $@

.PHONY: clean
clean:
	rm -f $(EXEC) $(OBJECTS)
