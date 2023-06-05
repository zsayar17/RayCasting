/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozsayar <aozsayar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 07:04:41 by aozsayar          #+#    #+#             */
/*   Updated: 2023/06/03 07:04:41 by aozsayar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

int	check_character_move(t_game *g)
{
	g->lc->x = g->lc->pos[X] / PIXEL_SIZE;
	g->lc->y = g->lc->pos[Y] / PIXEL_SIZE;
	if (g->elements->map_array[g->lc->y][g->lc->x] == '1')
		return (1);
	return (0);
}

void	update_angle(t_game *g, t_char *c)
{
	if (g->input_status & KEY_LEFT)
	{
		rotate_point(c->dir_pos, c->pos, -c->rotate_angle);
		c->angle = (c->angle - ROTATE_ANGLE) % 360;
	}
	if (g->input_status & KEY_RIGHT)
	{
		rotate_point(c->dir_pos, c->pos, c->rotate_angle);
		c->angle = (c->angle + ROTATE_ANGLE) % 360;
	}
}

void	calculatemovepos(t_game *g, t_char *c)
{
	g->lc->_sin = roundf(SPEED * sin(c->angle * RAD_CONVERTER));
	g->lc->_cos = roundf(SPEED * cos(c->angle * RAD_CONVERTER));
	if (g->input_status & KEY_W)
	{
		g->lc->pos[X] += g->lc->_sin;
		g->lc->pos[Y] -= g->lc->_cos;
	}
	if (g->input_status & KEY_S)
	{
		g->lc->pos[X] -= g->lc->_sin;
		g->lc->pos[Y] += g->lc->_cos;
	}
	if (g->input_status & KEY_A)
	{
		g->lc->pos[X] -= g->lc->_cos;
		g->lc->pos[Y] -= g->lc->_sin;
	}
	if (g->input_status & KEY_D)
	{
		g->lc->pos[X] += g->lc->_cos;
		g->lc->pos[Y] += g->lc->_sin;
	}
}

void	character_move(t_game *g)
{
	t_char	*c;

	if (!g->input_status)
		return ;
	c = g->additon;
	g->lc->pos[X] = c->pos[X];
	g->lc->pos[Y] = c->pos[Y];
	if (g->input_status && g->input_status != g->input_status >= KEY_LEFT)
	{
		calculatemovepos(g, c);
		if (!check_character_move(g))
		{
			c->dir_pos[Y] += g->lc->pos[Y] - c->pos[Y];
			c->dir_pos[X] += g->lc->pos[X] - c->pos[X];
			c->pos[X] = g->lc->pos[X];
			c->pos[Y] = g->lc->pos[Y];
		}
	}
	update_angle(g, c);
}
