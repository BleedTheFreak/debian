/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaya <ytaya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:37:53 by ytaya             #+#    #+#             */
/*   Updated: 2021/12/13 15:50:47 by ytaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_move(int keycode, t_game *game)
{
	ft_mapchaner(game, keycode);
	return (0);
}

int	ft_loop(t_game *game)
{
	static int	i;

	if (game->m_exit)
		i++;
	if (i % 20000 == 0 && i > 0)
	{
		if (game->m_exit)
		{
			printf("\033[0;32mCongratulations");
			printf(" you won with %d moves !\n", game->n_moves);
			printf("\033[0;35mThank you for playing our game ! (^_^)\n");
			exit(0);
		}
	}
	return (1);
}

int	ft_close(t_game *game)
{
	(void) game;
	printf("\033[0;35mThank you for playing our game ! (^_^)\n");
	exit(0);
	return (0);
}

void	ft_moveto(t_game *game, int i, int j)
{
	if (game->map[game->y_player - i][game->x_player - j] == '0')
		ft_swap(game, i, j);
	if (game->map[game->y_player - i][game->x_player - j] == 'C')
	{
		ft_swap(game, i, j);
		game->n_collect--;
	}
	if (game->n_collect == 0)
	{
		game->exit.exit_path = "imgs/exit_open.xpm";
		game->exit.imgptr = mlx_xpm_file_to_image(game->mlx,
				game->exit.exit_path, &game->t, &game->t);
		if (game->map[game->y_player - i][game->x_player - j] == 'E')
		{
			game->m_exit = 1;
			mlx_clear_window(game->mlx, game->wind);
			mlx_string_put(game->mlx,
				game->wind, (game->width / 2) * FR, (game->height / 2) * FR,
				0x00FF00, "You Won");
		}
	}
	printf("\033[0;33mMove number ==> {%d}\n", game->n_moves);
}

void	ft_swap(t_game *game, int i, int j)
{
		game->map[game->y_player][game->x_player] = '0';
		game->map[game->y_player - i][game->x_player - j] = 'P';
		game->n_moves++;
}
