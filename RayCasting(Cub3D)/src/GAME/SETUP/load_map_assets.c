/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_assets.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozsayar <aozsayar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 06:58:39 by aozsayar          #+#    #+#             */
/*   Updated: 2023/06/03 07:31:46 by aozsayar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	putwall(void *obj, int x, int y)
{
	int	a;
	int	b;
	int	i;
	int	j;

	a = MP_PIXEL_SIZE * x;
	b = MP_PIXEL_SIZE * y;
	i = MP_PIXEL_SIZE;
	while (--i > 0)
	{
		j = MP_PIXEL_SIZE;
		while (--j > 0)
			colorize_object(obj, WHITE, a + j, b + i);
	}
}

void	loadmap(t_game *game)
{
	t_list	*list;
	char	*line;
	int		x;
	int		y;

	game->map = create_object(game->mlx, NULL, game->width * MP_PIXEL_SIZE,
			game->height * MP_PIXEL_SIZE);
	list = game->elements->map;
	y = 0;
	while (list)
	{
		if (list->content)
			line = list->content;
		x = 0;
		while (line && line[x])
		{
			if (line[x] == '1')
				putwall(game->map, x, y);
			x++;
		}
		line = NULL;
		y++;
		list = list->next;
	}
	((t_object *)game->map)->y += game->height * MP_PIXEL_SIZE;
}

void	loadminimap(t_game *game)
{
	int	p[2];

	p[X] = SCREEN_WIDTH - MINIMAP_R * 2;
	p[Y] = SCREEN_HEIGHT - MINIMAP_R * 2;
	game->mini_map = create_object(game->mlx, p, MINIMAP_R * 2, MINIMAP_R * 2);
}
