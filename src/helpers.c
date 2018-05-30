/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 16:41:36 by vliubko           #+#    #+#             */
/*   Updated: 2018/05/30 12:44:56 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_21sh.h"

void	get_winsize(void)
{
	g_data.ws_col = tgetnum("co");
}

int		term_putchar(int c)
{
	write(2, &c, 1);
	return (1);
}

void	term_cmd(char *cmd)
{
	tputs(tgetstr(cmd, NULL), 1, &term_putchar);
}

int		ft_error(char *str)
{
	ft_putstr_fd(RED_FONT, 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(COLOR_OFF, 2);
	exit(1);
}
