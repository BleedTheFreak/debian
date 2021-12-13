/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaya <ytaya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:38:02 by ytaya             #+#    #+#             */
/*   Updated: 2021/12/13 21:12:34 by ytaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_extension(char *map_name, t_game *game)
{
	char	*temp;

	ft_file_empty(map_name, game);
	temp = ft_strrchr(map_name, '.');
	if (!temp)
		ft_print_error("map extension invalide !\n");
	if (ft_strncmp(temp, ".ber", 4) || ft_strlen(temp) != 4)
		ft_print_error("map extension must be end with .ber !\n");
	ft_read_map(game, map_name);
}

void	ft_check_rect(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	ft_last_check(game);
	while (i < game->height - 1)
	{
		if (ft_strlen(game->map[i]) == ft_strlen(game->map[i + 1]))
			j++;
		i++;
	}
	if (i != j)
		ft_print_error("Invalid map !\n");
}

void	ft_last_check(t_game *game)
{
	char	*message;

	ft_count_chars(game);
	if (game->n_collect >= 1 && game->n_exits >= 1 && game->n_players == 1)
		return ;
	else if (game->n_players > 1)
		ft_print_error("Your map must have just one player ! \n");
	else
	{
		message = "Your map must have at least one of those \
: exit collectable player\n";
		ft_print_error(message);
	}
}

void	ft_map_checker(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ft_check_rect(game);
	while (game->map[0][i])
	{
		if (game->map[0][i] != '1')
			ft_print_error("Invalid map !\n");
		i++;
	}
	i = 0;
	while (game->map[i])
	{
		if (game->map[i][(game->width) - 1] != '1' || game->map[i][0] != '1')
			ft_print_error("\033[0;31mInvalid map !\n");
		i++;
	}
	i = game->width - 1;
	while (game->map[(game->height - 1)][i] && i--)
		if (game->map[game->height - 1][i] != '1')
			ft_print_error("\033[0;31mInvalid map !\n");
}
