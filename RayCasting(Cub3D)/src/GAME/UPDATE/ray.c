/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msenipek <msenipek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 07:06:12 by aozsayar          #+#    #+#             */
/*   Updated: 2023/06/03 20:25:20 by msenipek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	push_rays(t_game *g, t_char *c)
{
	g->lc->dst[X] = c->dir_pos[X];
	g->lc->dst[Y] = c->dir_pos[Y];
	g->lc->d_dst[X] = c->dir_pos[X];
	g->lc->d_dst[Y] = c->dir_pos[Y];
	g->lc->dgr = SCREEN_WIDTH;
	g->lc->angle = RAY_FREQUENCY * -(g->lc->dgr / 2);
	g->lc->l_cnt = 0;
	g->lc->type = LIMITLESS;
	rotate_double_point(g, c->pos, RAY_FREQUENCY * -(g->lc->dgr / 2));
	while (g->lc->dgr-- >= 0)
	{
		create_line(g, c->pos, g->lc->dst);
		visualization(g, g->lc->angle);
		rotate_double_point(g, c->pos, RAY_FREQUENCY);
		g->lc->dst[X] = g->lc->d_dst[X];
		g->lc->dst[Y] = g->lc->d_dst[Y];
		g->lc->angle += RAY_FREQUENCY;
		g->lc->l_cnt++;
	}
}

void	visualization(t_game *g, double angle)
{
	if (angle < 0)
		angle *= -1;
	g->lc->dist = (cos(angle) * g->lc->dist);
	g->lc->dist = (g->lc->dist * (SCREEN_HEIGHT / (double)SCREEN_WIDTH));
	g->lc->dist = ((SCREEN_HEIGHT / 2.0f) / g->lc->dist * PIXEL_SIZE);
	g->lc->l_len = g->lc->dist;
	if (g->lc->dist >= SCREEN_HEIGHT / 2)
		g->lc->dist = SCREEN_HEIGHT / 2 - 1;
	setrayline(g);
	setwall(g);
}
