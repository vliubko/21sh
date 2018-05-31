/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_word_home_moves.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 16:51:26 by vliubko           #+#    #+#             */
/*   Updated: 2018/05/30 16:51:26 by vliubko          ###   ########.fr       */
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

void	move_cursor_home(void)
{
	while (g_data.pos > PROMPT_LEN)
		move_left();
}

void	move_cursor_end(void)
{
	while (g_data.pos < CMD_LEN + PROMPT_LEN)
		move_right();
}
