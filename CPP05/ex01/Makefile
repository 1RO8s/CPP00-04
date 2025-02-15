NAME	= a.out
SRCS	= main.cpp \
		  Bureaucrat.cpp \
		  Form.cpp
HEADERS = $(SRCS:.cpp=.hpp)
OBJS	= $(SRCS:.cpp=.o)
CC		= c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic-errors

all :	$(NAME)

.cpp.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.cpp=.o)

$(NAME) :	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean	:
	$(RM) $(OBJS)

fclean	:
	$(RM) $(NAME) $(OBJS)

re: fclean all

fmt:
	clang-format -i $(SRCS) $(HEADERS)

.PHONY: all clean fclean re fmt