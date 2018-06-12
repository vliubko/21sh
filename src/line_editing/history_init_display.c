/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_init_display.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 11:49:45 by vliubko           #+#    #+#             */
/*   Updated: 2018/06/10 15:20:28 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_21sh.h"

void	add_to_history(void)
{
	char	**new;
	int		i;

	i = 0;
	if (g_data.cmd_line[0] == '\0')
		return ;
	new = (char**)malloc(sizeof(char*) * (g_data.history.len + 2));
	while (i < g_data.history.len)
	{
		new[i] = ft_strdup(g_data.history.line[i]);
		i++;
	}
	new[i] = ft_strdup(g_data.cmd_line);
	new[i + 1] = NULL;
	ft_free_2d_array(g_data.history.line);
	g_data.history.line = new;
	g_data.history.len++;
	g_data.history.index = g_data.history.len;
}

void	history_init(void)
{
	g_data.history.index = 0;
	g_data.history.len = 0;
	g_data.history.buf = NULL;
}

int		display_history(void)
{
	int		i;

	i = 0;
	while (i < g_data.history.len)
	{
		ft_putnbr(i + 1);
		if (i < 9)
			ft_putstr("   ");
		else
			ft_putstr("  ");
		ft_putendl(g_data.history.line[i]);
		i++;
	}
	return (1);
}
