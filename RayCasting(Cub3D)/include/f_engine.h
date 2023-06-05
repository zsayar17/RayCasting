
/* #pragma once */
#ifndef F_ENGINE_H
# define F_ENGINE_H

# include "info.h"

/*INITS*/
void	init_game(t_game **game, int argc, char **argv);
void	init_mlx(t_game *game);
int		loop(void *param);

/*CLEAR*/

int		clear_game(t_game *param);
void	clear_elements(t_elements *elements);
void	clear_assets(t_game *game);
void	raise_error(t_game *game, char *error_msg);

/*GAME LOOP*/
void	setup(t_game *game);
void	update(t_game *game);
void	draw(t_game *game);

/*INPUTS BY USER*/
int		key_pressed(int keycode, t_game *game);
int		key_released(int keycode, t_game *game);

int		mouse_moved(int x, int y, t_game *param);

/*ELEMENTS*/
void	init_elements(char *arg, t_game *game);
void	create_elements(t_game *game);
void	read_elements(int fd, t_game *game);
void	set_elements(t_game *game, t_elements *elements, t_list *arg);

int		split_textures(t_elements *map, char *arg);
int		split_colors(t_elements *map, char *arg);
void	convert_colors(int *color_arr, char *str);
void	split_map(t_list **map, t_list *list);
void	fill_map_infos(t_game *game);

void	check_elements(t_game *game, t_elements *elements);
int		check_valid_char(char c);
int		check_left_right(t_list *current_node, int index);
int		check_topbottom(t_list *current_node, int index);
void	check_colors(t_game *game, t_elements *elements);

void	load_map_asset(t_game *game);

/*UTILITS*/
size_t	array_get_len(char **array);
void	array_add_str(char ***old_array, char *new_str);
char	**get_array(char *src, char delimeter);
char	**array_split(char *src, char delimeter);
void	array_clear(char ***array);

t_list	*node_create(t_list **list, void *content);
void	node_remove(t_list **list, t_list *target);
void	node_clear(t_list **list);

size_t	ft_strlen(char *arg);
int		str_compare(char *arg1, char *arg2);
int		str_l_compare(char *arg1, char *arg2, int len);
int		ft_atoi(char *arg);

void	str_join(char **oldarg, char *additionarg);
void	str_add_char(char **oldarg, char c);
char	*str_pass_char(char **arg, char c);

int		find_max(int a, int b);
int		find_min(int a, int b);
void	replace_array(int *arr_1, int *arr_2);

/*MATH PROCESS*/

void	rotate_point(int *rotete_point, int *center_point, float angle);
void	rotate_double_point(t_game *g, int *cnt_pnt, double angle);

/*DRAW_OBJS*/
void	*create_object(void *mlx, int *pos, int w, int h);
void	*create_object_with_image(int x, int y, void *img);
void	delete_object(void *mlx, void **obj);
void	draw_object(t_game *game, t_object *obj);
void	copy_object(void *dest, void *src, int *pos, int color);

void	colorize_object(void *object, char color, int x, int y);
void	clear_object(void *object);
int		getobjectcolor(void *object, int x, int y);

void	create_line(t_game *g, int *begin, int *end);

void	*new_circle(void *mlx, int *c_cords, int r, int is_empty);
double	mod(double num, double divisor);

#endif
