/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 12:39:38 by vliubko           #+#    #+#             */
/*   Updated: 2018/06/04 15:04:53 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_21sh.h"

void	prompt(void)
{
	ft_putstr("$> ");
}

//int 	count_cmd_length_multiline(void)
//{
//	int 	line_length;
//	int 	total_length;
//
//	total_length = CMD_LEN + PROMPT_LEN;
//	line_length = total_length - ((g_data.multi_line_count) * g_data.win.ws_col);
//	return (line_length);
//}

//void	ft_putstr_old(char const *s)
//{
//    if (!s)
//        return ;
//	while (*s != '\0')
//	{
//		ft_putchar(*s);
//		s = s + 1;
//	}
//}

void	shell_init(void)
{
	g_data.pos = PROMPT_LEN;
	g_data.multi_line_count = 0;
	ft_bzero(g_data.cmd_line, 4096);
	set_raw_mode();
	//g_data.history = ft_lstnew(0, 0);
	//g_data.history_len = 0;
}

//void	history_add(void)
//{
//	g_data.history_len++;
//	ft_lst_pushback(&g_data.history, ft_lstnew(g_data.cmd_line, CMD_LEN));
//}
//
//void	history_print(void)
//{
//	t_list	*tmp;
//	int 	i;
//
//	tmp = g_data.history->next;
//	i = 1;
//	while (tmp)
//	{
//		if (i == 1)
//			ft_putstr("\n");
//		ft_putnbr(i++);
//		ft_putstr("  ");
//		ft_putendl(tmp->content);
//		tmp = tmp->next;
//	}
//}

void	shell_loop(void)
{
	char 	key[8];
    char	**commands;
    int     ret;

    prompt();
	while (42)
	{
		get_winsize();
		ft_bzero(key, 8);
		signals();
		read(0, &key, 8);
		if (key[0] == ENTER)
		{
			//history_add();
			ft_putstr("\n");
			//ft_putstr(g_data.cmd_line);
            commands = ft_strsplit_whitespaces(g_data.cmd_line);
			ret = exe_command(commands);
            if (ret == -1)
                exit_signal();
            clear_cmd_line();
			ft_putstr("\n");
			prompt();
			g_data.pos = PROMPT_LEN;
			continue ;
		}
		move_cursor_choose(key);
		if (ft_strequ(g_data.cmd_line, "exit"))
			exit_signal();
	}
}

int main (int ac, char **av, char **env)
{
    env_init(ac, av, env);
	shell_init();
	shell_loop();
	return (0);
}

