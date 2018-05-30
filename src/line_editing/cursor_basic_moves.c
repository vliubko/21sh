/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_basic_moves.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 12:38:16 by vliubko           #+#    #+#             */
/*   Updated: 2018/05/30 14:40:31 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_21sh.h"

void	move_prev_word(void)
{
	int pos;

	pos = g_data.pos - PROMPT_LEN;

	while (WHITESPACE(g_data.cmd_line[pos - 1]))
	{
		move_left();
		pos--;
	}
	while (!(WHITESPACE(g_data.cmd_line[pos - 1])))
	{
		move_left();
		pos--;
	}
}

void	move_next_word(void)
{
	int pos;

	pos = g_data.pos - PROMPT_LEN;

	while (!(WHITESPACE(g_data.cmd_line[pos])))
	{
		move_right();
		pos++;
	}
	while (WHITESPACE(g_data.cmd_line[pos]))
	{
		move_right();
		pos++;
	}
}

int		move_cursor_choose(char key[])
{
	if (ft_strequ(&key[1], RIGHT_ARR))
		move_right();
	else if (ft_strequ(&key[1], LEFT_ARR))
		move_left();
	else if (ft_strequ(&key[1], CTRL_LEFT))
		move_prev_word();
	else if (ft_strequ(&key[1], CTRL_RIGHT))
		move_next_word();
	else if (key[0] == BACKSPACE)
		delete_char();
	else if (ft_isprint(key[0]))
		insert_char(key);
	else
		return (0);
	return (1);
}

void	move_right(void)
{
	if (g_data.pos < CMD_LEN + PROMPT_LEN)
	{
		if ((g_data.pos + 1) % g_data.ws_col == 0)
		{
			term_cmd("do");
			term_cmd("cr");
			g_data.multi_line_count++;
		}
		else
			term_cmd("nd");
		g_data.pos++;
	}
}

void	move_left(void)
{
	if (g_data.pos > PROMPT_LEN)
	{
		if (g_data.pos % g_data.ws_col == 0)
		{
			term_cmd("up");
			tputs(tgoto(tgetstr("RI", 0), 0, g_data.ws_col), 1, &term_putchar);
			g_data.multi_line_count--;
		}
		else
			term_cmd("le");
		g_data.pos--;
	}
}
