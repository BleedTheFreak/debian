/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaya <ytaya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:38:05 by ytaya             #+#    #+#             */
/*   Updated: 2021/12/13 15:20:00 by ytaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_error(char *message)
{
	printf("\033[0;31mError : %s", message);
	exit(0);
}

void	ft_setzero(t_game *game)
{
	game->n_collect = 0;
	game->n_exits = 0;
	game->n_players = 0;
	game->x_player = 0;
	game->y_player = 0;
	game->n_moves = 0;
	game->m_exit = 0;
}

void	ft_create_window(t_game *game, char *map_name)
{
	ft_check_extension(map_name, game);
	game->mlx = mlx_init();
	game->wind = mlx_new_window(game->mlx,
			game->width * FR, game->height * FR, "so_long");
	ft_map_parse(game, 0);
}
