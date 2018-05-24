/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_mode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <vliubko@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 16:31:26 by vliubko           #+#    #+#             */
/*   Updated: 2018/05/18 17:05:19 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_21sh.h"

void	set_raw_mode(void)
{
	if (!isatty(0))
		ft_error("Stdin not terminal\n");
	if (tgetent(NULL, getenv("TERM")) == -1)
		ft_error("Can't find TERM in env\n");
	if (tcgetattr(0, &g_data.tty) == -1)
		ft_error("Can't get attr terminal\n");
	tcgetattr(0, &g_data.savetty);
	g_data.tty.c_lflag &= ~ECHO;
	g_data.tty.c_lflag &= ~ICANON;
	g_data.tty.c_cc[VMIN] = 1;
	if (tcsetattr(0, TCSAFLUSH, &g_data.tty))
		ft_error("Can't set attr terminal\n");
}

void	set_default_mode(void)
{
	if (tcsetattr(0, TCSAFLUSH, &g_data.savetty))
		ft_error("Can't set attr terminal\n");
}
