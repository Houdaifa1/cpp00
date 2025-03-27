NAME = PhoneBook

SRC = main.cpp PhoneBook.cpp utils.cpp Contact.cpp 

cc = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(SRC)
	$(cc) $(CFLAGS) $(SRC) -o $(NAME)

clean :

fclean : clean
	rm -rf $(NAME)

re : fclean all