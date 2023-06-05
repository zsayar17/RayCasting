/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozsayar <aozsayar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 06:48:36 by aozsayar          #+#    #+#             */
/*   Updated: 2023/06/03 07:34:37 by aozsayar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/f_engine.h"

void	init_game(t_game **game, int argc, char **argv)
{
	int	arg_len;

	(*game) = NULL;
	if (argc != 2)
		raise_error(*game, "INVALID ARGUMENT");
	arg_len = ft_strlen(argv[1]);
	if (arg_len < 4 || str_compare(&argv[1][arg_len - 4], ".cub"))
		raise_error(*game, "INVALID MAP EXTANSION");
	(*game) = (t_game *)malloc(sizeof(t_game));
	(*game)->lc = (t_local *)malloc(sizeof(t_local));
	(*game)->height = 0;
	(*game)->width = 0;
	(*game)->width = GAME_CONTUNIUE;
	(*game)->elements = NULL;
	(*game)->mlx = NULL;
	(*game)->window = NULL;
	(*game)->assets = NULL;
	(*game)->input_status = 0;
	(*game)->additon = NULL;
	(*game)->map = NULL;
	(*game)->screen = NULL;
	(*game)->mini_map = NULL;
}

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, SCREEN_WIDTH,
			SCREEN_HEIGHT, "Wolfenstein3D");
	mlx_hook(game->window, 2, 1, key_pressed, game);
	mlx_hook(game->window, 3, 2, key_released, game);
	mlx_hook(game->window, 6, MOUSE_MOVE_MASK, mouse_moved, game);
	mlx_hook(game->window, 17, 0, clear_game, game);
}

int	loop(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (game->game_status == GAME_CLOSE)
		return (EXIT_SUCCESS);
	update(game);
	if (game->game_status == GAME_CLOSE)
		return (EXIT_SUCCESS);
	mlx_clear_window(game->mlx, game->window);
	draw(game);
	return (EXIT_SUCCESS);
}
