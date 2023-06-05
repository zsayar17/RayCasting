/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_set_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozsayar <aozsayar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 06:50:16 by aozsayar          #+#    #+#             */
/*   Updated: 2023/06/03 06:50:16 by aozsayar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/f_engine.h"

void	str_join(char **oldarg, char *additionarg)
{
	int		len;
	int		index;
	char	*new_arg;
	char	*temp_arg;

	len = ft_strlen(*oldarg) + ft_strlen(additionarg);
	if (!len)
		return ;
	index = 0;
	new_arg = (char *)malloc(sizeof (char) * (len + 1));
	temp_arg = *oldarg;
	while (temp_arg && *temp_arg)
		new_arg[index++] = *(temp_arg++);
	while (additionarg && *additionarg)
		new_arg[index++] = *(additionarg++);
	new_arg[index] = 0;
	if (*oldarg)
		free(*oldarg);
	*oldarg = new_arg;
}

void	str_add_char(char **oldarg, char c)
{
	char	*new_arg;
	char	*temp_arg;
	int		index;
	int		len;

	len = ft_strlen(*oldarg) + 1;
	index = 0;
	new_arg = (char *)malloc(sizeof(char) * (len + 1));
	temp_arg = *oldarg;
	while (temp_arg && *temp_arg)
		new_arg[index++] = *(temp_arg++);
	new_arg[index++] = c;
	new_arg[index] = 0;
	if (*oldarg)
		free(*oldarg);
	*oldarg = new_arg;
}

char	*str_pass_char(char **arg, char c)
{
	while (*arg && **arg == c)
		(*arg)++;
	return (*arg);
}
