#variables declaration
CXX= g++
GO= go
C_DIR= mkdir
ECHO= echo
OBJ_EXT= o
SRC_EXT= cpp
GO_EXT= go

#directories declaration
ROOT_DIR=.
OBJ_DIR= $(ROOT_DIR)/obj
BUILD_DIR= $(ROOT_DIR)/build
BIN_DIR= /usr/bin

#main directories declaration
MAIN_DIR= $(ROOT_DIR)/c++
MAIN_SRC_DIR= $(MAIN_DIR)/src
MAIN_INC_DIR= $(MAIN_DIR)/include
MAIN_OBJ_DIR= $(OBJ_DIR)/c++

#go directories declaration
GO_DIR= $(ROOT_DIR)/go
GO_INC_DIR= $(GO_DIR)/include
GO_SRC_DIR= $(GO_DIR)/src

#go files finder
GO_SRC_FILES= $(shell find $(GO_SRC_DIR) -maxdepth 1 -type f -name *.$(GO_EXT))
GO_SO_NAME= go.so
GO_SO= $(GO_INC_DIR)/$(GO_SO_NAME)

#output file declaration
BUILD_FILE_NAME= PFramework
BUILD_FILE= $(BUILD_DIR)/$(BUILD_FILE_NAME)

#main files finder
MAIN_SRC_FILES=  $(shell find $(MAIN_SRC_DIR) -maxdepth 1 -type f -name *.$(SRC_EXT))
MAIN_OBJ_FILES= $(patsubst $(MAIN_SRC_DIR)/%.$(SRC_EXT), $(MAIN_OBJ_DIR)/%.$(OBJ_EXT), $(MAIN_SRC_FILES))

#scripts directories declaration
SCRIPTS_DIR= $(ROOT_DIR)/scripts/c++
SCRIPTS_OBJ_DIR= $(OBJ_DIR)/scripts/c++
SCRIPTS_SRC_DIR= $(SCRIPTS_DIR)/src
SCRIPTS_INC_DIR= $(SCRIPTS_DIR)/include

#scripts files finder
SCRIPTS_SRC_FILES= $(shell find $(SCRIPTS_SRC_DIR) -maxdepth 1 -type f -name *.$(SRC_EXT))
SCRIPTS_OBJ_FILES= $(patsubst $(SCRIPTS_SRC_DIR)/%.$(SRC_EXT), $(SCRIPTS_OBJ_DIR)/%.$(OBJ_EXT), $(SCRIPTS_SRC_FILES))

#compilation variables
COMP_FLAGS= -I$(SCRIPTS_INC_DIR) -I$(MAIN_INC_DIR) -I$(GO_INC_DIR)

######################################################################################################

#the main target
all: $(BUILD_FILE)

#building the executable
$(BUILD_FILE): $(GO_SO) $(SCRIPTS_OBJ_FILES) $(MAIN_OBJ_FILES)
	$(C_DIR) -p $(BUILD_DIR)
	cp $(GO_SO) $(GO_SO_NAME)
	$(CXX) -o $(BUILD_FILE) $(SCRIPTS_OBJ_FILES) $(MAIN_OBJ_FILES) ./$(GO_SO_NAME)
	cp $(GO_SO) $(BUILD_DIR)/$(GO_SO_NAME)

#build go.so file
$(GO_SO): $(GO_SRC_FILES)
	$(C_DIR) -p $(GO_INC_DIR)
	$(GO) build -o $(GO_SO) -buildmode=c-shared $(GO_SRC_FILES)	

#building the scripts objects files
$(SCRIPTS_OBJ_FILES): $(SCRIPTS_OBJ_DIR)/%.$(OBJ_EXT): $(SCRIPTS_SRC_DIR)/%.$(SRC_EXT)
	$(C_DIR) -p $(OBJ_DIR)
	$(C_DIR) -p $(SCRIPTS_OBJ_DIR)	
	$(CXX) -c -o $@ $< $(COMP_FLAGS)

#building the main objects files
$(MAIN_OBJ_FILES): $(MAIN_OBJ_DIR)/%.$(OBJ_EXT): $(MAIN_SRC_DIR)/%.$(SRC_EXT)
	$(C_DIR) -p $(OBJ_DIR)
	$(C_DIR) -p $(MAIN_OBJ_DIR)
	$(CXX) -c -o $@ $< $(COMP_FLAGS)

#clean all
clean: cleango cleanobj
	rm -r -f $(BUILD_DIR)

#cleaning go.so
cleango:
	rm -f $(GO_SO_NAME) $(GO_INC_DIR)/$(GO_SO_NAME)

#cleaning only objects
cleanobj:
	rm -r -f $(OBJ_DIR)

#install the output file
install: all
	cp $(BUILD_FILE) $(BIN_DIR)/$(BUILD_FILE_NAME)
	cp $(BUILD_DIR)/$(GO_SO_NAME) $(BIN_DIR)/$(GO_SO_NAME)	

#uninstall the program
uninstall: 
	rm -f $(BIN_DIR)/$(BUILD_FILE_NAME)
	rm -f $(BIN_DIR)/$(GO_SO_NAME)
