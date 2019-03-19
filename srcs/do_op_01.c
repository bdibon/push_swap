/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   do_op_01.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/25 11:46:51 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/25 19:35:47 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

char	*stream_to_string(t_stack *stack_a, t_stack *stack_b)
{
	char	*buf;
	char	*input;
	ssize_t	n;

	input = NULL;
	buf = ft_memalloc(16);
	while ((n = read(STDIN_FILENO, buf, 15)) > 0)
	{
		if (input == NULL)
		{
			input = ft_strnew(ft_strlen(buf));
			ft_strcpy(input, buf);
		}
		else
		{
			ft_strexpand(&input, ft_strlen(buf));
			ft_strcat(input, buf);
		}
		ft_memset(buf, 0, 16);
	}
	if (n < 0 || (!input && !check_result2(stack_a, stack_b)))
		print_error();
	free(buf);
	return (input);
}

char	**get_operations(t_stack *stack_a, t_stack *stack_b)
{
	char	**op;
	char	*input;

	input = stream_to_string(stack_a, stack_b);
	op = ft_strsplit(input, '\n');
	free(input);
	return (op);
}

void	check_op(char *op)
{
	if (!ft_strcmp(op, "sa"))
		return ;
	if (!ft_strcmp(op, "sb"))
		return ;
	if (!ft_strcmp(op, "ss"))
		return ;
	if (!ft_strcmp(op, "pa"))
		return ;
	if (!ft_strcmp(op, "pb"))
		return ;
	if (!ft_strcmp(op, "ra"))
		return ;
	if (!ft_strcmp(op, "rb"))
		return ;
	if (!ft_strcmp(op, "rr"))
		return ;
	if (!ft_strcmp(op, "rra"))
		return ;
	if (!ft_strcmp(op, "rrb"))
		return ;
	if (!ft_strcmp(op, "rrr"))
		return ;
	print_error();
}

void	do_op(char *op, t_stack *stack_a, t_stack *stack_b)
{
	check_op(op);
	if (!ft_strcmp(op, "sa"))
		swap(stack_a);
	else if (!ft_strcmp(op, "sb"))
		swap(stack_b);
	else if (!ft_strcmp(op, "ss"))
		swap_double(stack_a, stack_b);
	else if (!ft_strcmp(op, "pa"))
		push(stack_b, stack_a);
	else if (!ft_strcmp(op, "pb"))
		push(stack_a, stack_b);
	else if (!ft_strcmp(op, "ra"))
		rotate(stack_a);
	else if (!ft_strcmp(op, "rb"))
		rotate(stack_b);
	else if (!ft_strcmp(op, "rr"))
		rotate_double(stack_a, stack_b);
	else if (!ft_strcmp(op, "rra"))
		rotate_reverse(stack_a);
	else if (!ft_strcmp(op, "rrb"))
		rotate_reverse(stack_b);
	else
		rotate_reverse_double(stack_a, stack_b);
}

void	try_op(char **op_list, t_stack *stack_a, t_stack *stack_b)
{
	char	*op;
	size_t	i;

	i = 0;
	op = op_list[i];
	while (op)
	{
		do_op(op, stack_a, stack_b);
		free(op);
		op = op_list[++i];
	}
	free(op_list);
}
