NAME = matrix

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -g -std=c++17

SRC = main.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)
	@echo "All compiled successfully"

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: clean all