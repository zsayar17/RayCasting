/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadAssets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozsayar <aozsayar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 06:49:12 by aozsayar          #+#    #+#             */
/*   Updated: 2023/06/03 06:49:12 by aozsayar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/f_engine.h"

void	check_asset_error(t_game *game, void *img)
{
	if (!img)
		raise_error(game, "INVALID TEXTURE");
}

void	load_map_asset(t_game *game)
{
	t_assets	*assets;
	int			x;
	int			y;
	void		*img;

	assets = (t_assets *)malloc(sizeof(t_assets));
	game->assets = assets;
	assets->eastwall = NULL;
	assets->north_wall = NULL;
	assets->west_wall = NULL;
	assets->south_wall = NULL;
	img = mlx_xpm_file_to_image(game->mlx, game->elements->no, &x, &y);
	check_asset_error(game, img);
	assets->north_wall = create_object_with_image(0, 0, img);
	img = mlx_xpm_file_to_image(game->mlx, game->elements->so, &x, &y);
	check_asset_error(game, img);
	assets->south_wall = create_object_with_image(0, 0, img);
	img = mlx_xpm_file_to_image(game->mlx, game->elements->ea, &x, &y);
	check_asset_error(game, img);
	assets->eastwall = create_object_with_image(0, 0, img);
	img = mlx_xpm_file_to_image(game->mlx, game->elements->we, &x, &y);
	check_asset_error(game, img);
	assets->west_wall = create_object_with_image(0, 0, img);
}
