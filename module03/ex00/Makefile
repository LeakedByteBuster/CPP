# NOTE: "make re" is needed for the first compilation with a different flag
# Compilation
# -----------
#	make re		: shows fight messages
# make re BUILD=...
# -----------------
#	sanitize	: removes fight messages, and add sanitizer to compilation
#	stats		: show stats of the player
#	stop		: removes fight messages
#	onlyStats	: shows only stats of the begining and end of the game
#	debug		: removes fight messages, and activate debugging messages
#	third		: adds a third player to test copy constructor

NAME = ClapTrap

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra

ifeq ($(BUILD), sanitize)
	CXXFLAGS+=-fsanitize=address -DDEBUG -DNOT_SIMULATE
else ifeq ($(BUILD), stats)
	CXXFLAGS+=-DSTATS
else ifeq ($(BUILD), stop)
	CXXFLAGS+=-DNOT_SIMULATE
else ifeq ($(BUILD), onlyStats)
	CXXFLAGS+=-DNOT_SIMULATE -DSTATS
else ifeq ($(BUILD), debug)
	CXXFLAGS+=-DNOT_SIMULATE -DDEBUG
else ifeq ($(BUILD), debugAssign)
	CXXFLAGS+=-DTHIRD -DSTATS
endif

STD = -std=c++98

DEPS_FLAGS = -MMD -MP


SRC 	=	main.cpp \
			ClapTrap.cpp

OBJ_DIR = obj

OBJS = $(patsubst %, $(OBJ_DIR)/%, $(SRC:.cpp=.o))

DEPS = $(OBJS:%.o=%.d)

INC_HEADERS = -I.

RM = rm -rf

QUIT = @

HBLK = '\e[1;90m'
HRED = '\e[1;91m'
HGRN = '\e[1;92m'
HYEL = '\e[1;93m'
HBLU = '\e[1;94m'
HMAG = '\e[1;95m'
HCYN = '\e[1;96m'
HWHT = '\e[1;97m'
NC ='\033[0m'

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o : %.cpp
	@ mkdir -p $(dir $@)
	$(CXX) $(STD) $(CXXFLAGS) $(DEPS_FLAGS) $(INC_HEADERS) -c $< -o $@

clean :
	$(RM) $(OBJ_DIR)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : re fclean clean all

# .SILENT : all clean fclean re $(NAME)

-include $(DEPS)
