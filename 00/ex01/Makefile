RED     = \033[31m
GREEN   = \033[32m
MAGENTA = \033[35m
CYAN    = \033[36m
RESET   = \033[0m

NAME		= phonebook

MANDATORY_SRC	= main.cpp \
				PhoneBook.cpp \
				Contact.cpp 

MANDATORY_OBJ	= $(MANDATORY_SRC:.cpp=.o)

CXX		= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(MANDATORY_OBJ)
	@$(CXX) $(CXXFLAGS) $(MANDATORY_OBJ) -o $(NAME)
	@printf "$(GREEN)Mandatory part is built.$(RESET)\n"

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@printf "$(RED)Removing object files... $(RESET)\n"
	@rm -f $(MANDATORY_OBJ)

fclean: clean
	@printf "$(MAGENTA)Removing $(NAME).. $(RESET)\n"
	@rm -f $(NAME)

re: fclean
	@$(MAKE) all

.PHONY: all clean fclean re