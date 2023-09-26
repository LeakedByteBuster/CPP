# NOTE: "make re" is needed for the first compilation 
#			(in case of using a different flag for BUILD variable)
# Compilation
# -----------
#	make
#
# make re BUILD=...
# -----------------
#	background	: adds a backgournd for tree written by ShrubberyCreationForm
#	debug		: for debugging

NAME = bin/Bureaucrat

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra

STD = -std=c++98

DEPS_FLAGS = -MMD

SRC 	=	src/main.cpp \
			src/Bureaucrat.cpp \
			src/AForm.cpp \
			src/ShrubberyCreationForm.cpp \
			ExceptionClasses/GradeTooLowException.cpp \
			ExceptionClasses/GradeTooHighException.cpp

OBJ_DIR = obj

OBJS = $(patsubst %, $(OBJ_DIR)/%, $(SRC:.cpp=.o))

DEPS = $(OBJS:%.o=%.d)

INC_HEADERS = -I. -I./ExceptionClasses -I./include

RM = rm -rf

HBLU = "\e[1;94m"
HWHT = "\e[1;97m"
NC ='\033[0m'

ifeq ($(BUILD), background)
	CXXFLAGS+=-DTREE_BACKGROUND
else ifeq ($(BUILD), debug)
	CXXFLAGS+=-DDEBUG
endif

all : $(NAME)

$(NAME) : $(OBJS)
	@ mkdir -p bin
	@ printf $(HBLU)"[+] "$(HWHT)
	$(CXX) $(STD) $(CXXFLAGS) $(INC_HEADERS) $(OBJS) -o $(NAME)
	@ printf $(NC)

$(OBJ_DIR)/%.o : %.cpp
	@ mkdir -p $(dir $@) && printf $(HBLU)"[+] "$(HWHT)
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
