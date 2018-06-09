/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 13:00:38 by vliubko           #+#    #+#             */
/*   Updated: 2018/06/09 19:08:05 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_21sh.h"

void	shell_init(void)
{
	g_data.pos = PROMPT_LEN;
	g_data.multi_line_count = 0;
	ft_bzero(g_data.cmd_line, 4096);
	history_init();
	set_raw_mode();
}
