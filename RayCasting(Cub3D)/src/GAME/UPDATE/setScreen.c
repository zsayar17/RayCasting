/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setScreen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozsayar <aozsayar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 07:10:39 by aozsayar          #+#    #+#             */
/*   Updated: 2023/06/03 07:10:39 by aozsayar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

int	setlinecolor(t_game *g)
{
	if (g->lc->s_indx1 >= g->lc->max_scr || g->lc->s_indx2 > g->lc->max_scr)
		return (1);
	g->lc->scr->data[g->lc->s_indx1] = g->elements->s_color[B];
	g->lc->scr->data[g->lc->s_indx1 + 1] = g->elements->s_color[G];
	g->lc->scr->data[g->lc->s_indx1 + 2] = g->elements->s_color[R];
	g->lc->scr->data[g->lc->s_indx1 + 3] = 0;
	g->lc->scr->data[g->lc->s_indx2] = g->elements->f_color[B];
	g->lc->scr->data[g->lc->s_indx2 + 1] = g->elements->f_color[G];
	g->lc->scr->data[g->lc->s_indx2 + 2] = g->elements->f_color[R];
	g->lc->scr->data[g->lc->s_indx2 + 3] = 0;
	return (0);
}

void	setrayline(t_game *g)
{
	g->lc->s_x = g->lc->l_cnt;
	g->lc->s_y = 0;
	g->lc->max_scr = (g->lc->scr->h * g->lc->scr->obj_info[1]) - 3;
	if (g->lc->l_len >= SCREEN_HEIGHT)
		return ;
	g->lc->s_indx1 = g->lc->s_x << 2;
	g->lc->s_indx2 = (g->lc->s_x << 2) + (g->lc->scr->obj_info[1]
			* ((SCREEN_HEIGHT >> 1) + (int)g->lc->dist));
	while (g->lc->s_y < (SCREEN_HEIGHT >> 1) - g->lc->dist)
	{
		g->lc->s_y++;
		if (setlinecolor(g))
			return ;
		g->lc->s_indx1 += g->lc->scr->obj_info[1];
		g->lc->s_indx2 += g->lc->scr->obj_info[1];
	}
}

void	setwalldata(t_game *g)
{
	g->lc->s_indx3 = (g->lc->s_x << 2) + (g->lc->scr->obj_info[1]
			* ((SCREEN_HEIGHT >> 1) - (int)g->lc->dist));
	g->lc->s_indx4 = g->lc->hit_x << 2;
	g->lc->l_len = g->lc->l_len << 1;
	g->lc->pxl_count = (double)g->lc->l_len
		/ ((double)((t_object *)g->lc->hit_side)->h);
	g->lc->indx = g->lc->pxl_count;
	g->lc->w_y = 0;
	if (g->lc->l_len > SCREEN_HEIGHT)
	{
		g->lc->w_y = ((double)((g->lc->l_len) - SCREEN_HEIGHT) / 2)
			/ g->lc->pxl_count;
		g->lc->s_indx4 += g->lc->hit_side->obj_info[1] * g->lc->w_y;
		g->lc->indx = g->lc->indx - mod(((double)((g->lc->l_len)
						- SCREEN_HEIGHT) / 2), g->lc->pxl_count);
		g->lc->l_len = SCREEN_HEIGHT;
	}
	g->lc->bgn_len = g->lc->l_len;
}

void	setwall(t_game *g)
{
	setwalldata(g);
	while (--g->lc->l_len)
	{
		g->lc->scr->data[g->lc->s_indx3]
			= g->lc->hit_side->data[g->lc->s_indx4];
		g->lc->scr->data[g->lc->s_indx3 + 1]
			= g->lc->hit_side->data[g->lc->s_indx4 + 1];
		g->lc->scr->data[g->lc->s_indx3 + 2]
			= g->lc->hit_side->data[g->lc->s_indx4 + 2];
		g->lc->scr->data[g->lc->s_indx3 + 3] = 0;
		g->lc->s_indx3 += g->lc->scr->obj_info[1];
		if (g->lc->w_y < g->lc->hit_side->h - 1
			&& g->lc->bgn_len - g->lc->l_len > g->lc->indx)
		{
			g->lc->w_dif = (g->lc->bgn_len - g->lc->l_len - g->lc->indx)
				/ g->lc->pxl_count;
			g->lc->w_y += g->lc->w_dif ;
			g->lc->indx += g->lc->pxl_count * g->lc->w_dif ;
			g->lc->s_indx4 += g->lc->hit_side->obj_info[1] * g->lc->w_dif ;
		}
		if (g->lc->s_indx3 >= g->lc->max_scr)
			return ;
	}
}
