/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   stack_op_01.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/25 14:03:40 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/25 18:43:02 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "stack.h"

void	swap(t_stack *stack_a)
{
	int	tmp;

	if (stack_a == NULL || stack_a->size <= 1)
		return ;
	tmp = stack_a->top->data;
	stack_a->top->data = stack_a->top->next->data;
	stack_a->top->next->data = tmp;
}

void	swap_double(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
}

void	push(t_stack *stack_a, t_stack *stack_b)
{
	int	data;

	if (stack_a == NULL || stack_b == NULL)
		return ;
	if (stack_a->size == 0)
		return ;
	data = stack_pop(stack_a);
	stack_push(stack_b, data);
}

void	rotate(t_stack *stack_a)
{
	t_stack_node	*node;
	size_t			i;

	if (stack_a == NULL || stack_a->size <= 1)
		return ;
	stack_a->top = stack_a->top->next;
	stack_a->bot = stack_a->top->prev;
	node = stack_a->bot;
	i = 0;
	while (node != stack_a->top)
	{
		node->key = i;
		i++;
		node = node->prev;
	}
	node->key = stack_a->size - 1;
}

void	rotate_double(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
