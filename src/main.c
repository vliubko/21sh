/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 12:39:38 by vliubko           #+#    #+#             */
/*   Updated: 2018/06/07 20:07:12 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_21sh.h"

void	prompt(void)
{
	ft_putstr("$> ");
}

void	shell_init(void)
{
	g_data.pos = PROMPT_LEN;
	g_data.multi_line_count = 0;
	ft_bzero(g_data.cmd_line, 4096);
	set_raw_mode();
	//g_data.history = ft_lstnew(0, 0);
	//g_data.history_len = 0;
}

char    ***ft_convert_2dtab_to_3dtab(char **old)
{
        int     len;
        char    ***ret;

        len = 0;
        while (old[len])
            len++;
        ret = (char***)malloc(sizeof(ret) * (len + 1));
        ret[len] = NULL;

        int i = 0;
        while (i < len)
        {
            ret[i] = ft_strsplit_whitespaces(old[i]);
            i++;
        }
        return (ret);
}

int		multi_commands(char **commands)
{
    int		i;
    char	**d2_tab;
    char    ***d3_tab;
    int		ret;

    i = -1;
    while (commands[++i])
    {
        //tild_replace_home() TILD REPLACE HERE
        d2_tab = ft_strsplit(commands[i], '|');
        d3_tab = ft_convert_2dtab_to_3dtab(d2_tab);
        ft_free_2d_array(d2_tab);
        ret = exe_command(d3_tab);

        if (ret == -1)
            return (-1);
    }
    return (0);
}

void    start_exec(void)
{
    char	**commands;
    int     ret;

    //ADD HISTORY HERE
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
	char 	key[8];

    prompt();
	while (42)
	{
		get_winsize();
		ft_bzero(key, 8);
		signals();
		read(0, &key, 8);
		if (key[0] == ENTER)
		{
			start_exec();
			continue ;
		}
		move_cursor_choose(key);
	}
}

int main (int ac, char **av, char **env)
{
    env_init(ac, av, env);
	shell_init();
	shell_loop();
	return (0);
}

