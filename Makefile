SRC = src/*.c


LIBFT = libft
INC = inc
LINK = /usr/local/opt/readline/lib -lreadline

LIBS = -L$(LIBFT) -lft -L$(LINK)
HEADERS = -I$(INC) -I$(LIBFT) -I /usr/local/opt/readline/include/
FLAGS = -Wall -Werror -Wextra $(LIBS) $(HEADERS)

all:
	@clear
	@make -s -C $(LIBFT)
	@echo Compiling libft
	@gcc $(SRC) $(FLAGS) -o minishell 
	@echo Good to go
	

clean:
	@clear
	@rm -f minishell
	@make fclean -s -C $(LIBFT)
	@echo nothing here anymore, well, except .c

fclean: clean

re: clean all
