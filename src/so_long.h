/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaya <ytaya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:37:41 by ytaya             #+#    #+#             */
/*   Updated: 2021/12/13 19:29:31 by ytaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "../libft/libft.h"
# include <mlx.h>
# define FR 64
# define BUFFER_SIZE 1337

typedef struct s_wall
{
	void	*imgptr;
	int		img_height;
	int		img_width;
	char	*wall_path;
}	t_wall;

typedef struct s_collect
{
	void	*imgptr;
	int		img_height;
	int		img_width;
	char	*collect_path;
}	t_collect;

typedef struct s_empty
{
	void	*imgptr;
	int		img_height;
	int		img_width;
	char	*empty_path;
}	t_empty;

typedef struct s_player
{
	void	*imgptr;
	int		img_height;
	int		img_width;
	char	*player_path;
}	t_player;

typedef struct s_exit
{
	void	*imgptr;
	int		img_height;
	int		img_width;
	char	*exit_path;
}	t_exit;

typedef struct s_game
{
	void		*mlx;
	void		*wind;
	char		**map;
	char		*tmp;
	int			height;
	int			width;
	int			n_players;
	int			n_exits;
	int			n_collect;
	int			n_moves;
	t_exit		exit;
	t_wall		wall;
	t_player	player;
	t_collect	collect;
	t_empty		empty;
	int			y_player;
	int			x_player;
	int			t;
	int			m_exit;
	int			file_is_empty;
}	t_game;

void	ft_free(char **str);
void	ft_get_line(char **rest, char **line);
void	ft_read(int fd, char **rest, char **line, char **buffer);
char	*get_next_line(int fd);
void	ft_map_checker(t_game *game);
void	ft_count_chars(t_game *game);
void	ft_last_check(t_game *game);
void	ft_check_rect(t_game *game);
void	ft_read_map(t_game *game, char *map_name);
void	ft_check_extension(char *map_name, t_game *game);
void	ft_setzero(t_game *game);
void	ft_seturls(t_game *game);
void	ft_mapchaner(t_game *game, int keycode);
void	ft_lunch(t_game *game, char *game_name);
int		ft_move(int keycode, t_game *game);
int		ft_loop(t_game *game);
int		ft_close(t_game *game);
void	ft_moveto(t_game *game, int i, int j);
void	ft_create_window(t_game *game, char *map_name);
void	ft_print_error(char *message);
void	ft_setzero(t_game *game);
void	ft_draw(t_game *game);
void	ft_putimg(t_game *game, int i, int j);
void	ft_map_parse(t_game *game, int parse);
void	ft_swap(t_game *game, int i, int j);
void	ft_file_empty(char *map_name, t_game *game);

#endif