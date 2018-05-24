/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <vliubko@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 16:41:36 by vliubko           #+#    #+#             */
/*   Updated: 2018/05/18 16:30:54 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_21sh.h"

void	get_winsize(struct winsize *win)
{
	ioctl(0, TIOCGWINSZ, win);
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
