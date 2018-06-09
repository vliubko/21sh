/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 11:49:45 by vliubko           #+#    #+#             */
/*   Updated: 2018/06/09 19:15:49 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_21sh.h"

void	add_to_history(void)
{
	g_data.history->cmd = ft_strdup(g_data.cmd_line);
	g_data.history->next = (t_history*)malloc(sizeof(g_data.history));
	g_data.history->next->cmd = NULL;
	g_data.history->next->prev = g_data.history;
	g_data.history = g_data.history->next;
	g_data.history_len++;
}

void	history_init(void)
{
	g_data.history = (t_history*)malloc(sizeof(g_data.history));
	g_data.history->next = NULL;
	g_data.history->prev = NULL;
	g_data.history->cmd = NULL;
	g_data.history_len = 0;
}

void	display_history(void)
{
	int 		index;

	index = 0;
	while (index < g_data.history_len)
		g_data.history = g_data.history->prev;
	index = 0;
	while (index < g_data.history_len)
	{
		ft_putnbr(index);
		ft_putstr(" ");
		ft_putendl(g_data.history->cmd);
		g_data.history = g_data.history->next;
		index++;
	}
}