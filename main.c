/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krochefo <krochefo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:49:26 by krochefo          #+#    #+#             */
/*   Updated: 2022/08/05 12:00:16 by krochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (!(c >= '0' && c <= '9'))
		return (0);
	return (1);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	sign = 1;
	result = 0;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		++str;
	if (*str == '+' || *str == '-')
	{
		if (*(str++) == '-')
		sign *= -1;
	}
	while (ft_isdigit(*str))
	{
	result = result * 10;
	result += (*str++ - '0');
	}
	return (sign * result);
}

int	ft_index(int nb, char **argv, int argc)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argc >= 2)
	{
		if (nb > ft_atoi(argv[i]))
			j++;
		i++;
		argc--;
	}
	return (j + 1);
}

int	*ft_sort_index(char	**argv, int argc)
{
	int	*temp;
	int	i;
	int	j;

	i = 0;
	j = argc - 2;
	temp = malloc((argc - 1) * sizeof(int));
	while (j >= 0)
	{
		temp[i] = ft_index(ft_atoi(argv[i + 1]), argv, argc);
		i++;
		j--;
	}
	return (temp);
}

int	main(int argc, char **argv)
{
	int	*array_a;
	int	*array_b;
	int	i;
	int	j;

	i = 0;
	j = i + 1;
	if (argc <= 2)
		exit(0);
	ft_error_isdigit(argv);
	ft_error_min_max(argv);
	ft_error_doubles(argv);
	ft_error_isordered(argv, argc);
	array_b = malloc(argc * sizeof(int));
	array_a = ft_sort_index(argv, argc);
	ft_sort_array(array_a, array_b, (argc - 1));
	free(array_a);
	free(array_b);
}
