NAME            =   push_swap
SRC             =   push_swap.c\
					rotatemoves.c\
					rrotatemoves.c\
					swap_moves.c\
					push_moves.c\
					short_sort.c\
					utils/ft_atoi.c\
					utils/list_utils.c\
					utils/more_list_utils.c\
					utils/arg_check.c\
					printf/ft_printf.c\
					printf/ft_printf_utils.c\
					printf/ft_printf_scdi.c\
					printf/ft_printf_u.c\
					printf/ft_printf_x.c\
					printf/ft_printf_p.c\
					utils/ft_split.c\
					utils/ft_strncmp.c

CC          =   gcc
CFLAGS          =   -Wall -Wextra -Werror -g3 -fsanitize=address
RM              =   rm -f
CLR_RMV     := \033[0m
RED         := \033[1;31m
GREEN       := \033[1;32m
YELLOW      := \033[1;33m
BLUE        := \033[1;34m
CYAN        := \033[1;36m

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		@clear
		@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CYAN}"
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:			pato
				@echo "$(RED)Deleting ${YELLOW}.o ${CLR_RMV}"
				$(RM) $(OBJS)

pato:
				@clear
				@echo "${YELLOW}'⣿⣿⣿⣿⣿⣿⣿⣿⣿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⡜⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⣿⣿⣿⣾⣶⡀⠀⠀⠀⠀⠀⠀⣽⣿⣿⣿⣿⣿⣿⣿⣿'\n'⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⣰⣹⣽⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠛⠛⠋⠉⢉⣨⣁⣀⠋⠙⢿⣿⣷⠀⠀⠀⠀⢈⣾⣿⣿⣿⣿⣿⣿⣿⣿'\n'⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⠀⠀⠀⠀⠀⠀⢰⠣⢇⣻⠟⠉⠻⠿⠿⠿⠿⠿⢿⢿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠋⣀⠄⠀⢒⣛⡛⠻⠿⡯⣹⣆⣻⣿⣿⠀⠀⠀⣠⣿⣿⣿⣿⣿⣿⣿⣿⠿⣯'\n'⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠆⠀⠀⠀⠀⠀⠀⡋⠄⠀⠀⠀⠀⡀⠀⠀⠀⠀⠀⠀⠈⠙⣿⣿⣿⣿⣿⣿⣣⡶⡠⢘⠉⠀⠈⢉⠙⠒⢬⣽⣿⣿⣿⣿⡇⠀⢰⣿⣿⣿⣿⣿⣿⣿⣿⣯⣀⡝"
				@echo "${YELLOW}'⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣇⠀⠀⠀⠀⠀⠀⡇⠀⠀⢀⠀⠀⠀⠀⠀⠀⠀⢀⠀⢣⡀⡘⣿⣿⣿⣿⣿⣿⣧⣃⣿⣤⣘⣠⣿⢣⣀⣿⣿⣿⣿⣿⣿⡃⠀⠸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀'\n'⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢟⠙⠀⠀⠀⠀⠀⠀⡓⠀⣌⣀⢤⠀⠀⣚⣦⣼⣶⣿⣶⣾⣿⣇⣽⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣯⣾⣿⣿⣿⣿⣿⣿⣿⡇⢰⢿⣿⢿⣿⣿⣿⣿⣿⣿⣿⣿⠀'\n'⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢸⣷⡃⢀⠀⠂⠀⠀⠽⣹⣿⣿⣿⣶⣿⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠁⢏⣿⣷⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧'\n'⠟⠿⠛⠿⠛⠳⠿⡟⣿⠟⣨⠭⢀⢸⠀⠐⠀⠀⠐⠹⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣏⢀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠿⠋⠃'\n'⠄⡀⠀⠀⠀⠀⠀⠀⠀⣠⡿⠂⠀⠈⠂⠀⠐⡄⠀⢘⣺⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣾⢸⣿⠟⣵⣿⣿⣿⡿⠟⣋⣥⣶⣶⣿ '\n'⠀⠀⠀⠀⠀⠀⠀⠥⠝⠁⠃⠀⠀⠀⠀⠡⠐⢆⠀⠀⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡏⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠀⠀⣴⣿⣿⡿⠃⠀⠉⠉⠹⢙⡛⠿"
				@echo "${YELLOW}'⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢈⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⠘⠫⠋⠛⣻⢿⡟⠉⠉⣠⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⠀⡴⠿⠋⠉⠀⠀⠀⠀⠀⠀⠀⠀⠈'\n'⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢂⠦⡹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣤⣀⣄⠈⢃⣀⣴⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀'\n'⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢘⣴⣥⠣⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⣀⡀⣄⢦⣔⣦⣱'\n'⣤⣦⣴⣠⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⢽⣿⣶⡍⢿⣿⣿⣿⡛⠙⠛⠛⠛⠋⠛⠛⠟⠛⢉⣉⣉⣉⣡⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠀⠀⠀⠀⢀⣄⣦⣽⣷⣿⣾⣿⣿⣿'\n'⣿⣿⣷⣿⣿⣷⣦⣦⣄⡤⣀⣀⢀⠀⠀⠀⠀⠀⠀⠀⠀⠫⣿⣿⣷⡜⢿⣿⣿⣿⣿⣷⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠇⠀⠀⢠⣴⣿⣾⣿⣿⣿⣿⣿⣿⣿⣿'\n'⣿⣿⣿⣿⡿⣿⣿⣿⣿⣿⣿⣽⣾⣷⡤⠀⠀⠀⠀⠀⠀⠀⠵⢻⣿⣿⣼⡿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⢁⡗⡄⣬⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿"


fclean:         pato clean
				@echo "$(RED)Deleting ${YELLOW}.a ${CLR_RMV}"
				$(RM) $(NAME)

re:             fclean all

.PHONY: all clean fclean re