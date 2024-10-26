NAME	= a.out
SRCS	= main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp
OBJS	= $(SRCS:.cpp=.o)
CC		= c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic-errors
# -pedantic -pedantic-errors

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

.PHONY: all clean fclean re
