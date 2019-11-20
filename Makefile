NAME	= libftprintf

LIBFT	= libft

# directories
SRCDIR	= ./srcs/
INCDIR	= ./includes/
OBJDIR	= ./obj/

# compiler
CC		= gcc
CFLAGS	= -Wall -Wextra -g

# src / obj files
SRC		= main.c fields.c float_tools.c print_f.c ft_printf.c number_tools.c parse_field.c \
			print_d.c print_o_x.c print_p.c print_s.c print_u.c
OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))

# ft library
FT		= ./libft/
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I ./libft
FT_LNK	= -L ./libft -lft


all: obj $(FT_LIB) $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	$(CC) -g $(CFLAGS) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
	make -C $(FT)

$(NAME): $(OBJ)
	$(CC) -g $(OBJ) $(FT_LNK) -o $(NAME)


clean:
	rm -rf $(OBJDIR)
	make -C $(FT) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(FT) fclean

re: fclean all