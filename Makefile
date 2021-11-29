# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dchonvil <dchonvil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/25 12:35:41 by dchonvil          #+#    #+#              #
#    Updated: 2021/07/30 04:57:50 by dchonvil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

CFLAGS = -Wall -Werror -Wextra

SERVER = server

CLIENT = client

LIB = libft.a

NAME = $(LIB) $(SERVER) $(CLIENT)

SRC = Server_repo/server.c

SRC2 = Client_repo/client.c

SRC-BNS1 = Bonus/Server_repo/server.c

SRC-BNS2 = Bonus/Client_repo/client.c \
		Bonus/Client_repo/utils_client.c

OBJ = $(SRC:.c=.o)

OBJ2 = $(SRC2:.c=.o)

OBJ3 = libft/*.o

OBJ-BNS1 = $(SRC-BNS1:.c=.o)

OBJ-BNS2 = $(SRC-BNS2:.c=.o)

RM = rm -rf

MK = make

all: $(NAME)

$(LIB):
	(cd libft/ && $(MK))

$(SERVER): $(OBJ)
	$(CC) Server_repo/server.c -o server $(CFLAGS) ./libft/libft.a -I./

$(CLIENT): $(OBJ2)
	$(CC) Client_repo/client.c -o client $(CFLAGS) ./libft/libft.a -I./

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ2)
	$(RM) $(OBJ-BNS1)
	$(RM) $(OBJ-BNS2)
	(cd libft && $(MK) clean)

fclean: clean
	$(RM) $(NAME)
	(cd libft && $(MK) fclean)

re: fclean all

bonus: fclean $(OBJ-BNS1) $(OBJ-BNS2) $(LIB)
	$(CC) Bonus/Server_repo/server.c -o server $(CFLAGS) ./libft/libft.a -I./
	$(CC) Bonus/Client_repo/client.c Bonus/Client_repo/utils_client.c -o client $(CFLAGS) ./libft/libft.a -I./

