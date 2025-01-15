NAME = fdf

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g  # Added debugging flag (-g)

# Directories
SRCDIR = src
OBJDIR = obj
INCDIR = include
LIBDIR = lib
MINILIBX = $(LIBDIR)/minilibx-linux
LIBFT = $(LIBDIR)/libft

# Source and object files
SRC = \
	3D.c \
	draw.c \
	events.c \
	grid.c \
	utils.c \

OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

# Library dependencies
LIBFT_LIB = $(LIBFT)/libft.a
MINILIBX_LIB = $(MINILIBX)/libmlx.a

# Includes and libraries
INCLUDES = -I$(INCDIR) -I$(MINILIBX) -I$(LIBFT)
LIBS = -L$(MINILIBX) -lmlx -L$(LIBFT) -lft -lm -lXext -lX11

# Rules
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_LIB) $(MINILIBX_LIB)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT)

$(MINILIBX_LIB):
	$(MAKE) -C $(MINILIBX)

clean:
	$(MAKE) -C $(LIBFT) clean
	$(MAKE) -C $(MINILIBX) clean
	rm -rf $(OBJDIR)

fclean: clean
	$(MAKE) -C $(LIBFT) fclean
	rm -f $(NAME)

re: fclean all

# Debug build target (without debugging flags)
debug: CFLAGS += -g  # Append debug flag
debug: fclean $(NAME)

.PHONY: all clean fclean re debug
