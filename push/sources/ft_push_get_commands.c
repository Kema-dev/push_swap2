/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_get_commands.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 09:47:34 by jjourdan          #+#    #+#             */
/*   Updated: 2021/03/30 10:46:16 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_commands	*ft_push_get_commands(t_list *mem, t_commands *command)
{
	int			return_value;
	char		*text;

	return_value = 1;
	while (return_value == 1)
	{
		return_value = get_next_line(STDIN_FILENO, &text);
		ft_push_command_lstadd_back(&command, ft_push_command_lstnew(mem, text));
		free(text);
	}
	ft_dprintf(STDOUT_FILENO, "PASS");
	while (command)
	{
		ft_dprintf(STDOUT_FILENO, "%s\n", command->value);
		command = command->next;
	}
	return (NULL);
}
