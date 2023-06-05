/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitelements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozsayar <aozsayar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 06:49:17 by aozsayar          #+#    #+#             */
/*   Updated: 2023/06/03 06:49:17 by aozsayar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/f_engine.h"

int	split_textures_vertival(t_elements *map, char *arg)
{
	if (!str_l_compare(arg, "SO", 2))
	{
		arg += 2;
		str_join(&map->so, str_pass_char(&arg, ' '));
	}
	else if (!str_l_compare(arg, "S", 1))
	{
		arg += 1;
		str_join(&map->so, str_pass_char(&arg, ' '));
	}
	else if (!str_l_compare(arg, "NO", 2))
	{
		arg += 2;
		str_join(&map->no, str_pass_char(&arg, ' '));
	}
	else if (!str_l_compare(arg, "N", 1))
	{
		arg += 1;
		str_join(&map->no, str_pass_char(&arg, ' '));
	}
	else
		return (1);
	return (0);
}

int	split_textures(t_elements *map, char *arg)
{
	if (!split_textures_vertival(map, arg))
		return (0);
	else if (!str_l_compare(arg, "EA", 2))
	{
		arg += 2;
		str_join(&map->ea, str_pass_char(&arg, ' '));
	}
	else if (!str_l_compare(arg, "E", 1))
	{
		arg += 1;
		str_join(&map->ea, str_pass_char(&arg, ' '));
	}
	else if (!str_l_compare(arg, "WE", 2))
	{
		arg += 2;
		str_join(&map->we, str_pass_char(&arg, ' '));
	}
	else if (!str_l_compare(arg, "W", 1))
	{
		arg += 1;
		str_join(&map->we, str_pass_char(&arg, ' '));
	}
	else
		return (1);
	return (0);
}

int	split_colors(t_elements *map, char *arg)
{
	char	*str;

	str = NULL;
	if (!str_l_compare(arg, "F", 1))
	{
		arg++;
		str_pass_char(&arg, ' ');
		str_join(&str, arg);
		convert_colors(map->f_color, str);
	}
	else if (!str_l_compare(arg, "C", 1))
	{
		arg++;
		str_pass_char(&arg, ' ');
		str_join(&str, arg);
		convert_colors(map->s_color, str);
	}
	else
		return (1);
	return (0);
}

void	convert_colors(int *color_arr, char *str)
{
	char	**colors;
	char	**temp_colors;
	int		index;

	colors = array_split(str, ',');
	free(str);
	if (!colors)
		return ;
	temp_colors = colors;
	index = 0;
	while (index < COLOR_COUNT && *colors)
	{
		color_arr[index++] = ft_atoi(*colors);
		free(*(colors++));
	}
	free(temp_colors);
}

void	split_map(t_list **map, t_list *list)
{
	t_list	*temp_map;
	t_list	*remove_node;
	char	*str;

	while (list)
	{
		str = NULL;
		if (list->content)
			str_join(&str, (char *)list->content);
		node_create(map, str);
		list = list->next;
	}
	temp_map = *map;
	while (temp_map->next)
		temp_map = temp_map->next;
	while (!temp_map->content)
	{
		remove_node = temp_map;
		temp_map = temp_map->prev;
		node_remove(map, remove_node);
	}
}
