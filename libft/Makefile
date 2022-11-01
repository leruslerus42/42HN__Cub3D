# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paroonag <paroonag@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/21 10:13:07 by paroonag          #+#    #+#              #
#    Updated: 2022/07/30 09:14:40 by paroonag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS =		ft_bzero.c ft_lstclear.c ft_strlcat.c ft_strlcpy.c \
			ft_strdup.c ft_strncmp.c get_next_line.c ft_putstr.c \
			ft_split.c ft_strchr.c ft_strjoin.c ft_memset.c ft_strlen.c \
			ft_lstdelone.c ft_lstsize.c ft_substr.c ft_isformat.c ft_lstlast.c \
			ft_isdigit_str.c ft_free2d.c ft_cntword.c ft_atoi.c ft_calloc.c ft_isdigit.c ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstadd_back.c \
			ft_lstclear.c \
			ft_lstmaxwidth.c
B_SRCS =	
			
OBJS			= $(SRCS:.c=.o)

BONUS_OBJS		= $(BONUS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= libft.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

bonus:			$(OBJS) $(BONUS_OBJS)
				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY:			all clean fclean re bonus