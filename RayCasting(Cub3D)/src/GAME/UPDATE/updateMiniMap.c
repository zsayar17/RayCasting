/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updateMiniMap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozsayar <aozsayar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 07:01:55 by aozsayar          #+#    #+#             */
/*   Updated: 2023/06/03 07:01:56 by aozsayar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	fillemptyside(t_object *obj, int color)
{
	int	i;
	int	j;
	int	dif[2];
	int	r;

	i = -1;
	r = obj->w >> 1;
	while (++i < obj->h)
	{
		j = -1;
		while (++j < obj->w)
		{
			dif[X] = i - r;
			dif[Y] = j - r;
			if (dif[X] * dif[X] + dif[Y] * dif[Y]
				< r * r && getobjectcolor(obj, j, i))
				colorize_object(obj, color, j, i);
		}
	}
}

void	updateminimap(t_game *game)
{
	int	pos[2];

	pos[X] = ((t_char *)game->additon)->pos[X] / (PIXEL_SIZE / MP_PIXEL_SIZE);
	pos[Y] = ((t_char *)game->additon)->pos[Y] / (PIXEL_SIZE / MP_PIXEL_SIZE);
	clear_object(game->mini_map);
	copy_object(game->mini_map, game->map, pos, RED);
	fillemptyside(game->mini_map, GREEN);
}
