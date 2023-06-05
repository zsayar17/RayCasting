/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_colorize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozsayar <aozsayar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 06:49:56 by aozsayar          #+#    #+#             */
/*   Updated: 2023/06/03 06:49:56 by aozsayar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/f_engine.h"

void	set_object_color(int *color_array, int color)
{
	color_array[R] = 0;
	color_array[G] = 0;
	color_array[B] = 0;
	if (color == RED)
		color_array[R] = 255;
	if (color == GREEN)
		color_array[G] = 255;
	if (color == BLUE)
		color_array[B] = 255;
	if (color == WHITE)
	{
		color_array[R] = 255;
		color_array[G] = 255;
		color_array[B] = 255;
	}
}

void	colorize_object(void *object, char color, int x, int y)
{
	int			index;
	t_object	*obj;
	int			colors[3];

	obj = (t_object *)object;
	index = (y * obj->obj_info[1]) + (x << 2);
	set_object_color(colors, color);
	obj->data[index] = colors[B];
	obj->data[index + 1] = colors[G];
	obj->data[index + 2] = colors[R];
	obj->data[index + 3] = 0;
}

int	getobjectcolor(void *object, int x, int y)
{
	int			index;
	t_object	*obj;

	obj = (t_object *)object;
	if (x < 0 || x >= obj->w || y < 0 || y >= obj->h)
		return (-1);
	index = (y * obj->obj_info[1]) + (x << 2);
	return (obj->data[index + 3]);
}

void	clear_object(void *object)
{
	int			x;
	int			y;
	int			index;
	t_object	*obj;

	obj = (t_object *)object;
	if (!obj)
		return ;
	y = -1;
	while (++y < obj->h)
	{
		x = -1;
		while (++x < obj->w)
		{
			index = (y * obj->obj_info[1]) + (x << 2);
			obj->data[index] = 0;
			obj->data[index + 1] = 0;
			obj->data[index + 2] = 0;
			obj->data[index + 3] = (char)255;
		}
	}
}
