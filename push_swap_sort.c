/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krochefo <krochefo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 04:00:46 by krochefo          #+#    #+#             */
/*   Updated: 2022/08/05 13:39:18 by krochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3_array(int *array_a)
{
	if (array_a[0] > array_a[1] && array_a[1]
		< array_a[2] && array_a[2] < array_a[0])
		ft_rotate(array_a, 'a');
	if (array_a[0] > array_a[1] && array_a[1]
		< array_a[2] && array_a[2] > array_a[0])
		ft_swap(array_a, 'a');
	if (array_a[0] < array_a[1] && array_a[1]
		> array_a[2] && array_a[2] < array_a[0])
		ft_reverse_rotate(array_a, 'a');
	if (array_a[0] > array_a[1] && array_a[1]
		> array_a[2] && array_a[2] < array_a[0])
	{
		ft_swap(array_a, 'a');
		ft_reverse_rotate(array_a, 'a');
	}
	if (array_a[0] < array_a[1] && array_a[1]
		> array_a[2] && array_a[2] > array_a[0])
	{
		ft_swap(array_a, 'a');
		ft_rotate(array_a, 'a');
	}
}

void	ft_sort_5_array(int *array_a, int *array_b)
{
	while (array_a[0] != 5)
		ft_rotate(array_a, 'a');
	ft_push(array_a, array_b, 'b');
	while (array_a[0] != 1)
		ft_rotate(array_a, 'a');
	ft_push(array_a, array_b, 'b');
	ft_sort_3_array(array_a);
	ft_push(array_b, array_a, 'a');
	ft_push(array_b, array_a, 'a');
	ft_rotate(array_a, 'a');
}

void	ft_sort_100_array(int *array_a, int *array_b, int nb_arg)
{
	int	hold_first;
	int	j;

	hold_first = nb_arg;
	j = 0;
	ft_a_to_b(array_a, array_b, nb_arg, hold_first);
	while (array_b[0])
	{
		j = ft_b_to_a(array_a, array_b, hold_first);
		ft_push(array_b, array_a, 'a');
		if (j == 1)
		{
			ft_swap(array_a, 'a');
			hold_first--;
			j = 0;
		}
		hold_first--;
	}
}

void	ft_sort_array(int *array_a, int *array_b, int nb)
{
	if (nb == 3)
		ft_sort_3_array(array_a);
	if (nb == 5)
		ft_sort_5_array(array_a, array_b);
	if (nb > 5)
		ft_sort_100_array(array_a, array_b, nb);
}
