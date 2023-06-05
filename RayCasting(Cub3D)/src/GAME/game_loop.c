/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msenipek <msenipek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 07:13:32 by aozsayar          #+#    #+#             */
/*   Updated: 2023/06/03 20:11:07 by msenipek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/f_engine.h"
#include "../../include/cub3d.h"

void	setup(t_game *game)
{
	load_map_asset(game);
	loadmap(game);
	loadminimap(game);
	load_character(game);
	loadscreen(game);
}

void	update(t_game *game)
{
	character_move(game);
	updatescreen(game);
	updateminimap(game);
}

void	draw(t_game *game)
{
	draw_object(game, game->screen);
	draw_object(game, game->mini_map);
	draw_object(game, ((t_char *)game->additon)->obj);
}
