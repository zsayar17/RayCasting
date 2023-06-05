/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozsayar <aozsayar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 06:49:38 by aozsayar          #+#    #+#             */
/*   Updated: 2023/06/03 06:49:39 by aozsayar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/f_engine.h"

void	rotate_point(int *rotete_point, int *center_point, float angle)
{
	float	rotate_matrix[2][2];
	int		new_point[2];
	int		x;
	int		y;

	x = rotete_point[X] - center_point[X];
	y = rotete_point[Y] - center_point[Y];
	rotate_matrix[0][0] = cos(angle);
	rotate_matrix[0][1] = -sin(angle);
	rotate_matrix[1][0] = -rotate_matrix[0][1];
	rotate_matrix[1][1] = rotate_matrix[0][0];
	new_point[X] = roundf(x * rotate_matrix[0][0] + y * rotate_matrix[0][1]);
	new_point[Y] = roundf(x * rotate_matrix[1][0] + y * rotate_matrix[1][1]);
	rotete_point[X] = center_point[X] + new_point[X];
	rotete_point[Y] = center_point[Y] + new_point[Y];
}

void	rotate_double_point(t_game *g, int *center_point, double angle)
{
	g->lc->d_x = g->lc->d_dst[X] - center_point[X];
	g->lc->d_y = g->lc->d_dst[Y] - center_point[Y];
	g->lc->rt_mtrx[0][0] = cos(angle);
	g->lc->rt_mtrx[0][1] = -sin(angle);
	g->lc->rt_mtrx[1][0] = -g->lc->rt_mtrx[0][1];
	g->lc->rt_mtrx[1][1] = g->lc->rt_mtrx[0][0];
	g->lc->_pnt[X] = g->lc->d_x * g->lc->rt_mtrx[0][0]
		+ g->lc->d_y * g->lc->rt_mtrx[0][1];
	g->lc->_pnt[Y] = g->lc->d_x * g->lc->rt_mtrx[1][0]
		+ g->lc->d_y * g->lc->rt_mtrx[1][1];
	g->lc->d_dst[X] = center_point[X] + g->lc->_pnt[X];
	g->lc->d_dst[Y] = center_point[Y] + g->lc->_pnt[Y];
}

double	mod(double num, double divisor)
{
	int	quotient;

	quotient = (num / divisor);
	return (num - (quotient * divisor));
}
