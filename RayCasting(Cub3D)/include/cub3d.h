#ifndef CUB3D_H
# define CUB3D_H

# include	"f_engine.h"
# define SPEED 8
# define DIR_LEN 	-10000
# define ROTATE_ANGLE 3
# define RAY_FREQUENCY 0.00109083078 // 0.06125 derece
# define MINIMAP_R 100
# define FOV 66

typedef struct s_char
{
	int		pos[2];
	int		size;
	int		angle;
	void	*obj;
	int		dir_pos[2];
	float	rotate_angle;
}t_char;

typedef struct s_minimap
{
	void	*obj;
	int		r;
	int		pos[2];

}t_minimap;

void	loadmap(t_game *game);
void	load_character(t_game *game);

void	character_move(t_game *game);
int		check_character_move(t_game *game);

void	push_rays(t_game *game, t_char *character);
void	visualization(t_game *game, double angle);

void	updateminimap(t_game *game);
void	loadminimap(t_game *game);

void	updatescreen(t_game *game);
void	loadscreen(t_game *game);
void	update_angle(t_game *g, t_char *c);
void	setwall(t_game *g);
void	setrayline(t_game *g);
void	clear_char(t_game *game, t_char *character);

#endif
