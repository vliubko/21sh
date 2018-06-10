/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_editing.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 12:49:04 by vliubko           #+#    #+#             */
/*   Updated: 2018/06/10 10:23:29 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_EDITING_H
# define LINE_EDITING_H

# define LEFT_ARR	"[D"
# define RIGHT_ARR	"[C"
# define CTRL_RIGHT	"[1;5C"
# define CTRL_LEFT	"[1;5D"
# define CTRL_UP	"[1;5A"
# define CTRL_DOWN	"[1;5B"
# define END		"[F"
# define HOME		"[H"

# define PROMPT_LEN 3
# define CMD_LEN	(int)ft_strlen(g_data.cmd_line)

typedef	struct			s_history
{
	char				**line;
	int					len;
	int 				index;
}						t_history;

int					move_cursor_choose(char key[]);
void				move_right(void);
void				move_left(void);
void				move_prev_word(void);
void				move_next_word(void);
void				move_cursor_home(void);
void				move_cursor_end(void);
void				insert_char(char *key);
void				delete_char(void);
void				clear_cmd_line(void);
void				realloc_cmd_line(char *head, char *new_tail);
void				history_init(void);
void				add_to_history(void);
int					display_history(void);

#endif
