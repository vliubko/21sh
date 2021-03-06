/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_basic_moves.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 12:38:16 by vliubko           #+#    #+#             */
/*   Updated: 2018/06/10 15:46:28 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_21sh.h"

void	move_up_multiline(void)
{
	int		i;
	int		line_up;

	line_up = g_data.ws_col;
	i = 0;
	while (i++ < line_up)
		move_left();
}

void	move_down_multiline(void)
{
	int		i;
	int		line_down;

	i = 0;
	line_down = g_data.ws_col;
	while (i++ < line_down)
		move_right();
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
	else if (ft_strequ(&key[1], HOME))
		move_cursor_home();
	else if (ft_strequ(&key[1], END))
		move_cursor_end();
	else if (ft_strequ(&key[1], CTRL_UP))
		move_up_multiline();
	else if (ft_strequ(&key[1], CTRL_DOWN))
		move_down_multiline();
	else if (ft_strequ(&key[1], UP_ARR) || ft_strequ(&key[1], DOWN_ARR))
		history_processing(key);
	else if (key[0] == BACKSPACE)
		delete_char();
	else if (ALT_V || ALT_C)
		copy_paste_processing(key);
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
