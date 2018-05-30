/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_editing.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 12:49:04 by vliubko           #+#    #+#             */
/*   Updated: 2018/05/30 13:47:06 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_EDITING_H
# define LINE_EDITING_H

# define LEFT_ARR	"[D"
# define RIGHT_ARR	"[C"
# define CTRL_RIGHT "[1;5C"
# define CTRL_LEFT  "[1;5D"

# define PROMPT_LEN 3
# define CMD_LEN	(int)ft_strlen(g_data.cmd_line)

int					move_cursor_choose(char key[]);
void				move_right(void);
void				move_left(void);
void				move_prev_word(void);
void				move_next_word(void);
void    			insert_char(char *key);
void				delete_char(void);
void				clear_cmd_line(void);
void				realloc_cmd_line(char *head, char *new_tail);

#endif
