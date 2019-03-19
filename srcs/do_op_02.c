/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   do_op_02.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/25 11:44:30 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/25 19:55:48 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

void	print_ok(void)
{
	ft_printf("OK\n");
	exit(0);
}

void	print_ko(void)
{
	ft_printf("KO\n");
	exit(0);
}

void	check_result(t_stack *stack_a, t_stack *stack_b)
{
	t_stack_node *node;

	node = stack_a->top;
	if (stack_b->size > 0)
		print_ko();
	while (node != stack_a->bot)
	{
		if (node != stack_a->top)
			if (node->data < node->prev->data)
				print_ko();
		node = node->next;
	}
	if (node != stack_a->top)
		if (node->data < node->prev->data)
			print_ko();
	print_ok();
}

int		check_result2(t_stack *stack_a, t_stack *stack_b)
{
	t_stack_node *node;

	node = stack_a->top;
	if (stack_b->size > 0)
		return (0);
	while (node != stack_a->bot)
	{
		if (node != stack_a->top)
			if (node->data < node->prev->data)
				return (0);
		node = node->next;
	}
	if (node != stack_a->top)
		if (node->data < node->prev->data)
			return (0);
	print_ok();
	return (1);
}
