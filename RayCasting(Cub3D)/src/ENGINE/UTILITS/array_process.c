/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msenipek <msenipek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 06:49:24 by aozsayar          #+#    #+#             */
/*   Updated: 2023/06/03 20:13:34 by msenipek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/f_engine.h"

size_t	array_get_len(char **array)
{
	int	count;

	count = 0;
	while (array && *(array++))
		count++;
	return (count);
}

void	array_add_str(char ***old_array, char *new_str)
{
	int		len;
	int		index;
	char	**new_array;
	char	**temp_array;

	if (!ft_strlen(new_str))
		return ;
	len = array_get_len(*old_array);
	index = 0;
	new_array = (char **)malloc(sizeof(char *) * (len + 2));
	temp_array = *old_array;
	while (temp_array && *temp_array)
		new_array[index++] = *(temp_array++);
	new_array[index++] = new_str;
	new_array[index] = NULL;
	if (*old_array)
		free(*old_array);
	*old_array = new_array;
}

char	**get_array(char *src, char delimeter)
{
	int		count;
	char	**array;

	count = 1;
	src--;
	while (*(++src))
	{
		if (*src == delimeter)
			count++;
		while (*src == delimeter)
			src++;
	}
	array = (char **)malloc(sizeof(char *) * (count + 1));
	array[count] = NULL;
	return (array);
}

char	**array_split(char *src, char delimeter)
{
	char	**array;
	char	**temp_array;
	char	*word;

	if (!src)
		return (NULL);
	array = get_array(src, delimeter);
	temp_array = array;
	word = NULL;
	while (*src)
	{
		if (*src != delimeter)
			str_add_char(&word, *(src++));
		if (*src == delimeter && word)
		{
			*(temp_array++) = word;
			word = NULL;
		}
		while (*src == delimeter)
			src++;
	}
	if (word)
		*(temp_array++) = word;
	return (array);
}

void	array_clear(char ***array)
{
	if (*array == NULL)
		return ;
	free (*array);
}
