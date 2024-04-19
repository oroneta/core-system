# Makefile  C

# Directories
SRC_DIR = c
# INC_DIR = -Ih -I/usr/pgsql-14/include/ -I/usr/local/include/
# LINK_DIR = -L/usr/pgsql-14/lib/ -L/usr/local/lib/
INC_DIR = -Ih -I/usr/pgsql-14/include/ -I/usr/include/
LINK_DIR = -L/usr/pgsql-14/lib/ -L/usr/lib64/
LIB_DIR = -lpqxx -lpq -lpthread 
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
CFLAGS = $(INC_DIR) $(LINK_DIR) $(LIB_DIR)

# Main executable program
all: $(TARGET)

# g++ --all
$(TARGET): $(OBJS)
	@mkdir -p $(DIST_DIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

# g++ --code
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Regla para limpiar
clean:
	rm -rf $(BUILD_DIR)/*.o $(TARGET) ../dist/*.tgz ../dist/*.tar