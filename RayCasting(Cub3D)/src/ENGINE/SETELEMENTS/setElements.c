/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setElements.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozsayar <aozsayar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 06:49:17 by aozsayar          #+#    #+#             */
/*   Updated: 2023/06/03 06:49:17 by aozsayar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/f_engine.h"

void	replace_space(t_elements *element)
{
	t_list	*list;
	char	*line;

	list = element->map;
	while (list && list->content)
	{
		line = list->content;
		while (line && *line)
		{
			if (*line == ' ')
				*line = '1';
			line++;
		}
		list = list->next;
	}
}

void	fill_map_array(t_elements *elements)
{
	t_list	*map_list;

	map_list = elements->map;
	while (map_list)
	{
		array_add_str(&elements->map_array, map_list->content);
		map_list = map_list->next;
	}
}

void	create_elements(t_game *game)
{
	int	index;

	index = 0;
	game->elements = (t_elements *)malloc(sizeof(t_elements));
	game->elements->map = NULL;
	game->elements->map_array = NULL;
	game->elements->ea = NULL;
	game->elements->no = NULL;
	game->elements->so = NULL;
	game->elements->we = NULL;
	while (index < COLOR_COUNT)
	{
		game->elements->f_color[index] = -1;
		game->elements->s_color[index] = -1;
		index++;
	}
}

void	read_elements(int fd, t_game *game)
{
	char	buffer;
	char	*map_line;
	t_list	*list;

	list = NULL;
	map_line = NULL;
	while (read(fd, &buffer, 1))
	{
		if (buffer == '\n')
		{
			node_create(&list, map_line);
			map_line = NULL;
			continue ;
		}
		str_add_char(&map_line, buffer);
	}
	close(fd);
	set_elements(game, game->elements, list);
	replace_space(game->elements);
	fill_map_array(game->elements);
}

void	set_elements(t_game *game, t_elements *elements, t_list *arg)
{
	t_list	*list;
	char	*str;
	int		setted_elements;

	setted_elements = 0;
	list = arg;
	while (list)
	{
		str = (char *)list->content;
		str_pass_char(&str, ' ');
		if (!split_colors(elements, str) || !split_textures(elements, str))
			setted_elements++;
		else if (str && *str && setted_elements == ELEMENT_COUNT - 1)
		{
			split_map(&elements->map, list);
			break ;
		}
		else if (str && *str)
		{
			node_clear(&arg);
			raise_error(game, "NON ELEMENT");
		}
		list = list->next;
	}
	node_clear(&arg);
}
