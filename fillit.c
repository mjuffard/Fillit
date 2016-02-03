/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 15:37:12 by mjuffard          #+#    #+#             */
/*   Updated: 2016/02/03 10:31:41 by mjuffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../Libft/libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_count_diese(char *tab)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while(tab[i] != '\0')
	{
		if(tab[i] == '#')
			j++;
		i++;
	}
	return(j);
}

int ft_count_point(char *tab)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while(tab[i] != '\0')
	{
		if(tab[i] == '.')
			j++;
		i++;
	}
	return(j);
}

int	ft_count_backslash_n(char *tab)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while(tab[i] != '\0')
	{
		if(tab[i] == '\n')
			j++;
		i++;
	}
	return(j);
}

int	ft_check_tetri1(char *tab)
{
	int		nb_diese;
	int		nb_point;
	int		nb_backslash_n;

	nb_diese = ft_count_diese(tab);
	nb_point = ft_count_point(tab);
	nb_backslash_n = ft_count_backslash_n(tab);
	if(nb_diese == 4 && nb_point == 12 && nb_backslash_n == 5)
		return(1);
	if(nb_diese == 4 && nb_point == 12 && nb_backslash_n == 4)
		return(2);
	else
		return(0);
}

int	ft_check_tetri2(char *tab)
{
	int	co;
	int	i;
	int	ver;

	i = 0;
	ver = ft_check_tetri1(tab);
	co = 0;
	while(tab[i] != '\0')
	{
		if (ver > 0)
		{
			if(tab[i] == '#')
			{
				if (i + 1 < 20 && tab[i + 1] == '#')
					co++;
				if (i + 5 < 20 && tab[i + 5] == '#')
					co++;
				if (i - 1 >= 0 && tab[i - 1] == '#')
					co++;
				if (i - 5 >= 0 && tab[i - 5] == '#')
					co++;
			}
		}
		i++;
	}
	if (co >= 6)
		return (1);
	else
		return (0);
}

int	ft_check_tetri3(char *tab)
{
	int	ver;

	ver = ft_check_tetri2(tab);
	if (ver == 1)
	{
		if (tab[4] == '\n' && tab[9] == '\n' && tab[14] == '\n' &&
			   	tab[19] == '\n')
			return (1);
		else
			return (0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char	*buff;
	int		fd;
	int		ret;
	int		x;
	int		y;
	int		z;

	if (!(buff = (char *)malloc(sizeof(char) * 22)))
		return (0);
	if (argc != 2 || (fd = open(argv[1], O_RDONLY)) < 0)
		return (0);
	while ((ret = read(fd, buff, 21)) > 0)
	{
		buff[ret] = '\0';
		x = ft_check_tetri1(buff);
		y = ft_check_tetri3(buff);
	}
	if (x == 2 && y == 1 && ret == 0)
		z = 1;
	else
		z = 0;
	printf("%d", z);
	return (z);
	close(fd);
	return (0);
}
