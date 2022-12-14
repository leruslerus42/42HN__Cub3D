/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paroonag <paroonag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 07:15:50 by paroonag          #+#    #+#             */
/*   Updated: 2022/07/30 11:52:12 by paroonag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	set_color(t_info *cub, char *rgb_color, int type)
{
	char	**rgb;
	int		hex;
	int		rgb_nbr;
	int		i;

	rgb = ft_split(rgb_color, ',');
	if (!rgb)
		ft_exit("fail to split RGB");
	i = -1;
	hex = 0;
	while (++i < 3)
	{
		if (!rgb[i] || !ft_isdigit_str(rgb[i]))
			ft_exit("invalid RGB format");
		rgb_nbr = ft_atoi(rgb[i]);
		if (rgb_nbr > 255 || rgb_nbr < 0)
			ft_exit("invalid RGB range");
		hex = hex * 256 + rgb_nbr;
	}
	set_color_utils(cub, type, hex);
	ft_free2d(rgb);
}

void	set_texture(t_info *cub, char *xpm_path, int type)
{
	int		fd;

	if (!xpm_path)
		ft_exit("empty xpm path");
	if (!ft_isformat(xpm_path, ".xpm"))
		ft_exit("invalid xpm path format");
	fd = open(xpm_path, O_RDONLY);
	if (fd == -1)
		ft_exit("Fail open .xpm");
	close(fd);
	if (cub->ele.xpm_path[type] != NULL)
		ft_exit("multiple xpm paths");
	cub->ele.xpm_path[type] = ft_strdup(xpm_path);
}

int	set_elements(t_info *cub, char **word)
{
	if (ft_strncmp(word[0], "NO\0", 3) == 0)
		set_texture(cub, word[1], NORTH);
	else if (ft_strncmp(word[0], "SO\0", 3) == 0)
		set_texture(cub, word[1], SOUTH);
	else if (ft_strncmp(word[0], "WE\0", 3) == 0)
		set_texture(cub, word[1], WEST);
	else if (ft_strncmp(word[0], "EA\0", 3) == 0)
		set_texture(cub, word[1], EAST);
	else if (ft_strncmp(word[0], "F\0", 2) == 0)
		set_color(cub, word[1], FLOOR);
	else if (ft_strncmp(word[0], "C\0", 2) == 0)
		set_color(cub, word[1], CEILING);
	else
		return (MAP);
	return (0);
}

void	read_elements(t_info *cub)
{
	char	*line;
	int		type;
	int		cnt_word;
	char	**word;

	cnt_word = 0;
	while (get_next_line(cub->fd, &line) > 0)
	{
		if (line[0] == '\0')
		{
			free(line);
			continue ;
		}
		cnt_word = ft_cntword(line, ' ');
		word = ft_split(line, ' ');
		if (!word)
			ft_exit("fail to split lines");
		type = valid_and_set_element_lines(cub, word, cnt_word);
		ft_free2d(word);
		if (type == MAP)
			break ;
		free(line);
	}
	cub->map_lines = ft_lstnew(ft_strdup(line));
	free(line);
}
