/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_charcter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msenipek <msenipek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 06:53:46 by aozsayar          #+#    #+#             */
/*   Updated: 2023/06/03 20:40:58 by msenipek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	set_angle(t_char *ch, char c)
{
	if (c == 'N')
		ch->angle = 0;
	if (c == 'E')
	{
		ch->angle = -90;
		rotate_point(ch->dir_pos, ch->pos, -PI / 2);
	}
	if (c == 'W')
	{
		ch->angle = 90;
		rotate_point(ch->dir_pos, ch->pos, PI / 2);
	}
	if (c == 'S')
	{
		ch->angle = 180;
		rotate_point(ch->dir_pos, ch->pos, PI);
	}
}

char	set_char_pos(t_game *game, int *cord)
{
	char	**array;
	int		x;
	int		y;

	array = game->elements->map_array;
	y = -1;
	while (++y < game->height)
	{
		x = -1;
		while (++x < (int)ft_strlen(array[y]))
		{
			if (array[y][x] == 'N' || array[y][x] == 'S'
				|| array[y][x] == 'W' || array[y][x] == 'E')
			{
				cord[X] = x * PIXEL_SIZE + PIXEL_SIZE / 2;
				cord[Y] = y * PIXEL_SIZE + PIXEL_SIZE / 2;
				return (array[y][x]);
			}
		}
	}
	return (0);
}

void	load_character(t_game *game)
{
	int		cord[2];
	int		obj_cord[2];
	t_char	*character;
	char	c;

	character = (t_char *)malloc(sizeof(t_char));
	game->additon = character;
	c = set_char_pos(game, cord);
	character->pos[X] = cord[X] + 5;
	character->pos[Y] = cord[Y] + 5;
	character->dir_pos[X] = character->pos[X];
	character->dir_pos[Y] = character->pos[Y] + DIR_LEN;
	set_angle(character, c);
	obj_cord[X] = SCREEN_WIDTH - ((t_object *)game->mini_map)->w / 2;
	obj_cord[Y] = SCREEN_HEIGHT - ((t_object *)game->mini_map)->h / 2;
	character->obj = new_circle(game->mlx, obj_cord, MP_PIXEL_SIZE >> 1, 0);
	character->rotate_angle = RAD_CONVERTER * ROTATE_ANGLE;
}
