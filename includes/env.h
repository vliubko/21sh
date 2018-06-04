/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 14:22:39 by vliubko           #+#    #+#             */
/*   Updated: 2018/06/04 14:28:13 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
#define ENV_H

typedef	struct		s_env
{
    char			*key;
    char			*value;
    struct s_env	*next;
}					t_env;

t_env				*g_env;

char				**list_to_array(void);
char	            *get_env_value_by_name(char *key);
void	            change_env_value_by_name(char *key, char *value);
void	            env_init(int ac, char **av, char **envp);

#endif
