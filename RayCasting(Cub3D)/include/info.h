
#ifndef INFO_H
# define INFO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# ifdef __linux__
	# include "../mlx_linux/mlx.h"
# elif defined(__APPLE__)
	# include "../mlx_mac/mlx.h"
#endif

# ifdef __linux__
	# define A 97
	# define S 115
	# define D 100
	# define W 119
	# define ESC 65307
	# define LEFT 65361
	# define RIGHT 65363
	# define MOUSE_MOVE_MASK 64
# elif defined(__APPLE__)
	# define A 0
	# define S 1
	# define D 2
	# define W 13
	# define ESC 53
	# define LEFT 123
	# define RIGHT 124
	# define MOUSE_MOVE_MASK 13
#endif

# define COLOR_COUNT 3
# define ELEMENT_COUNT 7
# define PIXEL_SIZE 64
# define MP_PIXEL_SIZE 16
# define SCREEN_WIDTH 1056
# define SCREEN_HEIGHT 720

# define INT_MIN -2147483648
# define INT_MAX 2147483647

# define PI 3.141592653589793
# define CEL_CONVERTER 57.2957795131
# define RAD_CONVERTER 0.01745329251

# define KEY_A 1
# define KEY_S 2
# define KEY_D 4
# define KEY_W 8
# define KEY_LEFT 16
# define KEY_RIGHT 32

enum
{
	GAME_CONTUNIUE,
	GAME_PAUSE,
	GAME_CLOSE
};

enum
{
	R,
	G,
	B
};

enum
{
	X,
	Y
};

enum
{
	LIMITED,
	LIMITLESS
};

enum
{
	RED,
	GREEN,
	BLUE,
	BLACK,
	WHITE
};

typedef struct s_game
{
	void				*mlx;
	void				*window;
	int					width;
	int					height;
	int					game_status;
	short int			input_status;
	void				*additon;
	void				*map;
	void				*mini_map;
	void				*screen;
	struct s_elements	*elements;
	struct s_assets		*assets;
	struct s_local		*lc;
}	t_game;

typedef struct s_elements
{
	struct s_list	*map;
	char			**map_array;
	char			*no;
	char			*ea;
	char			*we;
	char			*so;
	int				s_color[COLOR_COUNT];
	int				f_color[COLOR_COUNT];
}	t_elements;

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
	struct s_list	*prev;

}	t_list;

typedef struct s_line
{
	int				begin[2];
	int				end[2];
	int				delta[2];
	int				steps[2];
	int				p;
	int				hit_pos;
	int				distance;
}	t_line;

typedef struct s_object
{
	void	*img;
	char	*data;
	int		x;
	int		y;
	int		w;
	int		h;
	int		c_x;
	int		c_y;
	int		obj_info[3];
}	t_object;

typedef struct s_assets
{
	void	*north_wall;
	void	*south_wall;
	void	*west_wall;
	void	*eastwall;
}	t_assets;

typedef struct s_local
{
	int			pos[2];

	int			_sin;
	int			_cos;

	int			x;
	int			y;

	double		d_dst[2];
	int			dst[2];
	int			dgr;
	double		dist;
	double		angle;
	int			l_cnt;

	double		rt_mtrx[2][2];
	double		d_x;
	double		d_y;
	double		_pnt[2];
	int			type;

	t_line		l;
	int			mx_len;

	int			l_x;
	int			l_y;

	t_object	*hit_side;
	int			hit_x;

	int			count;
	t_object	*scr;
	int			s_x;
	int			s_y;
	int			i;
	int			s_indx1;
	int			s_indx2;
	int			max_scr;

	int			bgn_len;
	int			s_indx3;
	int			s_indx4;
	int			l_len;
	double		pxl_count;
	double		indx;
	int			w_y;
	int			w_dif;
}	t_local;

#endif
