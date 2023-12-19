NAME = array

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra

STD = -std=c++98

INCLUDE = -Iinclude

SRC = $(shell find . -type f -name "*.cpp")

OBJ_DIR = obj

OBJ = $(patsubst ./%, $(OBJ_DIR)/%, $(SRC:.cpp=.o))

RM = rm -rf

DEPS = $(patsubst %.o, %.d, $(OBJ))

HBLU = "\e[1;91m"
HWHT = "\e[1;97m"
NC ='\033[0m'

ifeq ($(build), leaks)
	CXXFLAGS += -DLEAKS
else ifeq ($(build), double)
	CXXFLAGS += -DDOUBLE
else ifeq ($(build), string)
	CXXFLAGS += -DSTRING
else ifeq ($(build), char)
	CXXFLAGS += -DCHAR
else ifeq ($(build), out)
	CXXFLAGS += -DOUT_RANGE
endif

all : $(NAME)

$(NAME) : $(OBJ)
	@ $(CXX) $(STD) $(CXXFLAGS) $(INCLUDE) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o : %.cpp
	@ mkdir -p $(dir $@) && printf $(HBLU)"[+] "$(HWHT)
	$(CXX) $(STD) $(CXXFLAGS) $(INCLUDE) -MMD -c $< -o $@
	@ printf $(NC)
# @ printf $(HRED)"[+]"$(HWHT)" COMPILING"$(HRED)" ⤐  "$(HWHT)"%s\n"$(NC) $(notdir $<)

clean :
	@ $(RM) $(OBJ_DIR)

fclean : clean
	@ $(RM) $(NAME)

re : fclean all

-include $(DEPS)