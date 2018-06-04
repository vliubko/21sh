/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 14:28:22 by vliubko           #+#    #+#             */
/*   Updated: 2018/06/04 14:40:45 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
#define BUILTINS_H

int				bi_cd(char **arg);
int				cd_standart(char *path);
char			*tild_replace_home(char *line);
int		        bi_env(void);

#endif
