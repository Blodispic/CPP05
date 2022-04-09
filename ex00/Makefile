##############################  SOURCE & OBJETS  ###############################

SRCS = main.c Bureaucrat.cpp

OBJS = $(SRCS:.c=.o)

################################  VARIABLES  ###################################

NAME = Bureaucrat

INCLUDE = Bureaucrat.hpp Makefile

RM = rm -f

GCCF = gcc -Wall -Wextra -Werror -std=c++98

##################################  RULES  #####################################

all : $(NAME)

$(NAME):	$(INCLUDE) $(OBJS)
	$(GCCF) $(OBJS) -o $(NAME)

%.o: %.c	$(INCLUDE) 
	${GCCF} -c $< -o $@ 

############################  CLEAN & RE & phony  ##############################

clean:
	${RM} ${OBJS} 

fclean:		clean
	$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus


#################################### END  ######################################