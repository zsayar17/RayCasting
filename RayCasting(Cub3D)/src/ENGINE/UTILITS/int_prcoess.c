/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_prcoess.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozsayar <aozsayar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 06:49:32 by aozsayar          #+#    #+#             */
/*   Updated: 2023/06/03 06:49:33 by aozsayar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/f_engine.h"

int	find_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	find_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

void	replace_array(int *arr_1, int *arr_2)
{
	arr_1[Y] = arr_1[Y] ^ arr_2[Y];
	arr_2[Y] = arr_1[Y] ^ arr_2[Y];
	arr_1[Y] = arr_1[Y] ^ arr_2[Y];
	arr_1[X] = arr_1[X] ^ arr_2[X];
	arr_2[X] = arr_1[X] ^ arr_2[X];
	arr_1[X] = arr_1[X] ^ arr_2[X];
}
