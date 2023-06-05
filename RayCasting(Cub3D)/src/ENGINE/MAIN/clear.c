/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msenipek <msenipek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 06:48:46 by aozsayar          #+#    #+#             */
/*   Updated: 2023/06/03 20:15:15 by msenipek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/f_engine.h"
#include "../../../include/cub3d.h"

int	clear_game(t_game *game)
{
	if (game)
	{
		game->game_status = GAME_CLOSE;
		if (game->window)
			mlx_destroy_window(game->mlx, game->window);
		if (game->elements)
			clear_elements(game->elements);
		if (game->map)
			delete_object(game->mlx, &game->map);
		if (game->mini_map)
			delete_object(game->mlx, &game->mini_map);
		if (game->assets)
			clear_assets(game);
		if (game->screen)
			delete_object(game->mlx, &game->screen);
		if (game->additon)
			clear_char(game, game->additon);
		free(game->lc);
		free(game);
	}
	exit(EXIT_SUCCESS);
}

void	clear_elements(t_elements *elements)
{
	t_list	*list;

	list = elements->map;
	if (elements->ea)
		free(elements->ea);
	if (elements->we)
		free(elements->we);
	if (elements->no)
		free(elements->no);
	if (elements->so)
		free(elements->so);
	node_clear(&list);
	array_clear(&elements->map_array);
	free(elements);
}

void	clear_assets(t_game *game)
{
	if (game->assets->eastwall)
		delete_object(game->mlx, &(game->assets->eastwall));
	if (game->assets->north_wall)
		delete_object(game->mlx, &(game->assets->north_wall));
	if (game->assets->south_wall)
		delete_object(game->mlx, &(game->assets->south_wall));
	if (game->assets->west_wall)
		delete_object(game->mlx, &(game->assets->west_wall));
	free(game->assets);
}

void	raise_error(t_game *game, char *error_msg)
{
	printf("%s\n", error_msg);
	clear_game(game);
}
