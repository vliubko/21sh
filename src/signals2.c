/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 14:58:41 by vliubko           #+#    #+#             */
/*   Updated: 2018/06/09 11:09:47 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_21sh.h"

void	handle_winch(void)
{
	char	buf[4];

	buf[0] = -55;
	ioctl(STDERR_FILENO, TIOCSTI, buf);
	get_winsize();
}

void	handle_continue(void)
{
	clear_cmd_line();
	g_data.pos = PROMPT_LEN;
	term_cmd("cl");
	set_raw_mode();
	handle_winch();
	prompt();
}

void	handle_stop(void)
{
	set_default_mode();
	signal(SIGTSTP, SIG_DFL);
	ioctl(STDERR_FILENO, TIOCSTI, "\032");
}

void	handle_ctrl_c(void)
{
	clear_cmd_line();
	ft_putstr("\n\n");
	prompt();
	g_data.pos = PROMPT_LEN;
	signal(SIGINT, sig_callback);
}