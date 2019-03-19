/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   split_set.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/25 13:54:15 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/25 13:54:28 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

t_nstack	*nstack_create(t_stack *stack)
{
	t_nstack		*nstack;

	if (!(nstack = ft_memalloc(sizeof(t_nstack))))
		return (NULL);
	ft_memmove(nstack, stack, sizeof(t_stack));
	return (nstack);
}

t_split		*split_set(t_stack *stack_a, t_stack *stack_b)
{
	t_split	*split;

	if (!(split = ft_memalloc(sizeof(t_split))))
		return (NULL);
	split->stack_a = nstack_create(stack_a);
	split->stack_b = nstack_create(stack_b);
	split->op = queue_create();
	return (split);
}

size_t		count_stack_supmed(t_nstack *stack)
{
	t_stack_node	*snode;
	size_t			nb;

	if (!stack || stack->size == 0)
		return (0);
	snode = stack->top;
	nb = 0;
	while (snode != stack->bot)
	{
		if (snode->data > stack->med)
			nb++;
		snode = snode->next;
	}
	if (snode->data > stack->med)
		nb++;
	stack->nb_supmed = nb;
	stack->nb_infmed = stack->size - nb;
	return (nb);
}

void		set_stack_split(t_med *med, t_nstack *stack)
{
	stack->med = med->median;
	count_stack_supmed(stack);
}
