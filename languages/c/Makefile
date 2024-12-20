# compiler and flags
CC = gcc
CFLAGS =
LDFLAGS =
# no flags...

# directories
SRC_DIR = src
BUILD_DIR = build

# source code
SRCS = notes.c $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:%.c=$(BUILD_DIR)/%.o)

# binary
TARGET = notes

# default target
all: $(BUILD_DIR) $(TARGET)

# create build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)/$(SRC_DIR)

# link object files
$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $@

# create object files
$(BUILD_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# clean build artifacts
.PHONY: clean
clean:
	rm -f $(TARGET)
	rm -rf $(BUILD_DIR)