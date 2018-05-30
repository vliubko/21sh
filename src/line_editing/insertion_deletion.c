/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_deletion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 13:22:28 by vliubko           #+#    #+#             */
/*   Updated: 2018/05/30 15:24:22 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_21sh.h"


void    insert_char(char *key)
{
	int     pos;
	char    *tail;
	char    *new_tail;
	char    *head;
	int 	len;

	pos = g_data.pos - PROMPT_LEN;
	tail = ft_strsub(g_data.cmd_line, pos, CMD_LEN - pos);
	head = ft_strsub(g_data.cmd_line, 0, pos);
	new_tail = ft_strjoin(key, tail);
	len = (int)ft_strlen(tail);
	ft_strdel(&tail);
	term_cmd("cd");
	ft_putstr(new_tail);
	realloc_cmd_line(head, new_tail);
	tputs(tgoto(tgetstr("LE", 0), 0, len + 1), 1, &term_putchar);
	move_right();
}

void	delete_char(void)
{
	int     pos;
	char    *tail;
	char    *head;
	int 	len;

	pos = g_data.pos - PROMPT_LEN;
	if (pos == 0)
		return ;
	head = ft_strsub(g_data.cmd_line, 0, pos - 1);
	tail = ft_strsub(g_data.cmd_line, pos, CMD_LEN - pos);
	len = (int)ft_strlen(tail);
	move_left();
	term_cmd("cd");
	ft_putstr(tail);
	realloc_cmd_line(head, tail);
	if (len > 0)
		tputs(tgoto(tgetstr("LE", 0), 0, len), 1, &term_putchar);
}
