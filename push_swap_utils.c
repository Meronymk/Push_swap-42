/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krochefo <krochefo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:48:00 by krochefo          #+#    #+#             */
/*   Updated: 2022/07/27 06:41:38 by krochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_array_len(int *array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

int	ft_find_position(int *array, int nb)
{
	int	i;

	i = 0;
	while (array[i])
	{
		i++;
		if (nb == array[i])
			break ;
	}
	return (i);
}

int	ft_chunk_nb(int nb_arg)
{
	if (nb_arg > 250)
		return (25);
	else
		return (15);
}

int	ft_funnel_median(int *array_a, int nb_arg, int chunk)
{
	if (nb_arg > 250)
	{
		if (ft_checker(array_a, nb_arg, chunk) == 0)
			return (25);
	}
	else
	{
		if (ft_checker(array_a, nb_arg, chunk) == 0)
			return (15);
	}
	return (0);
}
