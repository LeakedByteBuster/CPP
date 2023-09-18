# NOTE: "make re" is needed for the first compilation 
#			(in case of using a different flag for BUILD variable)
# Compilation
# -----------
#	make
#
# make re BUILD=...
# -----------------
#	nothing		: Removes messages printed by Animals
#	assign		: Tests copy constructor and copy assignement operator
#	assignLeaks	: Tests leaks
#	tests		: Activate test part [Allocationg and dealocating inside a loop]
#	leaks		: Calls 'leaks' command using atexit(3) on normal classes
#	build		: Shows constructors messages and one basic test
#	wrong		: Use wrongClasses
#	buildwrong	: Shows constructors messages from wrongClasses
#	wrongLeaks	: Calls 'leaks' command using atexit(3) on wrong classes
#	sanitize	: add sanitizer flag to the compilation
#	nothing		: shows nothing on output

NAME = zoo

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra

ifeq ($(BUILD), tests)
	CXXFLAGS+=-DTESTS
else ifeq ($(BUILD), leaks)
	CXXFLAGS+=-DTEST_LEAKS -DTESTS
#----------------------------------
else ifeq ($(BUILD), build)
	CXXFLAGS+=-DCONSTROCTURS_MSG -DSTOP_SIMULATION
#----------------------------------
else ifeq ($(BUILD), assign)
	CXXFLAGS+=-DASSIGN -DTESTS
else ifeq ($(BUILD), assignLeaks)
	CXXFLAGS+=-DASSIGN -DTEST_LEAKS
else ifeq ($(BUILD), assignBuild)
	CXXFLAGS+=-DASSIGN -DCONSTROCTURS_MSG -DSTOP_SIMULATION
#----------------------------------
else ifeq ($(BUILD), wrong)
	CXXFLAGS+=-DWRONG_CLASSES
else ifeq ($(BUILD), buildWrong)
	CXXFLAGS+=-DWRONG_CLASSES -DSTOP_SIMULATION -DCONSTROCTURS_MSG
else ifeq ($(BUILD), wrongLeaks)
	CXXFLAGS+=-DTEST_LEAKS -DTESTS -DWRONG_CLASSES
#----------------------------------
else ifeq ($(BUILD), sanitize)
	CXXFLAGS+=-fsanitize=address
#----------------------------------
else ifeq ($(BUILD), nothing)
	CXXFLAGS+=-DSTOP_SIMULATION
endif

STD = -std=c++98

DEPS_FLAGS = -MMD

SRC 	=	src/main.cpp \
			src/Dog.cpp \
			src/Cat.cpp \
			src/Animal.cpp \
			src/Brain.cpp

OBJ_DIR = obj

OBJS = $(patsubst %, $(OBJ_DIR)/%, $(SRC:.cpp=.o))

DEPS = $(OBJS:%.o=%.d)

INC_HEADERS = -Iinclude

RM = rm -rf

HBLU = "\e[1;94m"
HWHT = "\e[1;97m"
NC ='\033[0m'

all : $(NAME)

$(NAME) : $(OBJS)
	@ printf $(HBLU)
	@ printf "==> "
	@ printf $(HWHT)
	$(CXX) $(STD) $(CXXFLAGS) $(INC_HEADERS) $(OBJS) -o $(NAME)
	@ printf $(NC)

$(OBJ_DIR)/%.o : %.cpp
	@ mkdir -p $(@D)
	@ printf $(HBLU)
	@ printf "==> " 
	@ printf $(HWHT)
	$(CXX) $(STD) $(CXXFLAGS) $(DEPS_FLAGS) $(INC_HEADERS) -c $< -o $@
	@ printf $(NC)

clean :
	@ $(RM) $(OBJ_DIR)

fclean : clean
	@ $(RM) $(NAME)

re : fclean all

.PHONY : re fclean clean all

# .SILENT : all clean fclean re

-include $(DEPS)
