/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <vliubko@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 16:48:28 by vliubko           #+#    #+#             */
/*   Updated: 2018/05/18 16:58:27 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_21sh.h"

void		exit_signal(void)
{
	//ft_free_select(data);
	set_default_mode();
	exit(0);
}

void	handle_winch(void)
{
	char	buf[4];

	buf[0] = -55;
	ioctl(STDERR_FILENO, TIOCSTI, buf);
}

void	handle_continue(void)
{
	term_cmd("cl");
	set_raw_mode();
	handle_winch();
}

void	handle_stop(void)
{
	set_default_mode();
	signal(SIGTSTP, SIG_DFL);
	ioctl(STDERR_FILENO, TIOCSTI, "\032");
}

void	sig_callback(int signo)
{
	if (signo == SIGINT || signo == SIGABRT || signo == SIGSTOP ||
		signo == SIGKILL || signo == SIGQUIT || signo == SIGTERM)
		exit_signal();
	else if (signo == SIGWINCH)
		handle_winch();
	else if (signo == SIGTSTP)
		handle_stop();
	else if (signo == SIGCONT)
		handle_continue();
}

void	signals(void)
{
	signal(SIGINT, sig_callback);
	signal(SIGABRT, sig_callback);
	signal(SIGSTOP, sig_callback);
	signal(SIGKILL, sig_callback);
	signal(SIGQUIT, sig_callback);
	signal(SIGWINCH, sig_callback);
	signal(SIGTSTP, sig_callback);
	signal(SIGCONT, sig_callback);
	signal(SIGTERM, sig_callback);
}
