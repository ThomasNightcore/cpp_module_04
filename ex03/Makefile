# -------------------------------------------------------------------
# VARIABLES
# -------------------------------------------------------------------

# Source file directories
SRCS_DIR			= ./
TEST_DIR			= ./tests/

INCLUDES_DIR		= ./

# Other directories
OBJS_DIR			= ./objs/

# Source files
CFILES_ROOT			= main.cpp \
					  AMateria.cpp \
					  Ice.cpp \
					  Cure.cpp \
					  MateriaSource.cpp \
					  Character.cpp \

CFILES_TEST			= subjectTest.cpp \
					  customTests.cpp \
					  classTests.cpp

OBJ_FILES 			:= $(CFILES_ROOT:.cpp=.o) \
		 			   $(CFILES_TEST:.cpp=.o)

DEP_FILES 			:= $(CFILES_ROOT:.cpp=.d) \
		 			   $(CFILES_TEST:.cpp=.d)

OBJS				:= $(addprefix $(OBJS_DIR), $(OBJ_FILES))
DEPENDENCIES		:= $(addprefix $(OBJS_DIR), $(DEP_FILES))

# Compilation variables
NAME				= materia
CXX 				= c++
CXXFLAGS 			= -Wall -Werror -Wextra -std=c++98 -MMD -MP
RM 					= rm -rf
INCLUDES			:= $(INCLUDES_DIR)

# -------------------------------------------------------------------
# RULES
# -------------------------------------------------------------------

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

debug:
	$(MAKE) CXXFLAGS="-g $(CXXFLAGS)"

clean:
	$(RM) objs

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re debug

# -------------------------------------------------------------------
# OBJECT RULES
# -------------------------------------------------------------------
# // These have to be implemented for each directory in the project

-include $(DEPENDENCIES)
$(OBJS_DIR)%.o: $(SRCS_DIR)%.cpp
	@mkdir -p $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

-include $(DEPENDENCIES)
$(OBJS_DIR)%.o: $(TEST_DIR)%.cpp
	@mkdir -p $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@
