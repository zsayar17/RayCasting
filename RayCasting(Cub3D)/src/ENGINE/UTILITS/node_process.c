/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozsayar <aozsayar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 06:49:44 by aozsayar          #+#    #+#             */
/*   Updated: 2023/06/03 06:49:45 by aozsayar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/f_engine.h"

t_list	*node_create(t_list **list, void *content)
{
	t_list	*temp_list;
	t_list	*new_list;

	temp_list = *list;
	while (temp_list && temp_list->next)
		temp_list = temp_list->next;
	new_list = (t_list *)malloc(sizeof(t_list));
	new_list->content = content;
	new_list->next = NULL;
	new_list->prev = NULL;
	if (temp_list)
	{
		new_list->prev = temp_list;
		temp_list->next = new_list;
	}
	else
		*list = new_list;
	return (temp_list);
}

void	node_remove(t_list **list, t_list *target)
{
	t_list	*temp_list;

	temp_list = *list;
	while (temp_list)
	{
		if (temp_list == target)
		{
			if (*list != target)
				temp_list->prev->next = temp_list->next;
			else
				*list = (*list)->next;
			temp_list = temp_list->next;
			if (target->content)
				free(target->content);
			free(target);
			return ;
		}
		temp_list = temp_list->next;
	}
}

void	node_clear(t_list **list)
{
	t_list	*temp;

	while ((*list))
	{
		temp = (*list);
		(*list) = (*list)->next;
		if (temp->content)
			free(temp->content);
		free(temp);
	}
	*list = NULL;
}
