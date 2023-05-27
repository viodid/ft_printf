LIB = ar rcs

NAME = libft.a

SRCS = ft_isalpha.c \
						ft_isdigit.c  \
						ft_isalnum.c \
						ft_isascii.c \
						ft_isprint.c \
						ft_toupper.c \
						ft_tolower.c \
						ft_strlen.c \
						ft_atoi.c \
						ft_memcpy.c \
						ft_memmove.c \
						ft_memset.c \
						ft_memcmp.c \
						ft_strchr.c \
						ft_bzero.c \
						ft_strlcpy.c \
						ft_calloc.c \
						ft_strjoin.c \
						ft_memchr.c \
						ft_strnstr.c \
						ft_strlcat.c \
						ft_strdup.c \
						ft_strrchr.c \
						ft_strncmp.c \
						ft_substr.c \
						ft_strtrim.c \
						ft_strmapi.c \
						ft_striteri.c \
						ft_putchar_fd.c \
						ft_putstr_fd.c \
						ft_putendl_fd.c \
						ft_putnbr_fd.c \
						ft_itoa.c \
						ft_split.c


OBJ = $(SRCS:.c=.o)

BONUS_SRCS = ft_lstnew_bonus.c \
							ft_lstadd_front_bonus.c \
							ft_lstsize_bonus.c \
							ft_lstlast_bonus.c \
							ft_lstadd_back_bonus.c \
							ft_lstdelone_bonus.c \
							ft_lstclear_bonus.c \
							ft_lstiter_bonus.c \
							ft_lstmap_bonus.c

BONUS_OBJ = $(BONUS_SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJ)
	@ar r $(NAME) $(OBJ)

bonus: $(BONUS_OBJ)
	@ar r $(NAME) $(BONUS_OBJ)

all: $(NAME) bonus

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re