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
			src/RobotomyRequestForm.cpp \
			src/ShrubberyCreationForm.cpp \
			src/PresidentialPardonForm.cpp \
			exceptionClasses/GradeTooLowException.cpp \
			exceptionClasses/GradeTooHighException.cpp \
			exceptionClasses/FormNotSigned.cpp

OBJ_DIR = obj

OBJS = $(patsubst %, $(OBJ_DIR)/%, $(SRC:.cpp=.o))

DEPS = $(OBJS:%.o=%.d)

INC_HEADERS = -I. -I./exceptionClasses -I./include

RM = rm -rf

HBLU = "\e[1;94m"
HWHT = "\e[1;97m"
NC ='\033[0m'

ifeq ($(BUILD), background)
	CXXFLAGS+=-DTREE_BACKGROUND
else ifeq ($(BUILD), debug)
	CXXFLAGS+=-DDEBUG
else ifeq ($(BUILD), assign)
	CXXFLAGS+=-DASSIGN
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
	@ $(RM) $(OBJ_DIR) *_shrubbery

fclean : clean
	@ $(RM) $(NAME)

re : fclean all

.PHONY : re fclean clean all

# .SILENT : all clean fclean re

-include $(DEPS)
