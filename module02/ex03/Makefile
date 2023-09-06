#	Build:
#	------
#		Compilation :
#		-------------
#		make BUILD=ndebug		|| not showing messages from methods
#		make BUILD=test			|| shows only true test cases
#		make BUILD=false_cases	|| shows both false and true test cases


NAME = bsp

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra

STD = -std=c++98

DEPS_FLAGS = -MMD -MP

SRC =	main.cpp \
		Fixed.cpp \
		Point.cpp \
		bsp.cpp

OBJ_DIR = obj

OBJS = $(patsubst %, $(OBJ_DIR)/%, $(SRC:.cpp=.o))

DEPS = $(OBJS:%.o=%.d)

INC_HEADERS = -I. -Iutils

RM = rm -rf

ifeq ($(BUILD), ndebug)
	CXXFLAGS += -DNDEBUG
else ifeq ($(BUILD), test)
	CXXFLAGS +=-DNDEBUG -DTEST_CASES
else ifeq ($(BUILD), false_cases)
	CXXFLAGS+=-DNDEBUG -DTEST_CASES -DSHOW_FALSE_CASES
else 
	
endif

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