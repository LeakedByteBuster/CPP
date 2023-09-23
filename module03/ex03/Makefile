# NOTE: "make re" is needed for the first compilation 
#			(in case of using a different flag for BUILD variable)
# Compilation
# -----------
#	make re		: shows fight messages
#
# make re BUILD=...
# -----------------
#	sanitize	: removes fight messages, and add sanitizer to compilation
#	stats		: show stats of the player and fight messages
#	nothing		: print an empty line in output
#	onlyStats	: shows only stats of the begining and end
#	debug		: removes fight messages, and activate debugging messages
#	debugAssign	: same as "debug" but, it tests copy constructor
#	energy		: sets energyPoints points of of all robots to 0
#	health		: sets hitPoints points of of all robots to 0

NAME = Diamond

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra

ifeq ($(BUILD), sanitize)
	CXXFLAGS+=-fsanitize=address -DDEBUG -DNOT_SIMULATE 
else ifeq ($(BUILD), stats)
	CXXFLAGS+=-DSTATS
else ifeq ($(BUILD), health)
	CXXFLAGS+=-DSTATS -DTEST_HEALTH
else ifeq ($(BUILD), energy)
	CXXFLAGS+=-DSTATS -DTEST_ENERGY
else ifeq ($(BUILD), nothing)
	CXXFLAGS+=-DNOT_SIMULATE
else ifeq ($(BUILD), onlyStats)
	CXXFLAGS+=-DNOT_SIMULATE -DSTATS
else ifeq ($(BUILD), debug)
	CXXFLAGS+=-DNOT_SIMULATE -DDEBUG
else ifeq ($(BUILD), debugAssign)
	CXXFLAGS+=-DNOT_SIMULATE -DDEBUG -DASSIGN -DSTATS
endif

STD = -std=c++98

DEPS_FLAGS = -MMD

SRC 	=	main.cpp \
			robotsMethods/ClapTrap.cpp \
			robotsMethods/ScavTrap.cpp \
			robotsMethods/FragTrap.cpp \
			DiamondTrap.cpp

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
