NAME = libft.a
HEADER = ./libft.h
SRCS= ./ft_atoi.c\
	./ft_bzero.c\
	./ft_isalnum.c\
	./ft_isalpha.c\
	./ft_isascii.c\
	./ft_isdigit.c\
	./ft_isprint.c\
	./ft_memcpy.c\
	./ft_memccpy.c\
	./ft_memcmp.c\
	./ft_memset.c\
	./ft_memchr.c\
	./ft_memmove.c\
	./ft_strlen.c\
	./ft_strlcpy.c\
	./ft_strlcat.c\
	./ft_strncmp.c\
	./ft_strchr.c\
	./ft_tolower.c\
	./ft_toupper.c\
	./ft_strdup.c\
	./ft_calloc.c\
	./ft_substr.c\
	./ft_strjoin.c\
	./ft_strnstr.c\
	./ft_putchar_fd.c\
	./ft_putstr_fd.c\
	./ft_putendl_fd.c\
	./ft_putnbr_fd.c\
	./ft_split.c\
	./ft_strmapi.c\
	./ft_strtrim.c\
	./ft_realloc.c\
	./ft_itoa.c\
	./ft_strrchr.c\
	./ft_space.c\
	./get_next_line.c\
	./get_next_line_utils.c
BONUS= ./ft_lstadd_back_bonus.c\
		./ft_lstadd_front_bonus.c\
		./ft_lstclear_bonus.c\
		./ft_lstdelone_bonus.c\
		./ft_lstiter_bonus.c\
		./ft_lstlast_bonus.c\
		./ft_lstmap_bonus.c\
		./ft_lstnew_bonus.c\
		./ft_lstsize_bonus.c
OBJ = $(SRCS:.c=.o)
OBJ_BONUS = $(BONUS:.c=.o) $(SRCS:.c=.o)

CFLAGS += -Wall -Wextra  -Werror

CC = gcc

all: $(NAME)

%.o: %.c $(HEADER) 
		@$(CC) $(CFLAGS) -c $< -o $@
		@printf "-"

$(NAME): $(OBJ) $(HEADER)
		@ar rcs $(NAME) $(OBJ)
		@echo "\nlib compiled"

clean:
	@rm -rf $(OBJ) $(OBJ_BONUS)
	@echo "objects deleted"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(NAME) is deleted"

bonus: $(OBJ_BONUS)
	@ar rcs $(NAME) $(OBJ_BONUS)
	@echo "\nbonus compiled"


re: fclean all

.PHONY : all clean fclean re
