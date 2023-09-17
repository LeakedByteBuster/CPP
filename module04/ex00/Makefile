# NOTE: "make re" is needed for the first compilation 
#			(in case of using a different flag for BUILD variable)
# Compilation
# -----------
#	make
#
# make re BUILD=...
# -----------------
#	nothing		: removes messages printed by Animals
#	debug		: add sanitizer
#	assign		: tests copy constructor and copy assignement operator

NAME = zoo

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra

ifeq ($(BUILD), tests)
	CXXFLAGS+=-DTESTS
else ifeq ($(BUILD), build)
	CXXFLAGS+=-DCONSTROCTURS_MSG
else ifeq ($(BUILD), buildOnly)
	CXXFLAGS+=-DCONSTROCTURS_MSG -DSTOP_SIMULATION
else ifeq ($(BUILD), nothing)
	CXXFLAGS+=-DSTOP_SIMULATION
else ifeq ($(BUILD), leaks)
	CXXFLAGS+=-DTEST_LEAKS -DTESTS
else ifeq ($(BUILD), sanitize)
	CXXFLAGS+=-fsanitize=address
endif

STD = -std=c++98

DEPS_FLAGS = -MMD

SRC 	=	src/main.cpp \
			src/Dog.cpp \
			src/Cat.cpp \
			src/Animal.cpp

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
