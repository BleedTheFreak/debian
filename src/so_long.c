/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaya <ytaya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:38:13 by ytaya             #+#    #+#             */
/*   Updated: 2021/12/13 21:46:29 by ytaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_parse(t_game *game, int parse)
{
	int	i;
	int	j;

	if (!parse)
		ft_seturls(game);
	i = 0;
	mlx_clear_window(game->mlx, game->wind);
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (!parse)
				ft_draw(game);
			ft_putimg(game, i, j);
			j++;
		}
		i++;
	}
}

void	ft_mapchaner(t_game *game, int keycode)
{
	if (keycode == 13 || keycode == 126)
		ft_moveto(game, 1, 0);
	else if (keycode == 1 || keycode == 125)
		ft_moveto(game, -1, 0);
	else if (keycode == 0 || keycode == 123)
		ft_moveto(game, 0, 1);
	else if (keycode == 2 || keycode == 124)
		ft_moveto(game, 0, -1);
	else if (keycode == 53)
	{
		printf("\033[0;31mYou ended the game!\n");
		printf("\033[0;35mThank you for playing our game ! (^_^)\n");
		exit(0);
	}
	if (!game->m_exit)
		ft_map_parse(game, 1);
}

void	ft_lunch(t_game *game, char *game_name)
{
	ft_create_window(game, game_name);
	mlx_hook(game->wind, 02, 0L, ft_move, game);
	mlx_loop_hook(game->mlx, ft_loop, game);
	mlx_hook(game->wind, 17, 0L, ft_close, game);
	mlx_loop(game->mlx);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac == 2)
		ft_lunch(&game, av[1]);
	else
		ft_print_error("Map must entre as argument !\n");
	return (0);
}
