NAME = form

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -pedantic-errors -std=c++98
INCLUDE = -I .

SRC = main.cpp \
	  Form.cpp \
	  Bureaucrat.cpp \

OBJS = $(SRC:.cpp=.o)

RM = rm -f

.cpp.o:
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re