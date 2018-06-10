/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_scroll.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 12:07:22 by vliubko           #+#    #+#             */
/*   Updated: 2018/06/10 15:46:28 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_21sh.h"

static void		insert_history(char *str)
{
	size_t 	i;

	move_cursor_home();
	clear_cmd_line();
	term_cmd("cd");
	ft_strcat(g_data.cmd_line, str);
	ft_putstr(str);
	i = 0;
	g_data.pos += ft_strlen(str);
	while (i++ < ft_strlen(str))
		move_right();
}

void	history_back(void)
{
	char 	*old;

//	if (!g_data.history.buf)
//		g_data.history.buf = ft_strdup(g_data.cmd_line);

	if (g_data.history.index > 0)
		g_data.history.index--;

	old = g_data.history.line[g_data.history.index];
	insert_history(old);
}

void	history_forward(void)
{
	char 	*old;

	g_data.history.index++;
	if (g_data.history.index > g_data.history.len)
	{
		g_data.history.index--;
		return ;
	}

	if (g_data.history.index == g_data.history.len)
	{
		insert_history(g_data.history.buf);
		//ft_strdel(&g_data.history.buf);
		return ;
	}
	old = g_data.history.line[g_data.history.index];
	insert_history(old);
}

void	history_processing(char *key)
{
	if (g_data.history.len == 0)
		return ;
	if (ft_strequ(&key[1], UP_ARR))
		history_back();
	else if (ft_strequ(&key[1], DOWN_ARR))
		history_forward();
}