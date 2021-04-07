/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_maths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:46:00 by jjourdan          #+#    #+#             */
/*   Updated: 2021/04/07 17:57:39 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_push_get_sqrt(int nb)
{
	int	sqrt;
	int	buf;

	sqrt = nb / 2;
	buf = 0;
	while (sqrt != buf)
	{
		buf = sqrt;
		sqrt = (nb / buf + buf) / 2;
	}
	return (sqrt);
}

void	ft_push_50_250(t_list *mem, t_info *info, t_stack *stack)
{
	ft_push_x2_max_to_b(info, stack);
	ft_push_b_to_a(mem, stack);
	ft_push_0_x1_to_b(info, stack);
	ft_push_b_to_a(mem, stack);
	ft_push_g2(info, stack);
	ft_push_b_to_a(mem, stack);
	ft_push_finish_rotate(info, stack);
}

void	ft_push_250_max(int *tab, t_list *mem, t_info *info, t_stack *stack)
{
	t_group	*group;
	int		i;

	(void)stack;
	group = NULL;
	i = 0;
	while (i < info->nb_grps)
	{
		ft_push_group_lstadd_back(&group, ft_push_group_lstnew(mem, tab[i * info->grp_size], tab[(i + 1) * info->grp_size - 1], info->grp_size));
		i++;
	}
	ft_push_group_lstadd_back(&group, ft_push_group_lstnew(mem, tab[i * info->grp_size], tab[info->nb - 1], info->nb - i * info->grp_size));
	i = 0;
	while (i <= info->nb_grps)
	{
		ft_push_sort_group();
		group = group->next;
		i++;
	}
}
