# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/08/25 14:08:39 by bodibon      #+#   ##    ##    #+#        #
#    Updated: 2018/08/25 17:33:07 by bodibon     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME_1 = push_swap
NAME_2 = checker

SDIR = ./srcs/
IDIR = ./includes/
LDIR = ./libft/
ODIR = ./obj/

SRCS_1 = $(addsuffix .c, check_input insertion_sb_01 insertion_sb_02 \
			insertion_sort_01 insertion_sort_02 insertion_sort_03 \
			insertion_sort_04 insertion_sort_05 main_push_swap med_01 med_02 \
			median_utility push_sort_01 push_sort_02 queue_01 queue_02 \
			queue_03 queue_op_01 queue_op_02 solve_01 solve_02 split_balance \
			split_check_01 split_check_02 split_flush split_half split_inb_01 \
			split_inb_02 split_set split_sort split_stack_01 split_stack_02 \
			split_stack_03 stack_01 stack_02 stack_op_01 stack_op_02)

SRCS_2 = $(addsuffix .c, check_input insertion_sb_01 insertion_sb_02 \
			insertion_sort_01 insertion_sort_02 insertion_sort_03 \
			insertion_sort_04 insertion_sort_05 main_checker med_01 med_02 \
			median_utility push_sort_01 push_sort_02 queue_01 queue_02 \
			queue_03 queue_op_01 queue_op_02 solve_01 solve_02 split_balance \
			split_check_01 split_check_02 split_flush split_half split_inb_01 \
			split_inb_02 split_set split_sort split_stack_01 split_stack_02 \
			split_stack_03 stack_01 stack_02 stack_op_01 stack_op_02 \
			do_op_01 do_op_02)

HEADERS = $(addsuffix .h, push_swap queue stack)

OBJ_1 = $(addprefix $(ODIR), $(SRCS_1:.c=.o))
OBJ_2 = $(addprefix $(ODIR), $(SRCS_2:.c=.o))

LIB = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME_1) $(NAME_2)

$(NAME_1): $(LIB) $(OBJ_1)
	$(CC) $(addprefix $(LDIR), $(LIB)) $(CFLAGS) $(OBJ_1) -o $@

$(NAME_2): $(LIB) $(OBJ_2)
	$(CC) $(addprefix $(LDIR), $(LIB)) $(CFLAGS) $(OBJ_2) -o $@

$(LIB):
	make -C $(LDIR)

$(addprefix $(ODIR), %.o): $(addprefix $(SDIR), %.c) $(addprefix $(IDIR), $(HEADERS))
 
	mkdir -p $(ODIR)
	$(CC) -I $(IDIR) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(ODIR)
	make -C $(LDIR) clean

fclean: clean
	rm -f $(NAME_1) $(NAME_2)
	make -C $(LDIR) fclean

re: fclean all
