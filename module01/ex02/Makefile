NAME = ThisIsBrain

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra

STD = -std=c++98

DEPS_FLAGS = -MMD -MP

SRC =	main.cpp \

OBJ_DIR = obj

OBJS = $(patsubst %, $(OBJ_DIR)/%, $(SRC:.cpp=.o))

DEPS = $(OBJS:%.o=%.d)

INC_HEADERS = -I. -Iutils

RM = rm -rf

# TMP = ===========

# EQ = ===========

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
	mkdir -p $(dir $@)
# @ printf $(HWHT)"[* Compiling  "$(NC)
# @ printf $(HGRN)"%s"$(NC) $(TMP)
# $(eval TMP += $(EQ))
# @ printf $(HGRN)">" $(NC)
# @ printf "\r"$(NC)
	$(CXX) $(STD) $(CXXFLAGS) $(DEPS_FLAGS) $(INC_HEADERS) -c $< -o $@

clean :
	$(RM) $(OBJ_DIR)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : re fclean clean all

# .SILENT : all clean fclean re $(NAME)

-include $(DEPS)