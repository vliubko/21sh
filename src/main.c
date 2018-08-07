/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 12:39:38 by vliubko           #+#    #+#             */
/*   Updated: 2018/07/20 10:45:33 by vliubko          ###   ########.fr       */
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

char 	***debug_3d(void)
{
	char ***ret;
	int 	len = 1;
	//int 	i = 0;

	ret = (char***)malloc(sizeof(ret) * (len + 1));
	ret[len] = NULL;

	ret[0] = ft_strsplit_whitespaces("ls > test");
	return (ret);
}

int		multi_commands(char **commands)
{
	int		i;
	char	**d2_tab;
	char	***d3_tab;
	int		ret;
	static int 	redirect_fd;

	i = -1;
	while (commands[++i])
	{
		d2_tab = ft_strsplit(commands[i], '|');
		//var_dump(d2_tab);
		//d3_tab = ft_convert_2dtab_to_3dtab(d2_tab);

		d3_tab = debug_3d();
		//var_dump_3d_tab(d3_tab);
		start_replace(d3_tab);
		if (ft_has_redirect(d3_tab))
		{
			redirect_fd = ft_redirection(d3_tab);
		}
		ft_free_2d_array(d2_tab);
		ret = exe_command(d3_tab);
		ft_free_3d_array(d3_tab);
		if (redirect_fd)
		{
			redirect_fd = 0;
			dup2(1, redirect_fd);
		}
		if (ret == -1)
			return (-1);
	}
	return (0);
}

void	start_exec(void)
{
	char	**commands;
	int		ret;

    quotes_start();
	ft_putstr("\n");
	add_to_history();
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
	shell_init(av);
	shell_loop();
	return (0);
}
