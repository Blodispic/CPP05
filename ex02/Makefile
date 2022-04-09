##############################  SOURCE & OBJETS  ###############################

SRCS = main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp

OBJS = $(SRCS:.cpp=.o)

################################  VARIABLES  ###################################

NAME = Bureaucrat

INCLUDE = Bureaucrat.hpp AForm.hpp PresidentialPardonForm.hpp Makefile

RM = rm -f

GCCF = c++ -Wall -Wextra -Werror -std=c++98

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

.PHONY:		all clean fclean re bonus libf


#################################### END  ######################################