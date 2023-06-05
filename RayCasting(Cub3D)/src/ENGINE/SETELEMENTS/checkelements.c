/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkelements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msenipek <msenipek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 06:49:00 by aozsayar          #+#    #+#             */
/*   Updated: 2023/06/03 20:53:24 by msenipek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/f_engine.h"

void	check_colors(t_game *game, t_elements *elements)
{
	int	i;

	i = -1;
	while (++i < 3)
	{
		if (elements->f_color[i] > 255 || elements->f_color[i] < 0)
			raise_error(game, "INVALID RANGE NUMBER");
		if (elements->s_color[i] > 255 || elements->s_color[i] < 0)
			raise_error(game, "INVALID RANGE NUMBER");
	}
}

void	check_elements(t_game *game, t_elements *elements)
{
	t_list	*map;
	char	*l;
	int		i;
	int		c_cnt;

	if (!elements->map)
		raise_error(game, "INVALID ELEMENTS");
	map = elements->map;
	c_cnt = 0;
	while (map)
	{
		l = (char *)map->content;
		i = -1;
		while (l && l[++i])
		{
			if (check_valid_char(l[i]) || ((l[i] == '0' || l[i] == 'N')
					&& (check_topbottom(map, i) || check_left_right(map, i))))
				raise_error(game, "INVALID MAP");
			if (l[i] == 'N' || l[i] == 'S' || l[i] == 'W' || l[i] == 'E')
				c_cnt++;
		}
		map = map->next;
	}
	if (c_cnt != 1)
		raise_error(game, "INVALID MAP");
}

int	check_valid_char(char c)
{
	if (c == ' ' || c == '1' || c == '0' || c == 'N'
		|| c == 'S' || c == 'W' || c == 'E')
		return (0);
	return (1);
}

int	check_left_right(t_list *current_node, int index)
{
	char	*line;

	line = (char *)current_node->content;
	if (index == 0 || !line[index + 1])
		return (1);
	return (0);
}

int	check_topbottom(t_list *current_node, int index)
{
	char	*t_line;
	char	*b_line;
	int		t_len;
	int		b_len;
	int		i;

	if (!current_node->prev || !current_node->prev->content
		|| !current_node->next || !current_node->next->content)
		return (1);
	t_line = (char *)current_node->prev->content;
	b_line = (char *)current_node->next->content;
	t_len = ft_strlen(t_line);
	b_len = ft_strlen(b_line);
	if (index - 1 >= 0 && index + 1 < b_len && index + 1 < t_len)
	{
		i = 2;
		while (--i >= -1)
		{
			if (b_line[index + i] == ' ' || t_line[index + i] == ' ')
				return (1);
		}
	}
	else
		return (1);
	return (0);
}
