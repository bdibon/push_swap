/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   stack.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/25 11:36:38 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/25 19:17:05 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#	ifndef STACK_H
#	define STACK_H

#include "../libft/libft.h"

typedef struct				s_stack
{
	struct s_stack_node		*top;
	struct s_stack_node		*bot;
	size_t					size;
}							t_stack;

typedef struct				s_stack_node
{
	int						data;
	size_t					key;
	struct s_stack_node		*next;
	struct s_stack_node		*prev;
}							t_stack_node;

t_stack						*stack_create(void);
void						stack_destroy(t_stack *stack);
t_stack_node				*stack_push(t_stack *stack, int data);
int							stack_pop(t_stack *stack);
int							stack_peek(t_stack *stack);

int							stack_size(t_stack *stack);
t_stack						*stack_init(int argc, char *argv[]);
t_stack						*stack_init2(char *argv[]);

void						stack_print(t_stack *stack);
void						ps_print(t_stack *stack_a, t_stack *stack_b);

t_stack						*stack_clone(t_stack *stack);

void						swap(t_stack *stack_a);
void						swap_double(t_stack *stack_a, t_stack *stack_b);
void						push(t_stack *stack_a, t_stack *stack_b);
void						rotate(t_stack *stack_a);
void						rotate_double(t_stack *stack_a, t_stack *stack_b);
void						rotate_reverse(t_stack *stack_a);
void						rotate_reverse_double(t_stack *stack_a,
		t_stack *stack_b);

#	endif
