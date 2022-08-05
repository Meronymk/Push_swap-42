/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krochefo <krochefo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 05:22:23 by krochefo          #+#    #+#             */
/*   Updated: 2022/08/05 12:09:30 by krochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_atoli(const char *str)
{
	unsigned int	i;
	long int		ret;
	long int		sign;

	i = 0;
	sign = 1;
	ret = 0;
	while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
		ret = (str[i++] - '0') + (ret * 10);
	if (sign == 1)
		return (ret);
	return (ret * sign);
}

void	ft_error_isdigit(char **argv)
{
	int	ip;
	int	is;

	ip = 0;
	is = 0;
	while (argv[++ip])
	{
		is = -1;
		while (argv[ip][++is])
		{
			if (argv[ip][is] == '-')
				is++;
			if (!ft_isdigit(argv[ip][is]))
				ft_error();
		}
	}
}

void	ft_error_min_max(char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
		if (ft_atoli(argv[i]) > 2147483647 || ft_atoli(argv[i]) < -2147483648)
			ft_error();
}

void	ft_error_doubles(char **argv)
{
	int	ip;
	int	is;

	ip = 0;
	while (argv[++ip] && argv[ip + 1])
	{
		is = 0;
		while (argv[ip + ++is])
			if (ft_atoi(argv[ip]) == ft_atoi(argv[ip + is]))
				ft_error();
	}
}

void	ft_error_isordered(char **argv, int argc)
{
	int	i;
	int	k;

	i = 1;
	k = 2;
	while ((i + 1) != argc)
	{
		if ((ft_atoi(argv[i + 1])) > ft_atoi(argv[i]))
		{
			k++;
		}
		i++;
	}
	if (k == argc)
	{
		exit(0);
	}
}
