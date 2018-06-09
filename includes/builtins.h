/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 14:28:22 by vliubko           #+#    #+#             */
/*   Updated: 2018/06/06 11:31:06 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

int				bi_cd(char **arg);
int				cd_standart(char *path);
int				bi_env(void);
int				bi_echo(char **av);
int				bi_clear(void);
int				bi_setenv(char **command);
int				bi_unsetenv(char **command);

#endif
