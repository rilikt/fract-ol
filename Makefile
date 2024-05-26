# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/30 12:29:08 by timschmi          #+#    #+#              #
#    Updated: 2024/05/26 16:27:43 by timschmi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = main.c window.c mandelbrot.c hook.c
OFILES = $(SRCS:.c=.o)
NAME = fract_ol
EXES = $(NAME)

SUBDIRS = mlx/ libft/

LDFLAGS= -L./libft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit

CC = cc

# CFLAGS = -Wall -Wextra -Werror

all: $(SUBDIRS) $(EXES)

$(SUBDIRS):
	$(MAKE) -C $@

$(EXES): $(OFILES)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(MAKE) -C libft/ clean
	$(MAKE) -C mlx/ clean
	rm -f $(OFILES)

fclean: clean
	$(MAKE) -C libft/ fclean
	$(MAKE) -C mlx/ clean
	rm -f $(EXES)

re: fclean all

.PHONY:  all clean fclean re $(SUBDIRS)