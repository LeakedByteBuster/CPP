NAME = FixedPoint

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra

STD = -std=c++98

DEPS_FLAGS = -MMD -MP

SRC =	main.cpp \
		Fixed.cpp

OBJ_DIR = obj

OBJS = $(patsubst %, $(OBJ_DIR)/%, $(SRC:.cpp=.o))

DEPS = $(OBJS:%.o=%.d)

INC_HEADERS = -I. -Iutils

RM = rm -rf

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o : %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(STD) $(CXXFLAGS) $(DEPS_FLAGS) $(INC_HEADERS) -c $< -o $@

clean :
	$(RM) $(OBJ_DIR)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : re fclean clean all

-include $(DEPS)