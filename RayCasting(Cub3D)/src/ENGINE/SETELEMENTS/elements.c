/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msenipek <msenipek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 06:49:07 by aozsayar          #+#    #+#             */
/*   Updated: 2023/06/03 20:18:34 by msenipek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/f_engine.h"

void	init_elements(char *arg, t_game *game)
{
	int	fd;

	fd = open(arg, O_RDONLY);
	if (fd == -1)
		raise_error(game, "INVALID FILE");
	create_elements(game);
	read_elements(fd, game);
	check_elements(game, game->elements);
	check_colors(game, game->elements);
	fill_map_infos(game);
}

void	fill_map_infos(t_game *game)
{
	t_list	*list;
	int		width;
	int		current_width;
	int		height;

	list = game->elements->map;
	width = 0;
	height = 0;
	while (list)
	{
		current_width = ft_strlen((char *)list->content);
		if (current_width > width)
			width = current_width;
		height++;
		list = list->next;
	}
	game->width = width;
	game->height = height;
}
