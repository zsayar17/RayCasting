/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_get_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozsayar <aozsayar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 06:50:10 by aozsayar          #+#    #+#             */
/*   Updated: 2023/06/03 06:50:11 by aozsayar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/f_engine.h"

size_t	ft_strlen(char *arg)
{
	size_t	count;

	count = 0;
	while (arg && *(arg++))
		count++;
	return (count);
}

int	str_compare(char *arg1, char *arg2)
{
	if (!arg1 || !arg2)
		return (1);
	while (arg1 && arg2 && *arg1 && *arg2 && *arg1 == *arg2)
	{
		arg1++;
		arg2++;
	}
	if (!(*arg1) && !(*arg2))
		return (0);
	return (1);
}

int	str_l_compare(char *arg1, char *arg2, int len)
{
	int	count;

	if (!arg1 || !arg2)
		return (1);
	count = 0;
	while (arg1 && arg2 && *arg1 && *arg2 && *arg1 == *arg2 && count < len)
	{
		arg1++;
		arg2++;
		count++;
	}
	if (count == len)
		return (0);
	return (1);
}

int	ft_atoi(char *arg)
{
	int	sign;
	int	number;

	if (!arg)
		raise_error(NULL, "INVALID NUMBER");
	sign = 1;
	number = 0;
	if ((*arg == '-' || *arg == '+'))
		sign = 44 - *(arg++);
	while (*arg >= '0' && *arg <= '9')
		number = (number * 10) + (*(arg++) - '0');
	if (*arg)
		raise_error(NULL, "INVALID NUMBER");
	return (number * sign);
}
