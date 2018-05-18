/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <vliubko@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 12:39:38 by vliubko           #+#    #+#             */
/*   Updated: 2018/05/18 18:08:27 by vliubko          ###   ########.fr       */
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

void	move_cursor(char key[])
{
	if (ft_strequ(&key[1], RIGHT_ARR))
		term_cmd("nd");
	else if (ft_strequ(&key[1], LEFT_ARR))
		term_cmd("le");
}

int main (int ac, char **av, char **env)
{
	char 	key[8];

	(void)ac;
	(void)av;
	(void)env;

	set_raw_mode();
	prompt();
	while (42)
	{
		ft_bzero(key, 8);
		read(0, key, 8);
		if ((int)key[0] == ENTER || (int)key[0] == ENTER_1)
		{
			ft_bzero(g_data.cmd_line, 4096);
			ft_putstr("\n");
			prompt();
			continue ;
		}
		if (check_arrows(key))
			move_cursor(key);
		else if (ft_isprint(key[0]))
			ft_putstr(&key[0]);
		ft_strcat(g_data.cmd_line, key);
		if (ft_strequ(g_data.cmd_line, "exit"))
			exit_signal();
	}

	return (0);
}

