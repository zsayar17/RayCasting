/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadScreen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozsayar <aozsayar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 06:59:09 by aozsayar          #+#    #+#             */
/*   Updated: 2023/06/03 07:26:53 by aozsayar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	loadscreen(t_game *game)
{
	game->screen = create_object(game->mlx, NULL, SCREEN_WIDTH, SCREEN_HEIGHT);
	game->lc->scr = game->screen;
}
