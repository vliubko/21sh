/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 19:19:38 by vliubko           #+#    #+#             */
/*   Updated: 2018/07/14 19:24:28 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_21sh.h"

int 	ft_has_redirect(char *cmd_line)
{
	int 	i;
	char 	c;

	i = 0;
	while (cmd_line[i])
	{
		c = cmd_line[i];
		if (c == '>' || c == '<')
			return (1);
		i++;
	}
	return (0);
}

void	ft_redirection(char **cmd)
{
	///
}