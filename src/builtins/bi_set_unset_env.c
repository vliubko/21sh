/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_set_unset_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 11:31:44 by vliubko           #+#    #+#             */
/*   Updated: 2018/06/08 13:03:41 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_21sh.h"

int		bi_env(void)
{
	t_env	*print;

	print = g_env;
	while (print)
	{
		ft_putstr(print->key);
		ft_putstr("=");
		ft_putendl(print->value);
		print = print->next;
	}
	return (1);
}

int		check_forbidden_env(char *key)
{
	if (!ft_strequ(key, "HOME") && !ft_strequ(key, "PWD") &&
		!ft_strequ(key, "OLDPWD") && !ft_strequ(key, "USER") &&
		!ft_strequ(key, "LOGNAME"))
		return (0);
	ft_putstr_fd("Forbidden to set/unset: HOME, PWD, OLDPWD, USER, LOGNAME\n", 2);
	return (1);
}

int		bi_unsetenv(char **command)
{
	char	*key;
	char	*find;

	if (!command[0] || command[1])
		ft_putstr_fd("Usage: unsetenv NAME\n", 2);
	key = command[0];
	if (check_forbidden_env(key))
		return (1);
	if ((find = get_env_value_by_name(key)))
	{
		remove_env_value_by_name(key);
		ft_strdel(&find);
	}
	else
	{
		ft_putstr_fd(key, 2);
		ft_putstr_fd(" not found in env\n", 2);
	}
	return (1);
}

int		bi_setenv(char **command)
{
	char	*key;
	char	*value;
	char	*find;

	if (!command[0] || command[1] || !(ft_strchr(command[0], '=')) ||
		command[0][0] == '=')
		ft_putstr_fd("Usage: setenv [NAME]=[VALUE]\n", 2);
	else
	{
		key = ft_strsub(command[0], 0, ft_strchr(command[0], '=') - command[0]);
		if (check_forbidden_env(key) != 1)
		{
			value = ft_strchr(command[0], '=') + 1;
			if ((find = get_env_value_by_name(key)))
			{
				change_env_value_by_name(key, value);
				ft_strdel(&find);
			}
			else
				add_env_value(key, value);
		}
		(key) ? ft_strdel(&key) : 0;
	}
	return (1);
}
