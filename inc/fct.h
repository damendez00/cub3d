/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:22:04 by lbastien          #+#    #+#             */
/*   Updated: 2024/05/21 14:07:03 by damendez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FCT_H
#define FCT_H

t_data 	*init_data_struct(void);
void	ft_error(t_data *data, char *str, int status);
void	parse_scene(t_data *data);
t_tile	**parse_list_to_array(t_list *lst, t_data *data);
void	render_scene(t_data *data);
int		raycast_and_render(t_data *data);
void	process_input(t_data *data);
void	free_all(t_data *data);
void	free_2darray(char ***array);
void    print_data(t_data *data);
void	print_list(t_list *lst);
char	*tile_to_string(t_tile tile);
t_list	*list_new(char *str /*, t_data *data*/);
void	list_addback(t_list *new, t_list **lst, t_data *data);
void	free_list(t_list **lst);

/*		checker		*/
void	check_scene(int argc, char **argv, t_data *data);
void	check_if_tex(t_data *data, char *line);
void	check_if_color(t_data *data, char *line);
int		is_map_line(char *line);
void	is_texorcolor(t_data *data, char *line, int *i);
void	check_map(t_data *data);

/*		checker_map.c		*/
void	check_player_count(t_data *data);
void	check_closed(t_data *data);
void	check_playable(t_data *data);

/*		utils.c		*/
void	free_split(char **split);
int		ft_ptrlen(char **str);
int		ft_strlen_n(const char *str);
int		ft_ptrlen(char **str);

/*		map_utils.c		*/
int		is_map_line(char *line);
int		is_player(char c);
int		all_ones(char *str);
int		is_surrounded_space_or_wall(t_data *data, int y, int x);

#endif
