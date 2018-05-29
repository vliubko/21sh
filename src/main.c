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
	if (ft_strequ(&key[1], CTRL_LEFT) || ft_strequ(&key[1], CTRL_RIGHT) ||
			ft_strequ(&key[1], LEFT_ARR)  || ft_strequ(&key[1], RIGHT_ARR))
		return (1);
	return (0);
}

int 	count_cmd_length_multiline(void)
{
	int 	line_length;
	int 	total_length;

	total_length = CMD_LEN + PROMPT_LEN;
	line_length = total_length - ((g_data.multi_line_count) * g_data.win.ws_col);
	return (line_length);
}

void	move_right(void)
{
	if (g_data.pos < CMD_LEN + PROMPT_LEN && g_data.win.ws_col)
	{
		if ((g_data.pos + 1) % g_data.win.ws_col == 0)
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
		if (g_data.pos % g_data.win.ws_col == 0)
		{
			term_cmd("up");
			tputs(tgoto(tgetstr("RI", 0), 0, g_data.win.ws_col), 1, &term_putchar);
			g_data.multi_line_count--;
		}
		else
			term_cmd("le");
		g_data.pos--;
	}
}

void	move_prev_word(void) {
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

void	move_cursor(char key[])
{

	if (ft_strequ(&key[1], RIGHT_ARR)) {
		move_right();
	}
	else if (ft_strequ(&key[1], LEFT_ARR)) {
		move_left();
	}
	else if (ft_strequ(&key[1], CTRL_LEFT))
		move_prev_word();
	else if (ft_strequ(&key[1], CTRL_RIGHT))
		move_next_word();
}

void	ft_putstr_old(char const *s)
{
    if (!s)
        return ;
	while (*s != '\0')
	{
		ft_putchar(*s);
		s = s + 1;
	}
}

void    insert_char(char *key)
{
    int     pos;
    char    *tail;
    char    *new_tail;
    char    *head;
	int 	len;
	int 	cmd_len;

	cmd_len = (int)ft_strlen(g_data.cmd_line);
    pos = g_data.pos - PROMPT_LEN;
    tail = ft_strsub(g_data.cmd_line, pos, cmd_len - pos);
	head = ft_strsub(g_data.cmd_line, 0, pos);
	new_tail = ft_strjoin(key, tail);
    ft_bzero(g_data.cmd_line, 4096);
    ft_strcat(g_data.cmd_line, head);
    ft_strcat(g_data.cmd_line, new_tail);

	term_cmd("cd");
	
    ft_putstr_old(new_tail);

    len = (int)ft_strlen(tail);
//		ft_putstr_fd("len: ", 2);
//		write(2, ft_itoa(len), ft_strlen(ft_itoa(len)));
//		ft_putstr_fd("tail: ", 2);
//		ft_putendl_fd(tail, 2);
//		ft_putstr_fd("cmd_line: ", 2);
//		ft_putendl_fd(g_data.cmd_line, 2);

	tputs(tgoto(tgetstr("LE", 0), 0, len + 1), 1, &term_putchar);

	move_right();
//    while (len-- > 0)
//	{
//		term_cmd("le");
//		//g_data.pos--;
//	}
	//g_data.pos++;
    ft_strdel(&tail);
    ft_strdel(&head);
	ft_strdel(&new_tail);
	g_data.save_g_pos = g_data.pos;
	g_data.save_pos = pos;
//	ft_putstr_fd("g_data.pos: ", 2);
//	write(2, ft_itoa(g_data.pos), ft_strlen(ft_itoa(g_data.pos)));
//	ft_putstr_fd("pos: ", 2);
//	write(2, ft_itoa(pos), ft_strlen(ft_itoa(pos)));
//	ft_putstr_fd(" ,CMD_LEN: ", 2);
//	write(2, ft_itoa(cmd_len), ft_strlen(ft_itoa(cmd_len)));
//	ft_putstr_fd("\n", 2);

}

void	shell_init(void)
{
	g_data.pos = PROMPT_LEN;
	g_data.multi_line_count = 0;
	g_data.line_pos = 0;
	ft_bzero(g_data.cmd_line, 4096);
	get_winsize(&g_data.win);
	set_raw_mode();
}

void	shell_loop(void)
{
	char 	key[8];

	prompt();
	while (42)
	{
		ft_bzero(key, 8);
		signals();
		read(0, &key, 8);
		if (key[0] == ENTER)
		{
			ft_putstr("\n21sh: command not found: ");
			ft_putstr(g_data.cmd_line);
			ft_bzero(g_data.cmd_line, 4096);
			ft_putstr("\n");
			prompt();
			g_data.pos = PROMPT_LEN;
			continue ;
		}
		if (check_arrows(key))
			move_cursor(key);
		else if (ft_isprint(key[0])) {
			insert_char(key);
		}
		if (ft_strequ(g_data.cmd_line, "exit"))
			exit_signal();
	}
}

int main (int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	(void)env;

	shell_init();
	shell_loop();
	return (0);
}

