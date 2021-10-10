NAME = ex00

SRC = main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp

HEAD = Animal.hpp Dog.hpp Cat.hpp WrongAnimal.hpp WrongCat.hpp

OBJS = $(SRC:.cpp=.o)

CXX = clang++
RM = rm -rf

FLAGS = -Wall -Wextra -Werror -std=c++98

%.o: %.cpp	$(HEAD) Makefile
			@$(CXX) $(FLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS) $(HEAD)
			$(CXX) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY: 	all run clean fclean re