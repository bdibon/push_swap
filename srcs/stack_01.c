/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   stack_01.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/12 16:19:59 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/25 13:59:48 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "stack.h"

t_stack			*stack_create(void)
{
	t_stack	*stack;

	stack = ft_memalloc(sizeof(t_stack));
	return (stack);
}

void			stack_destroy(t_stack *stack)
{
	while (stack->size > 0)
		stack_pop(stack);
	free(stack);
}

t_stack_node	*stack_push(t_stack *stack, int data)
{
	t_stack_node	*new;

	if (stack == NULL || !(new = ft_memalloc(sizeof(t_stack_node))))
		return (NULL);
	new->data = data;
	if (stack->top)
	{
		stack->top->prev = new;
		new->next = stack->top;
		stack->top = new;
	}
	else
		stack->top = new;
	if (stack->bot)
	{
		stack->bot->next = new;
		new->prev = stack->bot;
	}
	else
		stack->bot = new;
	stack->size++;
	new->key = (stack->size == 1) ? 0 : new->next->key + 1;
	return (new);
}

int				stack_pop(t_stack *stack)
{
	t_stack_node	*top;
	int				data;

	top = stack->top;
	data = top->data;
	if (stack->size > 2)
	{
		top->next->prev = stack->bot;
		top->prev->next = top->next;
	}
	else if (stack->size == 2)
	{
		top->next->prev = NULL;
		top->prev->next = NULL;
	}
	stack->top = top->next;
	stack->bot = (stack->bot == top) ? NULL : stack->bot;
	free(top);
	stack->size--;
	return (data);
}

int				stack_peek(t_stack *stack)
{
	return (stack->top->data);
}
