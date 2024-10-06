NAME	= harl2.0
SRCS	= main.cpp Harl.cpp
OBJS	= $(SRCS:.cpp=.o)
CC		= clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98
# -pedantic -pedantic-errors
RM = rm -f

all :	$(NAME)

.cpp.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.cpp=.o)

$(NAME) :	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

sani :	$(OBJS)
	$(CC) $(CFLAGS) -g -fsanitize=address $(OBJS) -o $(NAME)

clean	:
	$(RM) $(OBJS)

fclean	:
	$(RM) $(NAME) $(OBJS)

re: fclean all

.PHONY: all clean fclean re
