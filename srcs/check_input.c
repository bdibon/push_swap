/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_input.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/25 11:43:56 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/25 11:44:10 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*get_input(int argc, char *argv[])
{
	if (argc == 1)
		exit(0);
	return (stack_init(argc, argv));
}

int			ft_strisnum(char *str)
{
	char *c;

	c = str;
	while (c && *c)
	{
		if (!ft_isdigit(*c) && !(c == str && *c == '-'))
			return (0);
		c++;
	}
	return (1);
}

intmax_t	ft_atoi2(const char *str)
{
	size_t		i;
	int			sign;
	intmax_t	nb;

	i = 0;
	while (str[i] && (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r')))
		i++;
	sign = (str[i] == '-') ? -1 : 1;
	i = (str[i] == '-' || str[i] == '+') ? i + 1 : i;
	nb = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	return (nb * sign);
}

void		print_error(void)
{
	ft_printf("Error\n");
	exit(1);
}

int			check_duplicates(t_stack *stack_a, int data)
{
	t_stack_node *node;

	if (stack_a->size == 0)
		return (1);
	node = stack_a->top;
	while (node != stack_a->bot)
	{
		if (node->data == data)
			return (0);
		node = node->next;
	}
	if (node->data == data)
		return (0);
	return (1);
}
