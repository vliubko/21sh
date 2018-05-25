/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_21sh.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <vliubko@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 14:40:30 by vliubko           #+#    #+#             */
/*   Updated: 2018/05/21 16:46:54 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_21SH_H
# define FT_21SH_H

# include "../libft/includes/libft.h"
# include <sys/ioctl.h>
# include <termios.h>
# include <term.h>
# include <signal.h>
# include <termcap.h>

# define BOLD_WHINE_FONT "\e[1;37m"
# define BG_COLOR "\e[48;5;29m"
# define RED_FONT "\033[1;31m"
# define CYAN_FONT "\e[1;36m"
# define PURPLE_FONT "\e[1;35m"
# define YELLOW_FONT "\e[38;5;226m"
# define COLOR_OFF "\e[0m"
# define ESC 		32539
# define ESC_ALTERN	27
# define BACKSPACE	127
# define BACKSPACE_1 32639
# define DEL			2117294875
# define ENTER		10
# define SPACE		32544
# define SPACE_1		32
# define UP_ARR		"[A"
# define DOWN_ARR	"[B"
# define LEFT_ARR	"[D"
# define RIGHT_ARR	"[C"

# define PROMPT_LEN 3
# define CMD_LEN	(int)ft_strlen(g_data.cmd_line)

typedef struct		s_args
{
	char			*value;
	int				select;
	int				underline;
	int				type;
	int				row;
	struct s_args	*next;
	struct s_args	*prev;
}					t_args;

typedef struct		s_select
{
	int				length;
	struct termios	tty;
	struct termios	savetty;
	struct winsize	win;
	struct s_args	*args;
	int				cols;
}					t_select;

typedef struct		s_shell
{
	struct termios	tty;
	struct termios	savetty;
	struct winsize	win;
	char			cmd_line[4096];
	int				pos;
	int				multi_line_count;
	int 			line_pos;
	int 			save_pos;
	int 			save_g_pos;
}					t_shell;

t_shell				g_data;

void				exit_signal(void);
void				get_winsize(struct winsize *win);
void				set_raw_mode(void);
void				set_default_mode(void);
int					ft_error(char *str);
int					term_putchar(int c);
void				signals(void);
void				term_cmd(char *cmd);

#endif