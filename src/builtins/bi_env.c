/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:06:00 by vliubko           #+#    #+#             */
/*   Updated: 2018/06/04 16:06:00 by vliubko          ###   ########.fr       */
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