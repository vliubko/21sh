/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <vliubko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 12:39:38 by vliubko           #+#    #+#             */
/*   Updated: 2018/06/08 18:59:40 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_21sh.h"

void	ft_free_3d_array(char ***av)
{
	int		i;

	if (!av)
		return ;
	i = -1;
	while (av[++i])
		ft_free_2d_array(av[i]);
	free(av);
}

int		multi_commands(char **commands)
{
	int		i;
	char	**d2_tab;
	char	***d3_tab;
	int		ret;

	i = -1;
	while (commands[++i])
	{
		d2_tab = ft_strsplit(commands[i], '|');
		d3_tab = ft_convert_2dtab_to_3dtab(d2_tab);
		start_replace(d3_tab);
		ft_free_2d_array(d2_tab);
		ret = exe_command(d3_tab);
		ft_free_3d_array(d3_tab);
		if (ret == -1)
			return (-1);
	}
	return (0);
}

void	start_exec(void)
{
	char	**commands;
	int		ret;

	ft_putstr("\n");
	commands = ft_strsplit(g_data.cmd_line, ';');
	ret = multi_commands(commands);
	ft_free_2d_array(commands);
	clear_cmd_line();
	if (ret == -1)
		exit_signal();
	ft_putstr("\n");
	prompt();
	g_data.pos = PROMPT_LEN;
}

void	shell_loop(void)
{
	char	key[8];

	prompt();
	signals();
	while (42)
	{
		get_winsize();
		ft_bzero(key, 8);
		read(0, &key, 8);
		if (key[0] == ENTER)
		{
			start_exec();
			continue ;
		}
		move_cursor_choose(key);
	}
}

int		main(int ac, char **av, char **env)
{
	env_init(ac, av, env);
	shell_init();
	shell_loop();
	return (0);
}
