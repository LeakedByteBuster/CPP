NAME = megaphone

CXX = c++

CXXFLAGS = -std=c++98 -Wall -Werror -Wextra -MMD -MP

SRC = megaphone.cpp

OBJ_DIR = obj

OBJS = $(patsubst %, $(OBJ_DIR)/%, $(SRC:.cpp=.o))

DEPS = $(OBJS:%.o=%.d)

RM = rm -rf

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

obj/%.o : %.cpp
	@ mkdir -p obj
	@ printf $(HYEL)"Compiling %s\r"$(NC) $(notdir $<)
	@ $(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ_DIR)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : re fclean clean all

.SILENT : all clean fclean re $(NAME)

-include $(DEPS)