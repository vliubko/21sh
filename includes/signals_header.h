/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_header.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <vliubko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 13:55:26 by vliubko           #+#    #+#             */
/*   Updated: 2018/06/08 15:00:11 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_HEADER_H
# define SIGNALS_HEADER_H

void	handle_winch(void);
void	handle_continue(void);
void	handle_stop(void);
void	handle_ctrl_c(void);

#endif
