/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <vliubko@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 12:39:38 by vliubko           #+#    #+#             */
/*   Updated: 2018/05/21 16:59:08 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_21sh.h"

void	prompt(void)
{
	ft_putstr("$> ");
}

int 	check_arrows(char key[])
{
	if (key[0] != 27)
			return (0);
	if (ft_strequ(&key[1], UP_ARR) || ft_strequ(&key[1], DOWN_ARR) ||
			ft_strequ(&key[1], LEFT_ARR)  || ft_strequ(&key[1], RIGHT_ARR))
		return (1);
	return (0);
}

int 	count_cmd_length_multiline(void)
{
	int 	line_length;
	int 	total_length;

	total_length = CMD_LEN + PROMPT_LEN;
	//ft_putnbr(total_length);
	//ft_putnbr(g_data.win.ws_col);
	line_length = total_length - ((g_data.multi_line_count) * g_data.win.ws_col);
	//ft_putnbr(line_length);
	return (line_length);
}

void	move_cursor(char key[])
{
	if (g_data.multi_line_count)
	{
		if (ft_strequ(&key[1], RIGHT_ARR) && g_data.pos < count_cmd_length_multiline())
		{
			term_cmd("nd");
			g_data.pos++;
		}
		else if (ft_strequ(&key[1], LEFT_ARR))
		{
			term_cmd("le");
			g_data.pos--;
		}
	}
	else if (ft_strequ(&key[1], RIGHT_ARR) && g_data.pos < PROMPT_LEN + CMD_LEN)
	{
		term_cmd("nd");
		g_data.pos++;
	}
	else if (ft_strequ(&key[1], LEFT_ARR) && g_data.pos > 3)
	{
		term_cmd("le");
		g_data.pos--;
	}
}

void    insert_char(char *key)
{
    char    *tail;
    char    *tail_new;
    int     tail_size;
    int     pos;

    pos = g_data.pos - PROMPT_LEN;

    tail_size = ft_strlen(g_data.cmd_line) - pos;
    tail = ft_strsub(g_data.cmd_line, pos, tail_size);
    tail_new = ft_strjoin(key, tail);
    ft_strdel(&tail);

    ft_strncpy(&g_data.cmd_line[pos], tail_new, ft_strlen(tail_new));

    ft_putstr(tail_new);

    int len = ft_strlen(tail_new);
    while (--len > 0)
        term_cmd("le");
    g_data.pos++;
    ft_strdel(&tail_new);
}

int main (int ac, char **av, char **env)
{
	char 	key[8];

	(void)ac;
	(void)av;
	(void)env;

	set_raw_mode();
	get_winsize(&g_data.win);
	prompt();
	g_data.pos = PROMPT_LEN;
	g_data.multi_line_count = 0;
	g_data.line_pos = 0;
	while (42)
	{
		ft_bzero(key, 8);
		read(0, key, 8);
		if ((int)key[0] == ENTER || (int)key[0] == ENTER_1)
		{
			ft_putstr("\ncommand: ");
			ft_putstr(g_data.cmd_line);
			ft_putstr("***length: ");
			ft_putnbr(ft_strlen(g_data.cmd_line));
			ft_bzero(g_data.cmd_line, 4096);
			ft_putstr("\n");
			prompt();
			g_data.pos = PROMPT_LEN;
			continue ;
		}
		if (check_arrows(key))
			move_cursor(key);
        else if ((int)key[0] == BACKSPACE || (int)key[0] == BACKSPACE_1)
        {
            ft_putstr("hello");
            int len = 5;
            while (--len > 0)
                term_cmd("le");
        }
		else if (ft_isprint(key[0]))
		{
            insert_char(key);
		}
		if (ft_strequ(g_data.cmd_line, "exit"))
			exit_signal();
		if (g_data.pos == g_data.win.ws_col)
		{
			g_data.pos = 0;
			g_data.multi_line_count++;
			g_data.line_pos++;
		}
	}
	return (0);
}

