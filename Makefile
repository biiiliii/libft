# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bimartin <bimartin@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/19 14:36:48 by bimartin          #+#    #+#              #
#    Updated: 2022/10/04 14:12:03 by bimartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

BONUS = .bonus

HEADER = libft.h

SRC = 	ft_atoi.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_striteri.c \
		ft_strmapi.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_itoa.c \
		ft_split.c

OBJ = $(SRC:.c=.o)

DEPS = $(SRC:.c=.d)

SRCBONUS	=	ft_utils_bonus.c \
				ft_lstnew_bonus.c \
				ft_lstadd_front_bonus.c \
				ft_lstsize_bonus.c \
				ft_lstlast_bonus.c \
				ft_lstadd_back_bonus.c \
				ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c \
				ft_lstiter_bonus.c \
				ft_lstmap_bonus.c

OBJBONUS = $(SRCBONUS:.c=.o)

DEPSBONUS = $(SRCBONUS:.c=.d)

FLAGS = -Wall -Wextra -Werror -MMD -g

RM = rm -f

DEF_COLOR := \033[0;39m
GRAY := \033[0;90m
RED := \033[0;91m
GREEN := \033[0;92m
YELLOW := \033[0;93m
BLUE := \033[0;94m
MAGENTA := \033[0;95m
CYAN := \033[0;96m
WHITE := \033[0;97m

%.o : %.c
	@echo "$(BLUE)	Compiling: $(YELLOW)$< $(DEF_COLOR)"
	@$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

bonus: $(BONUS)

-include $(DEPS)
$(NAME) : $(OBJ)
	@ar rcs	$(NAME) $(OBJ)

$(BONUS) : $(OBJ) $(OBJBONUS)
	@touch $@
	@echo "$(BLUE) Bonus compiled. $(DEF_COLOR)"
	@ar rcs $(NAME) $(OBJ) $(OBJBONUS)

clean :
	@$(RM) $(OBJ) $(OBJBONUS)
	@$(RM) $(DEPS) $(DEPSBONUS)
	@echo "$(BLUE)	Printf object files cleaned.$(DEF_COLOR)"

fclean : clean
	@$(RM) $(NAME) $(BONUS)
	@echo "$(WHITE)	All objects, dependencies and executables removed.$(DEF_COLOR)"

re : fclean all

senyera:
	@echo "			$(YELLOW)|$(RED)|$(YELLOW)|$(RED)|$(YELLOW)|$(RED)|$(YELLOW)|$(RED)|$(YELLOW)|$(DEF_COLOR)"
	@echo "			$(YELLOW)|$(RED)|$(YELLOW)|$(RED)|$(YELLOW)|$(RED)|$(YELLOW)|$(RED)|$(YELLOW)|$(DEF_COLOR)"
	@echo "			$(YELLOW)|$(RED)|$(YELLOW)|$(RED)|$(YELLOW)|$(RED)|$(YELLOW)|$(RED)|$(YELLOW)|$(DEF_COLOR)"
	@echo "			$(YELLOW)|$(RED)|$(YELLOW)|$(RED)|$(YELLOW)|$(RED)|$(YELLOW)|$(RED)|$(YELLOW)|$(DEF_COLOR)"
	@echo "			$(YELLOW)|$(RED)|$(YELLOW)|$(RED)|$(YELLOW)|$(RED)|$(YELLOW)|$(RED)|$(YELLOW)|$(DEF_COLOR)"
	@echo "			$(YELLOW)|$(RED)|$(YELLOW)|$(RED)|$(YELLOW)|$(RED)|$(YELLOW)|$(RED)|$(YELLOW)|$(DEF_COLOR)"
	@echo "			$(YELLOW)|$(RED)|$(YELLOW)|$(RED)|$(YELLOW)|$(RED)|$(YELLOW)|$(RED)|$(YELLOW)|$(DEF_COLOR)"
	@echo "			$(YELLOW)|$(RED)|$(YELLOW)|$(RED)|$(YELLOW)|$(RED)|$(YELLOW)|$(RED)|$(YELLOW)|$(DEF_COLOR)"
	@echo "			$(YELLOW)|$(RED)|$(YELLOW)|$(RED)|$(YELLOW)|$(RED)|$(YELLOW)|$(RED)|$(YELLOW)|$(DEF_COLOR)"


.PHONY : all clean fclean re bonus senyera
