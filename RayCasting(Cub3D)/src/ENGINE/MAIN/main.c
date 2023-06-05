/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msenipek <msenipek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 06:48:52 by aozsayar          #+#    #+#             */
/*   Updated: 2023/06/03 20:51:47 by msenipek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/f_engine.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	init_game(&game, argc, argv);
	init_elements(argv[1], game);
	init_mlx(game);
	setup(game);
	mlx_loop_hook(game->mlx, loop, game);
	mlx_loop(game->mlx);
}
