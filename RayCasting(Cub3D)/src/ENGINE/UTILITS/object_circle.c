/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_circle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozsayar <aozsayar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 06:49:49 by aozsayar          #+#    #+#             */
/*   Updated: 2023/06/03 07:26:33 by aozsayar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/f_engine.h"

void	create_circle(t_object *obj);
void	create_empty_circle(t_object *obj);

void	*new_circle(void *mlx, int *c_cords, int r, int is_empty)
{
	t_object	*obj;
	int			pos[2];

	pos[X] = c_cords[X] - r;
	pos[Y] = c_cords[Y] - r;
	obj = create_object(mlx, pos, 2 * r, 2 * r);
	obj->c_x = c_cords[X];
	obj->c_y = c_cords[Y];
	if (is_empty)
		create_empty_circle(obj);
	else
		create_circle(obj);
	return ((void *)obj);
}

void	create_circle(t_object *obj)
{
	int	x;
	int	y;
	int	dx;
	int	dy;
	int	r;

	r = obj->w / 2;
	y = -1;
	while (++y < obj->h)
	{
		dy = y - r;
		x = -1;
		while (++x < obj->w)
		{
			dx = x - r;
			if (dx * dx + dy * dy <= r * r)
				colorize_object(obj, BLUE, x, y);
		}
	}
}

void	create_empty_circle(t_object *obj)
{
	int	x;
	int	y;
	int	err;
	int	r;

	r = obj->w / 2;
	x = r;
	y = 0;
	err = 0;
	while (x >= y)
	{
		colorize_object(obj, (char)255, r + x, r + y);
		colorize_object(obj, (char)255, r + x, r - y);
		colorize_object(obj, (char)255, r - x, r + y);
		colorize_object(obj, (char)255, r - x, r - y);
		colorize_object(obj, (char)255, r + y, r + x);
		colorize_object(obj, (char)255, r + y, r - x);
		colorize_object(obj, (char)255, r - y, r + x);
		colorize_object(obj, (char)255, r - y, r - x);
		if (err <= 0 && ++y)
			err += 2 * y + 1;
		else if (err > 0 && --x)
			err -= 2 * x + 1;
	}
}
