/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <vliubko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 13:57:10 by vliubko           #+#    #+#             */
/*   Updated: 2018/06/08 15:00:46 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_21sh.h"

void	sig_callback(int signo)
{
	if (signo == SIGABRT || signo == SIGSTOP ||
		signo == SIGKILL || signo == SIGQUIT || signo == SIGTERM)
		exit_signal();
	else if (signo == SIGINT)
		handle_ctrl_c();
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
