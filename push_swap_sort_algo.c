/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_algo.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krochefo <krochefo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:48:00 by krochefo          #+#    #+#             */
/*   Updated: 2022/07/27 06:43:14 by krochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_hold_number(int *array_a, int chunk, int nb_arg, int nb)
{
	int	i;
	int	hold;

	hold = 0;
	if (nb == 2)
		i = ft_array_len(array_a);
	else
		i = 0;
	while (array_a[i])
	{
		if (array_a[i] >= ((nb_arg / 2) - chunk)
			&& array_a[i] < ((nb_arg / 2) + chunk))
		{
			hold = array_a[i];
			break ;
		}
		if (nb == 2)
			i--;
		else
			i++;
	}
	return (hold);
}

void	ft_a_to_b(int *array_a, int *array_b, int nb_arg, int hold_first)
{
	int	hold_second;
	int	chunk;

	chunk = ft_chunk_nb(nb_arg);
	while (array_a[0])
	{
		hold_first = ft_hold_number(array_a, chunk, nb_arg, 1);
		hold_second = ft_hold_number(array_a, chunk, nb_arg, 2);
		if ((ft_array_len(array_a) - ft_find_position(array_a, hold_second))
			< ft_find_position(array_a, hold_first))
		{
			while (array_a[0] != hold_first)
				ft_rotate(array_a, 'a');
		}
		else
			while (array_a[0] != hold_second)
				ft_reverse_rotate(array_a, 'a');
		if (array_a[0] < (nb_arg / 2) && array_b[0])
			ft_push_rotate(array_a, array_b);
		else
			ft_push(array_a, array_b, 'b');
		chunk += ft_funnel_median(array_a, nb_arg, chunk);
	}
}

void	ft_push_rotate(int *array_a, int *array_b)
{
	ft_push(array_a, array_b, 'b');
	ft_rotate(array_b, 'b');
}

int	ft_checker(int *array_a, int nb_arg, int chunk)
{
	int	i;

	i = 0;
	while (array_a[i])
	{
		if (array_a[i] >= ((nb_arg / 2) - chunk)
			&& array_a[i] < ((nb_arg / 2) + chunk))
			return (1);
		i++;
	}
	return (0);
}

int	ft_b_to_a(int *array_a, int *array_b, int hold_first)
{
	int	j;

	j = 0;
	while (array_b[0] != hold_first)
	{
		if (array_b[0] == (hold_first - 1))
		{
			ft_push(array_b, array_a, 'a');
			j = 1;
		}
		if (ft_find_position(array_b, hold_first) < (ft_array_len(array_b) / 2))
			ft_rotate(array_b, 'b');
		else
		{
			ft_reverse_rotate(array_b, 'b');
		}
	}
	return (j);
}
