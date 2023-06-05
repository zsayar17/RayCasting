/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updateScreen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozsayar <aozsayar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 07:07:49 by aozsayar          #+#    #+#             */
/*   Updated: 2023/06/03 07:12:54 by aozsayar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	updatescreen(t_game *game)
{
	clear_object(game->screen);
	push_rays(game, game->additon);
}
