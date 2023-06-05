/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozsayar <aozsayar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 06:50:06 by aozsayar          #+#    #+#             */
/*   Updated: 2023/06/03 07:30:01 by aozsayar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/f_engine.h"

void	*create_object(void *mlx, int *pos, int w, int h)
{
	t_object	*new_obj;

	new_obj = (t_object *)malloc(sizeof(t_object));
	new_obj->x = 0;
	new_obj->y = 0;
	if (pos)
	{
		new_obj->x = pos[X];
		new_obj->y = pos[Y];
	}
	new_obj->w = w;
	new_obj->h = h;
	new_obj->c_x = INT_MIN;
	new_obj->c_y = INT_MIN;
	new_obj->img = mlx_new_image(mlx, w, h);
	new_obj->data = mlx_get_data_addr(new_obj->img, &new_obj->obj_info[0],
			&new_obj->obj_info[1], &new_obj->obj_info[2]);
	clear_object(new_obj);
	return ((void *)new_obj);
}

void	*create_object_with_image(int x, int y, void *img)
{
	t_object	*new_obj;

	new_obj = (t_object *)malloc(sizeof(t_object));
	new_obj->x = x;
	new_obj->y = y;
	new_obj->c_x = INT_MIN;
	new_obj->c_y = INT_MIN;
	new_obj->img = img;
	new_obj->data = mlx_get_data_addr(new_obj->img, &new_obj->obj_info[0],
			&new_obj->obj_info[1], &new_obj->obj_info[2]);
	new_obj->w = new_obj->obj_info[1] / (new_obj->obj_info[0] / 8);
	new_obj->h = new_obj->obj_info[1] / (new_obj->obj_info[0] / 8);
	return ((void *)new_obj);
}

void	draw_object(t_game *game, t_object *obj)
{
	if (!obj)
		return ;
	mlx_put_image_to_window(game->mlx, game->window, obj->img, obj->x, obj->y);
}

void	delete_object(void *mlx, void **obj)
{
	t_object	*new_obj;

	new_obj = *obj;
	mlx_destroy_image(mlx, new_obj->img);
	free(new_obj);
	*obj = NULL;
}

void	copy_object(void *dest, void *src, int *pos, int color)
{
	int	x;
	int	y;
	int	r;
	int	dist;
	int	is_colorized;

	y = -1;
	r = ((t_object *)dest)->w / 2;
	while (++y < r << 1)
	{
		x = -1;
		while (++x < r << 1)
		{
			dist = ((r - x) * (r - x)) + ((r - y) * (r - y));
			is_colorized = getobjectcolor(src, pos[X] + x - r, pos[Y] + y - r);
			if (!is_colorized && dist < r * r)
				colorize_object(dest, color, x, y);
		}
	}
}
