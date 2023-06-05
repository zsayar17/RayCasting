/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clearCharacter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozsayar <aozsayar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 06:52:52 by aozsayar          #+#    #+#             */
/*   Updated: 2023/06/03 06:53:30 by aozsayar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	clear_char(t_game *game, t_char *character)
{
	delete_object(game->mlx, &character->obj);
	free(character);
}
