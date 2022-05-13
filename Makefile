NAME	= containers


SRC	= $(wildcard *.cpp)
FLAGS	= -Wall -Wextra -Werror
CXX	= c++
CXXFLAGS += -std=c++98 -g $(FLAGS)

all:	$(NAME)

$(NAME):	
			$(CXX) $(CXXFLAGS)  *.cpp -o $@
			rm -f $(OBJ)
			

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY = all clean fclean re