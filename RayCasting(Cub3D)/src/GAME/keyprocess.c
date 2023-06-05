/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyprocess.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozsayar <aozsayar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 07:13:40 by aozsayar          #+#    #+#             */
/*   Updated: 2023/06/03 07:13:44 by aozsayar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/f_engine.h"
#include "../../include/cub3d.h"

int	key_pressed(int keycode, t_game *game)
{
	int		key_press;

	key_press = 0;
	if (keycode == W)
		key_press |= KEY_W;
	if (keycode == A)
		key_press |= KEY_A;
	if (keycode == S)
		key_press |= KEY_S;
	if (keycode == D)
		key_press |= KEY_D;
	if (keycode == LEFT)
		key_press |= KEY_LEFT;
	if (keycode == RIGHT)
		key_press |= KEY_RIGHT;
	game->input_status |= key_press;
	return (EXIT_SUCCESS);
}

int	key_released(int keycode, t_game *game)
{
	int		key_relased;

	key_relased = 0;
	if (keycode == W)
		key_relased |= KEY_W;
	if (keycode == A)
		key_relased |= KEY_A;
	if (keycode == S)
		key_relased |= KEY_S;
	if (keycode == D)
		key_relased |= KEY_D;
	if (keycode == LEFT)
		key_relased |= KEY_LEFT;
	if (keycode == RIGHT)
		key_relased |= KEY_RIGHT;
	if (keycode == ESC)
		clear_game(game);
	game->input_status &= ~key_relased;
	return (EXIT_SUCCESS);
}
