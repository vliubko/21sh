/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_paste.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 10:53:50 by vliubko           #+#    #+#             */
/*   Updated: 2018/06/23 14:41:49 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_21sh.h"

void    copy_line(void)
{
    char    *buf;
    int     pos;

    ft_bzero(g_data.buf_cmd_line, 4096);
    pos = g_data.pos - PROMPT_LEN;
    buf = ft_strsub(g_data.cmd_line, pos, CMD_LEN - pos);
    ft_strcat(g_data.buf_cmd_line, buf);
    ft_strdel(&buf);
}

void    paste_line(void)
{
    int     pos;
    char    *tail;
    char    *new_tail;
    char    *head;
    int     len;
    int     len2;

    pos = g_data.pos - PROMPT_LEN;
	tail = ft_strsub(g_data.cmd_line, pos, CMD_LEN - pos);
	head = ft_strsub(g_data.cmd_line, 0, pos);
	new_tail = ft_strjoin(g_data.buf_cmd_line, tail);
	len = (int)ft_strlen(new_tail);
    len2 = (int)ft_strlen(g_data.buf_cmd_line);
	ft_strdel(&tail);
	term_cmd("cd");
	ft_putstr(new_tail);
	realloc_cmd_line(head, new_tail);
    tputs(tgoto(tgetstr("LE", 0), 0, len), 1, &term_putchar);
    while (len2 > 0)
    {
        move_right();
        len2--;
    }
}

void    copy_paste_processing(char *key)
{
    if (ALT_C)
		copy_line();
	else if (ALT_V && g_data.buf_cmd_line[0] != '\0')
		paste_line();
}
