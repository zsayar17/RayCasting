/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msenipek <msenipek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 06:50:00 by aozsayar          #+#    #+#             */
/*   Updated: 2023/06/03 20:19:54 by msenipek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/f_engine.h"

void	line_greater_dx(t_game *g);
void	line_greater_dy(t_game *g);
void	analyisis_hit_side(t_game *g);

void	analyisis_hit_side(t_game *g)
{
	if (g->elements->map_array[g->lc->l_y / PIXEL_SIZE] \
		[(g->lc->l_x - g->lc->l.steps[X]) / PIXEL_SIZE] != '1')
	{
		if (g->lc->l.steps[X] > 0)
			g->lc->hit_side = g->assets->west_wall;
		else
			g->lc->hit_side = g->assets->eastwall;
		g->lc->l.hit_pos = g->lc->l_y;
	}
	else
	{
		if (g->lc->l.steps[Y] > 0)
			g->lc->hit_side = g->assets->north_wall;
		else
			g->lc->hit_side = g->assets->south_wall;
		g->lc->l.hit_pos = g->lc->l_x;
	}
}

void	line_greater_dx(t_game *g)
{
	g->lc->l_x = g->lc->l.begin[X];
	g->lc->l_y = g->lc->l.begin[Y];
	g->lc->l.p = (g->lc->l.delta[Y] << 1) - g->lc->l.delta[X];
	while (1)
	{
		if (g->lc->type == LIMITLESS && g->elements->map_array \
			[g->lc->l_y / PIXEL_SIZE][g->lc->l_x / PIXEL_SIZE] == '1')
			return ;
		g->lc->l_x += g->lc->l.steps[X];
		if (g->lc->l.p < 0)
			g->lc->l.p += (g->lc->l.delta[Y] << 1);
		else
		{
			g->lc->l_y += g->lc->l.steps[Y];
			g->lc->l.p += (g->lc->l.delta[Y] - g->lc->l.delta[X]) << 1;
		}
	}
}

void	line_greater_dy(t_game *g)
{
	g->lc->l_x = g->lc->l.begin[X];
	g->lc->l_y = g->lc->l.begin[Y];
	g->lc->l.p = (g->lc->l.delta[X] << 1) - g->lc->l.delta[Y];
	while (1)
	{
		if (g->lc->type == LIMITLESS && g->elements->map_array \
			[g->lc->l_y / PIXEL_SIZE][g->lc->l_x / PIXEL_SIZE] == '1')
			return ;
		g->lc->l_y += g->lc->l.steps[Y];
		if (g->lc->l.p < 0)
			g->lc->l.p += (g->lc->l.delta[X] << 1);
		else
		{
			g->lc->l_x += g->lc->l.steps[X];
			g->lc->l.p += (g->lc->l.delta[X] - g->lc->l.delta[Y]) << 1;
		}
	}
}

void	create_line(t_game *g, int *begin, int *end)
{
	g->lc->mx_len = find_max(SCREEN_WIDTH, SCREEN_HEIGHT);
	g->lc->l.begin[X] = begin[X];
	g->lc->l.begin[Y] = begin[Y];
	g->lc->l.end[X] = end[X] + (g->lc->type
			* (1 - ((end[X] - begin[X] < 0) << 1)) * g->lc->mx_len);
	g->lc->l.end[Y] = end[Y] + (g->lc->type
			* (1 - ((end[Y] - begin[Y] < 0) << 1)) * g->lc->mx_len);
	g->lc->l.delta[X] = abs(end[X] - begin[X]);
	g->lc->l.delta[Y] = abs(end[Y] - begin[Y]);
	g->lc->l.steps[X] = 1 - ((end[X] - begin[X] < 0) << 1);
	g->lc->l.steps[Y] = 1 - ((end[Y] - begin[Y] < 0) << 1);
	g->lc->l.p = 0;
	if (g->lc->l.delta[X] > g->lc->l.delta[Y])
		line_greater_dx(g);
	else
		line_greater_dy(g);
	if (g->lc->type == LIMITED)
		return ;
	analyisis_hit_side(g);
	g->lc->l.delta[X] = g->lc->l_x - g->lc->l.begin[X];
	g->lc->l.delta[Y] = g->lc->l_y - g->lc->l.begin[Y];
	g->lc->dist = sqrt(g->lc->l.delta[X] * g->lc->l.delta[X]
			+ g->lc->l.delta[Y] * g->lc->l.delta[Y]);
	g->lc->hit_x = (g->lc->l.hit_pos % g->lc->hit_side->w);
}
