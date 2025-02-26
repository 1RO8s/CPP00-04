NAME = whatever
SRCS = main.cpp
HEADERS = $(SRCS:.cpp=.hpp)
OBJS = $(SRCS:.cpp=.o)
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic-errors

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

fmt:
	clang-format -i $(SRCS) $(HEADERS)

.PHONY: all clean fclean re fmt 