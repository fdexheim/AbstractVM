# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdexheim <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/26 14:02:22 by fdexheim          #+#    #+#              #
#    Updated: 2017/11/13 11:02:07 by fdexheim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	avm

SRC =	main.cpp vm.class.cpp vm.class.instructions.cpp exceptions.cpp \
		OperandFactory.class.cpp OperandInt8.class.cpp OperandInt16.class.cpp \
		OperandInt32.class.cpp OperandFloat.class.cpp OperandDouble.class.cpp \

INCLUDES =	vm.class.h IOperand.class.h exceptions.h OperandFactory.class.h \
			OperandInt8.class.h OperandInt16.class.h OperandInt32.class.h \
			OperandFloat.class.h OperandDouble.class.h \

OBJ =	$(SRC:.cpp=.o)

C++ =	clang++ -Wall -Wextra -Werror

%.o:		%.cpp
	@echo "\033[1;32;m[$<]\033[0m : " | tr -d '\n'
	$(C++) -c $<

all:		$(NAME)

$(NAME):	$(OBJ) $(INCLUDES)
	$(C++) -o $@ $(OBJ)
	@echo "\033[1;32;m[Compilation Successful]\033[0m"
	@echo "\033[1;36;m$(NAME)\033[1;32;m ready to go !\033[0m"

clean:
	@echo "\033[0;33;m[Clean]\033[0m              : " | tr -d '\n'
	rm -f $(OBJ)

fclean:		clean
	@echo "\033[0;31;m[Deleting $(NAME)]\033[0m : " | tr -d '\n'
	rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
