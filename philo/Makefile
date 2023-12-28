NAME			:=	philo

MAIN_FILE		:=	main.c \
					act.c \
					destroy.c \
					init.c \
					parse_args.c \
					party.c \
					print_get_msg.c
#					monitor.c

# ARGS			:=	parse_args.c

UTIL_FILES		:=	ft_atoll.c \
					ft_isdigit.c \
					ft_putstr.c \
					utils.c

SRC_PATH		:=	./srcs/
OBJ_PATH		:=	./objs/
INC_PATH		:=	./includes/
# ARGS_PATH		:=	$(SRC_PATH)args/
UTILS_PATH		:=	$(SRC_PATH)utils/

SRC				=	$(addprefix $(SRC_PATH), $(MAIN_FILE))
OBJ				=	$(addprefix $(OBJ_PATH), $(MAIN_FILE:.c=.o))
# ARGS			=	$(addprefix $(ARGS_PATH), $(ARGS))
# ARGS_OBJ		=	$(addprefix $(OBJ_PATH), $(ARGS:.c=.o))
UTILS			=	$(addprefix $(UTILS_PATH), $(UTIL_FILES))
UTILS_OBJ		=	$(addprefix $(OBJ_PATH), $(UTIL_FILES:.c=.o))

CC				:=	cc
CFLAGS			:=	-Wall -Wextra -Werror -MMD -g -pthread -fsanitize=thread -Iincludes 
# CFLAGS			:=	-Wall -Wextra -Werror -MMD -g -pthread -Iincludes 
RM				:=	rm -fr

all				:	$(NAME)

$(NAME)			:	$(OBJ_PATH) $(OBJ) $(UTILS_OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(UTILS_OBJ) -o $@

$(SRC_PATH)		:
	@mkdir -p $@

$(OBJ_PATH)		:
	@mkdir -p $@

$(INC_PATH)		:
	@mkdir -p $@


# $(NAME)			:	$(OBJ_PATH) $(OBJ) 
# 	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
# $(NAME)			:	$(OBJ_PATH) $(OBJ) $(ARGS_OBJ) $(UTILS_OBJ)
# 	$(CC) $(CFLAGS) $(OBJ) $(ARGS_OBJ) $(UTILS_OBJ) -o $@
# $(OBJ)			:

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH)%.o: $(UTILS_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@

# $(OBJ_PATH)%.o: $(ARGS_PATH)%.c
# 	$(CC) $(CFLAGS) -c $< -o $@

# $(OBJ_PATH)%.o	:	$(SRC_PATH)%.c
# 	@$(CC) $(CFLAGS) -c $^ -o $@

-include $(OBJS:%.o=%.d) $(ARGS_OBJ:%.o=%.d) $(UTILS_OBJ:%.o=%.d)

clean			:
	$(RM) $(OBJ_PATH)

fclean			:	clean
	$(RM) $(NAME)

re				:	fclean all

files			:	$(SRC_PATH) $(INC_PATH)
	@touch $(INC_PATH)philo.h $(SRC)

commit			:
	git add $(SRC) $(UTILS) Makefile $(INC_PATH)*.h test.sh output.txt
	git commit -m "commit through makefile"
	git status

.PHONY			:	all clean fclean re files commit