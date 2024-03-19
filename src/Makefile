# Makefile  C

# Directories
SRC_DIR = c
INC_DIR = -Ih
LIB_DIR = -lpthread
BUILD_DIR = ../build
DIST_DIR = ../dist
PROJECT_NAME = OronetaCoreServer

# Source code and object
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

# Name of project
TARGET = $(DIST_DIR)/$(PROJECT_NAME)

# Compiler and options flag "no warning"
CC = g++
CFLAGS = $(INC_DIR) $(LIB_DIR)

# Main executable program
all: $(TARGET)

# g++ --all
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

# g++ --code
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CC) -c $< -o $@ $(CFLAGS)

# Regla para limpiar
clean:
	rm -rf $(BUILD_DIR)/*.o $(TARGET) ../dist/*.tgz ../dist/*.tar