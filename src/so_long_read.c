/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaya <ytaya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:38:10 by ytaya             #+#    #+#             */
/*   Updated: 2021/12/13 15:09:20 by ytaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_read_map(t_game *game, char *map_name)
{
	int		fd;
	char	*join;
	char	*temp;

	fd = open(map_name, O_RDONLY);
	game->tmp = ft_strdup("");
	game->height = 0;
	while (1)
	{
		join = get_next_line(fd);
		if (!join)
			break ;
		if (*join == '\n')
			ft_print_error("Invalid map ! \n");
		temp = game->tmp;
		game->tmp = ft_strjoin(game->tmp, join);
		free(temp);
		free(join);
		game->height++;
	}
	game->map = ft_split(game->tmp, '\n');
	game->width = ft_strlen((game->map[0]));
	ft_map_checker(game);
}

void	ft_count_chars(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	ft_setzero(game);
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				game->n_collect++;
			else if (game->map[i][j] == 'P')
			{
				game->n_players++;
			}
			else if (game->map[i][j] == 'E')
				game->n_exits++;
			else if (game->map[i][j] != '1' && game->map[i][j] != '0')
				ft_print_error("your map have undefined charachters !\n");
			j++;
		}
		i++;
	}
}

void	ft_seturls(t_game *game)
{
	game->wall.wall_path = "imgs/wall.xpm";
	game->empty.empty_path = "imgs/empty.xpm";
	game->collect.collect_path = "imgs/collect.xpm";
	game->exit.exit_path = "imgs/exit.xpm";
	game->player.player_path = "imgs/player.xpm";
}

void	ft_draw(t_game *game, int i, int j)
{
	if (game->map[i][j] == '1')
		game->wall.imgptr = mlx_xpm_file_to_image(game->mlx,
				game->wall.wall_path, &game->t, &game->t);
	else if (game->map[i][j] == '0')
		game->empty.imgptr = mlx_xpm_file_to_image(game->mlx,
				game->empty.empty_path, &game->t, &game->t);
	else if (game->map[i][j] == 'C')
		game->collect.imgptr = mlx_xpm_file_to_image(game->mlx,
				game->collect.collect_path, &game->t, &game->t);
	else if (game->map[i][j] == 'E')
		game->exit.imgptr = mlx_xpm_file_to_image(game->mlx,
				game->exit.exit_path, &game->t, &game->t);
	else if (game->map[i][j] == 'P')
		game->player.imgptr = mlx_xpm_file_to_image(game->mlx,
				game->player.player_path, &game->t, &game->t);
}

void	ft_putimg(t_game *game, int i, int j)
{
	if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx,
			game->wind, game->wall.imgptr, j * FR, i * FR);
	else if (game->map[i][j] == '0')
		mlx_put_image_to_window(game->mlx,
			game->wind, game->empty.imgptr, j * FR, i * FR);
	else if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx,
			game->wind, game->collect.imgptr, j * FR, i * FR);
	else if (game->map[i][j] == 'E')
		mlx_put_image_to_window(game->mlx,
			game->wind, game->exit.imgptr, j * FR, i * FR);
	else if (game->map[i][j] == 'P')
	{
		game->y_player = i;
		game->x_player = j;
		mlx_put_image_to_window(game->mlx,
			game->wind, game->player.imgptr, j * FR, i * FR);
	}
}
